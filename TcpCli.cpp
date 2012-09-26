#include"TcpCli.h"
Class TcpCli{
  public:
   TcpCli();
   ~TcpCli();
  bool AttempConn();
  private:
  int clisocket;
};
/*构造函数*/
TcpCli::TcpCli()
{
 // clisocket=(AF_INET,SOCK_STREAM,0);
  clisocket=-1; 
}
TcpCli::~TcpCli()
{
  if (clisocket != -1)
      close(clisocket); 
}
bool 