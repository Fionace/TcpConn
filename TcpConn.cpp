#include<TcpConn.h>
/*构造函数*/
TcpConn::TcpConn()
{
  sersockfd=-1;
  Conn=0;
}
/*析构函数，要关闭还未关闭的套接字*/
TcpConn::~TcpConn()
{
  if (sersockfd != -1)
      close(sersockfd);
}
/*初始化服务器监听端口，包括套接字建立，绑定端口，到开始监听的过程*/
/*有ip和port的情况*/
bool TcpConn::initConn(const char *ip,int port)
{
  struct sockaddr_in seraddr;
  struct in_addr=s;
  seraddr.sin_family=AF_INET;
  seraddr.sin_port=htons(port);
  inet_aton(ip,&a)
  seraddr.sin_addr=a;
   if((sersocket=socket(AF_INET,SOCK_STREAM,0))<0)
       {
         printf("Could not create the server socket!\n");
          return -1;
       }
    if(bind(sersocket,(struct sockaddr)&seraddr,sizeof(serv))!=0)
    {
      printf("Could not !\n");
          return -1;
    }
}
/*仅有port的情况*/
bool TcpConn::initConn(int port)
{
  
}


