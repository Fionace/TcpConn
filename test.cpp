#include "stdio.h"
#include "iostream"
#include"TcpConn.h"
#include"TcpCli.h"
using namespace std;
int main(int argc,char **argv)
{
  TcpConn *Serv=new TcpConn;
  TcpCli *Cli=new TcpCli;
  int port=10890;
  const char *ip=localhost;
  printf("建立服务器监听\n");
  Serv->initConn(port);
  printf("等待连接\n");
  sleep(9000);
  printf("客户套接字建立\n");
  Cli->CliSock();
  printf("客户发起连接\n");
  Cli->AttempConn(ip,port);
  printf("服务器接受\n");
  Ser->AcceptConn();
  delete Serv;
  delete Cli;
  printf("成功建立\n");
  exit(0);
  
}