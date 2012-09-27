#include"TcpConn.h"
/*构造函数*/
TcpConn::TcpConn()
{
  sersocket=-1;
 // Conn=0;
}
/*析构函数，要关闭还未关闭的套接字*/
TcpConn::~TcpConn()
{
  if (sersocket != -1)
      close(sersocket);
}
/*初始化服务器监听端口，包括套接字建立，绑定端口，到开始监听的过程*/
/*bind仅有port的情况*/
bool TcpConn::initConn(int port)
{
 // struct sockaddr_in seraddr;
  //struct in_addr=s;
  seraddr.sin_family=AF_INET;
  seraddr.sin_port=htons(port);
  //inet_aton(ip,&a)
  seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
   if((sersocket=socket(AF_INET,SOCK_STREAM,0))<0)
       {
         printf("Could not create the server socket!\n");
          close(sersocket);
          return -1;
       }
    if(bind(sersocket,(sockaddr*)&seraddr,sizeof(seraddr))!=0)
    {
      printf("Could not bind successfully !\n");
      close(sersocket);
          return -1;
    }
    if(listen(sersocket,SOMAXCONN)!=0)
    {
      printf("Could not listen successfully !\n");
      close(sersocket);
          return -1;
    }
    printf("Server begin to listen ...\n");
    return  1;
}
bool TcpConn::AcceptConn()
{
  struct sockaddr_in cliaddr;
  //struct sockaddr cliaddr;
  int cliaddrLen = sizeof(cliaddr);
  //int serLen=sizeof(ser);
 // socklen_t serLen;
 // serLen=sizeof(ser);
  int cliconn = INVALID_SOCKET;
  cliconn=accept(sersocket,(sockaddr*)&cliaddr,(socklen_t*)&cliaddrLen);
  if (cliconn==-1)
  {
    printf("Connect to the server failed!\n");
    close(cliconn);
    close(sersocket);
    return -1;
  }
  printf("Connect successfully!\n");
  bzero(&seraddr,sizeof(seraddr));
  socklen_t len;
  len =sizeof(seraddr);
 // int n;
   int err;
   err=getsockname(cliconn,(sockaddr*)&seraddr,&len );
if(err==-1);
 {
   
  // printf( "getsockname   error   %d\n ",   WSAGetLastError());
    printf("the server info achieved failed!\n"); 
    printf("errno=%d\n",err);
   char * mesg = strerror(err);
    printf("Mesg:%s\n",mesg);
    close(cliconn);
    close(sersocket);
    return -1;
  }
   char  serip[INET_ADDRSTRLEN];
  inet_ntop(AF_INET,(sockaddr*)&seraddr,serip,sizeof(serip));
 printf("The server info is %s\n",serip);
    return  1;
  

}


