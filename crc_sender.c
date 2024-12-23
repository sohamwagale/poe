#include<stdio.h>
int main()
{
   int frame[20], genpoly[10], msg[25], n, size, temp[10], msgsend[25];
    int i=0,j=0,k=0, msglen=0, num=0;
     printf("Enter the size of frame: ");
     scanf("%d",&size);
     printf("\n Enter the frame: ");
	 for(i=0;i<size;i++)   
	 {
	   scanf("%d", &frame[i]);
     }
     
     printf("\n Enter the size of generator polynomial or divisor: ");
     scanf("%d", &n);
    printf("\n Enter the generator polynomial or divisor: ");
     for(i=0;i<n;i++)   
	 {
	   scanf("%d", &genpoly[i]);
     }
              
     for(i=0;i<size;i++)
     {
     	msg[msglen]=frame[i];     
     	msglen++;
	 }
    
    for(i=0;i<n-1;i++)
     {
     	msg[msglen]=0;     	
     	msglen++;
	 }
	 
	 printf("\n Message to be transmitted: ");
	 for(i=0;i<msglen;i++)
	 {
	 	printf("%d", msg[i]);
	 }
	 



	 printf("\n");
	for(i=0;i<n;i++)
	{
		temp[i]=msg[i];
	}
	num=n-1;
	while(num<msglen)
	{
		num++;
		if(temp[0]==1)
		{
		for(i=0;i<n;i++)
		{
			temp[i]=((temp[i]+genpoly[i])%2);
						
		}
		}
		printf("\n\nResult: ");
		for(i=0;i<n;i++)
		{
		     printf("%d",temp[i]);
		
		}
		
		for(i=0;i<n-1;i++)
		{
			temp[i]=temp[i+1];
			
		}
		if(num!=msglen)
		temp[n-1]=msg[num];

		printf("\nAfter shifting: ");
		if(num==msglen)
		{
		for(i=0;i<n-1;i++)
		{
		     printf("%d",temp[i]);		
		}
		}
		else
		{
		for(i=0;i<n;i++)
		{
		     printf("%d",temp[i]);
		
		}
		}
	
	}

		
	for(i=0;i<size;i++)
	{
		msgsend[i]=msg[i];
	}
	k=0;
	for(i=size;i<msglen;i++)
	{
		msgsend[i]=temp[k];
		k++;
	}

	printf("\n\nMessage to be transmitted: ");

	for(i=0;i<msglen;i++)
	{			
		printf("%d",msgsend[i]);
	}
}
