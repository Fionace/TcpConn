#include"TcpCli.h"

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
bool TcpCli::CliSock()
{
  clisocket=socket(AF_INET,SOCK_STREAM,0);
  if(clisocket==-1)
  {
    printf("Could not create the client socket!\n");
    close(clisocket);
    return -1;
  }
   printf("Create the client socket!\n");
    return  1;
}

bool TcpCli::AttempConn(const char *ip ,int port)
{
  struct sockaddr_in seraddr;
  bzero(&seraddr,sizeof(seraddr));
  seraddr.sin_family=AF_INET;
  seraddr.sin_port=htons(port);
  inet_pton(AF_INET,ip,&seraddr.sin_addr);
  if(connect(clisocket,(sockaddr*)&seraddr,sizeof(seraddr))==-1)
  {
    printf("Could not connect the server!\n");
    close(clisocket);
    return -1;
  }
  printf("Client want to connect the server!\n");
    return  1;
  
  
}