// Hamming code receiver
#include<stdio.h>
#include<math.h>
int main()
{
    int data[10],msg[10], msg1[7];
    int r1,r2,r4,decimal,i,m, j;
    printf("Enter size of dataword received: ");
    scanf("%d",&m);
    printf("Enter bits: ");
    for( i=0;i<m;i++)
    {
        scanf("%d",&msg[i]);
    }
    r1=(msg[6]+msg[4]+msg[2]+msg[0])%2;
    printf("r1=%d\n",r1);
    r2=(msg[5]+msg[4]+msg[1]+msg[0])%2;
    printf("r2=%d\n",r2);
    r4=(msg[3]+msg[2]+msg[1]+msg[0])%2;
    printf("r4=%d\n",r4);
    if(r1!=0 || r2!=0 || r4!=0)
    {
    printf("Error in received data\n");
        decimal=(r4*pow(2,2)+r2*pow(2,1)+r1*pow(2,0));
        printf("Decimal=%d\n",decimal);
        for(i=m-1,j=0; i>=0,j<m; i--,j++)
        msg1[j]=msg[i];
        //Inverting the error bit
        msg1[decimal-1]=!msg1[decimal-1];
        for(i=m-1,j=0; i>=0,j<m;i--, j++)
        msg[j]=msg1[i];
        printf("\nCorrect codeword: ");
        for(i=0;i<m;i++)
        {
            printf("%d",msg[i]);
        }
    }
    else
    { 
        printf("\n No Error in received data\n");
        printf("\nCodeword: ");
        for(i=0;i<m;i++)
        {
            printf("%d",msg[i]);
        }
    }
}