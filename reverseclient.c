#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
struct sockaddr_in address;
int sock = 0, valread;
struct sockaddr_in serv_addr;
char str[100];
printf("\nInput the string:");
scanf("[^\n]s", str);
char buffer[1024] = { 0 };
if ((sock = socket(AF_INET,SOCK_STREAM, 0))< 0) {
printf("\n Socket creation error \n");
return -1;
}
memset(&serv_addr, '0', sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);
if (inet_pton(AF_INET, "10.10.1.151",&serv_addr.sin_addr)<= 0) {
printf("\nAddress not supported \n");
return -1;
}
t
if (connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr))< 0) {
printf("\nConnection Failed \n");
return -1;
}
int l = strlen(str);
send(sock, str, sizeof(str), 0);
valread = read(sock, str, l);
printf("%s\n", str);
return 0;
}
