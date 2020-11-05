/*
    TCP实验一
    客户端
*/



#include<Winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#pragma comment(lib,"WS2_32.lib")
//服务器端口为5050
#define DEFAULT_PORT 5050
#define DATA_BUFFER 1024
int main(int argc,char *argv[])
{
	WSADATA wsaData;
	SOCKET sClient;
	int iPort=DEFAULT_PORT;
	//从服务器端接收的数据长度
	int iLen;
	//接收数据的缓冲
	char buf[DATA_BUFFER];
	//服务器端地址
	struct sockaddr_in ser;
	//判断输入的参数是否正确
	if(argc<2)
	{
		//提示在命令行中输入服务器IP地址
		printf("Usage:client [server IP address]\n");
		return 0;
	}
	//接收数据的缓冲区初始化
	memset(buf,0,sizeof(buf));
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
	{
		printf("Failed to load Winsock.\n");
		return 0;
	}
	//填写要连接的服务器地址信息
	ser.sin_family=AF_INET;
	ser.sin_port=htons(iPort);
	//inet_addr()函数将命令行的点分IP地址转化为用二进制表示的网络字节顺序的IP地址
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	//r.sin_addr.s_addr=inet_addr("172.18.168.21");
	//建立客户端流式套接口
	sClient=socket(AF_INET,SOCK_STREAM,0);
	if(sClient==INVALID_SOCKET)
	{
		printf("socket() Failed:%d\n",WSAGetLastError());
		return 0;
	}
	//请求与服务器建立TCP连接
	if(connect(sClient,(struct sockaddr*)&ser,sizeof(ser))==INVALID_SOCKET)
	{
		printf("connect() Failed:%d\n",WSAGetLastError());
		return 0;
	}
	else
		{
		//从服务器端接收数据
		iLen=recv(sClient,buf,sizeof(buf),0);
		if(iLen==0)
			return 0;
		else if(iLen==SOCKET_ERROR)
		{
			printf("recv() Failed:%d\n",WSAGetLastError());
			return 0;
		}
		printf("recv() data from server:%s\n",buf);
	}
	closesocket(sClient);
	WSACleanup;

	return 0;
}