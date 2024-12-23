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
struct sockaddr_in stSockAddr;
SocketFD=socket(AF_INET,SOCK_STREAM,0);
if(SocketFD<0)
{
perror("can not create socket");
exit(EXIT_FAILURE);
}
bzero(&stSockAddr,sizeof(stSockAddr));
stSockAddr.sin_family=AF_INET;
stSockAddr.sin_port=htons(1109);
stSockAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
int xyz=connect(SocketFD,(struct sockaddr*)&stSockAddr,sizeof(stSockAddr));
if(xyz<0)
{
perror("can not connect");
close(SocketFD);
exit(EXIT_FAILURE);
}
while(1)
{
printf("\nEnter data to be sent: ");
//scanf("%s",buff);
gets(buff);
write(SocketFD,buff,512);
printf("Reciving data from server....");
read(SocketFD,buff,512);
if(strcmp(buff,"X")==0)
break;
printf("\n Data is:%s",buff);
printf("Enter an integer for reverse the string")
scanf("%d", &n);
}
printf("\n");
close(SocketFD);
}