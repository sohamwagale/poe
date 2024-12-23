#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
char buff[512];
int SocketFD;
struct sockaddr_in stSockAddr, cli_addr;
SocketFD=socket(AF_INET,SOCK_STREAM,0);
if(SocketFD<0)
{
perror("can not creat socket");
exit(EXIT_FAILURE);
}
bzero(&stSockAddr,sizeof(stSockAddr));
stSockAddr.sin_family=AF_INET;
stSockAddr.sin_port=htons(1109);
stSockAddr.sin_addr.s_addr=INADDR_ANY;
if(bind(SocketFD,(struct sockaddr*)&stSockAddr,sizeof(stSockAddr))<0)
{
perror("can not bind");
close(SocketFD);
exit(EXIT_FAILURE);
}
int a=sizeof(cli_addr);
listen(SocketFD,2);
int connectFD=accept(SocketFD,(struct sockaddr*)&cli_addr,&a);
if(connectFD<0)
{
perror("can not connect");
close(SocketFD);
exit(EXIT_FAILURE);
}
while(1)
{
printf("\n RECEIVING DATA FROM CLIENT.....\n");
read(connectFD,buff,512);
printf("Data is:%s",buff);
if(strcmp(buff,"x")==0)
break;
printf(" Enter Data to be sent:");
gets(buff);
write(SocketFD,buff,512);
}
close(connectFD);
return EXIT_SUCCESS;
char str[40]; // declare the size of character string
printf (" \n Enter a string to be reversed: ");
gets (str);
printf (" \n After the reverse of a string: %s ", strrev(str));
}