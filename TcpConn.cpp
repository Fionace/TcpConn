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


