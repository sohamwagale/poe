#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char buf[512];
	int sckfd,get;
	struct sockaddr_in serv_addr;
	
	bzero((char *)&serv_addr,sizeof (serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(1500);
	
	if((sckfd=socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		printf("Server down");
		close(sckfd);
		exit(0);
	}
	printf("\nConnected to server");
	while(1){
		printf("\nEnter the string::");
		scanf("%s",&buf);
		printf("\nSending data");
		get=sendto(sckfd,buf,512,0,(struct sockaddr *)&serv_addr,sizeof (serv_addr));
		if(strcmp(buf,"x")==0)
			break;
	}
	
	printf("Client down");
	close(sckfd);
}
