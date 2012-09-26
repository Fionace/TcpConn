#include "sys/socket.h"
#include "errno.h"
#include "netdb.h"
#include "string.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "iostream"
#include <unistd.h>
#include <fcntl.h>
#include "fstream"
using namespace std;
//#include ""
#define INVALID_SOCKET -1
class TcpConn
{
  public:
      TcpConn();
      ~TcpConn();
   struct sockaddr_in seraddr;
      bool initConn(int port);
      bool AcceptConn();
      
  private:
     // int Conn;
      int sersocket;
      
       
};
