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
class TcpConn
{
  public:
      TcpConn();
      ~TcpConn();
      bool initConn();
      bool AcceptConn();
  private:
      int Conn;
      
       
};

