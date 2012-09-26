#include<TcpConn.h>
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
  struct sockaddr_in seraddr;
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
    if(bind(sersocket,(struct sockaddr)&seraddr,sizeof(servaddr))!=0)
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
  int cliconn = INVALID_SOCKET;
  cliconn=accept(sersocket,(sockaddr*)&cliaddr,(socklen_t*)&cliaddrlen);
  if (cliconn==-1)
  {
    printf("Connect to the server failed!\n");
    close(cliconn);
    close(sersocket);
    return -1
  }
  printf("Connect successfully!\n");
    return  1;
  

}


