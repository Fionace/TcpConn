#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define INVALID_SOCKET -1

using namespace std;

Class TcpCli{
  public:
   TcpCli();
   ~TcpCli();
   bool CliSock();
  bool AttempConn(const char *ip ,int port);
  private:
  int clisocket;
};

