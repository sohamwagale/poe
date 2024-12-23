#include<stdio.h>
int main()
{
   int frame[20], genpoly[10], msgrec[25], n, size, temp[10];
    int i=0,j=0,f=0, num=0;
     printf("Enter the size of Received frame: ");
     scanf("%d",&size);
     printf("\n Enter the Received frame: ");
	 for(i=0;i<size;i++)   
	 {
	   scanf("%d", &msgrec[i]);
     }
     
    printf("\n Enter the size of generator polynomial or divisor: ");
    scanf("%d", &n);
    printf("\n Enter the generator polynomial or divisor: ");
     for(i=0;i<n;i++)   
	 {
	   scanf("%d", &genpoly[i]);
     }
                  	  
	printf("\n");
	for(i=0;i<n;i++)
	{
		temp[i]=msgrec[i];
	}
	num=n-1;
	while(num<size)
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
		if(num!=size)
		temp[n-1]=msgrec[num];

		printf("\nAfter shifting: ");
		if(num==size)
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

printf("\n\nRemainder: ");
for(i=0;i<n-1;i++)
		{
		     printf("%d",temp[i]);		
		}
		
                 f=0;
		for(i=0;i<n;i++)
		{
			if(temp[i]!=0)
			{
				f=1;
					printf("\nReceived Frame contains error\n");
				break;
			}
		}


		if(f==0)
		{
			printf("\nReceived Frame is error free and it is: ");
			for(i=0;i<size-(n-1);i++)
			{
				printf("%d",msgrec[i]);
			}
		}
	printf("\n");
}
