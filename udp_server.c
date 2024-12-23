#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	char buf[512];
	int sckfd,nwfd,servlen,i,get;	
	struct sockaddr_in cli_addr,serv_addr;
	if((sckfd=socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		printf("CLient down");
		close(sckfd);
		exit(0);
	}

	
	bzero((char *)&serv_addr,sizeof (serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(1500);
	if(bind(sckfd,(struct sockaddr *)& serv_addr,sizeof (serv_addr))<0)
	{
		printf("\nCan not bound");
		exit(0);
	} 
	servlen=sizeof(serv_addr);	
	while(1)
		{
			printf("\nReceving data");
			get=recvfrom(sckfd,buf,512,0,(struct sockaddr *)&serv_addr,&servlen);
			printf("\n$Client ::%s",buf);			
if(strcmp(buf,"x")==0)
			break;			
		}
				printf("Server down");			
                close(sckfd);		
            }
