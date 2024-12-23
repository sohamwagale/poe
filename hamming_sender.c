// Hamming Code Sender
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int data[10];
    int r=0,msg[20],m,n,i;
    int r1,r2,r4;
    printf("Enter size of dataword (m): ");
    scanf("%d",&m);
    printf("Enter bits: ");
    for( i=0;i<m;i++)
    {
        scanf("%d",&data[i]);
    }
    for(int i=1; ;i++)
    {
        if((m+i+1)<=pow(2,i))
        {
            r=i;
            break;
        }
    }
    printf("\nNo. of Redundant bits r=%d\n",r);
    n=m+r;
    printf("\nn=m+r\tn=%d\n",n);
    msg[0]=data[0];
    msg[1]=data[1];
    msg[2]=data[2];
    msg[3]=r4;
    msg[4]=data[3];
    msg[5]=r2;
    msg[6]=r1;
    r1=(msg[4]+msg[2]+msg[0])%2;
    printf("\nr1=%d\n",r1);
    r2=(msg[4]+msg[1]+msg[0])%2;
    printf("r2=%d\n",r2);
    r4=(msg[2]+msg[1]+msg[0])%2;
    printf("r4=%d\n",r4);
    msg[3]=r4;
    msg[5]=r2;
    msg[6]=r1;
    printf("Codeword to be transmitted: ");
    for(int i=0;i<n;i++)
    {
        printf("%d",msg[i]);
    }
}