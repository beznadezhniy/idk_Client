/* Всё что закомменченно - изучение основ сетевого программирования путем проб и ошибок ^_^*/
#pragma comment (lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;
/*
SOCKET Socket;
WSADATA Winsock;
sockaddr_in Addr;
int Addrlen = sizeof(Addr);
*/

int main(int argc, char* argv[])
{
	//WASStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		cout << "Error " << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET Conn = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(Conn, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Error: failed connection to server.\n";
		return 1;
	}
	
	cout << "Connected!\n"; 
	char msg[256];
	recv(Conn, msg, sizeof(msg), 0);
	cout << msg << endl;
/*
	printf("Receiving file .. \n");

int Size;
char *Filesize = new char[1024];

if(recv(Socket, Filesize, 1024, 0)) // File size
{
Size = atoi((const char*)Filesize);
printf("File size: %d\n", Size);
}

char *Buffer = new char[Size];

if(recv(Socket, Buffer, Size, 0)) // File Binary
{
FILE *File;
File = fopen("Prog.exe", "wb");
fwrite((const char*)Buffer, 1, Size, File);
fclose(File);
}

getchar();
closesocket(Socket);
WSACleanup();
*/	
	system("pause");
	return 0;
}