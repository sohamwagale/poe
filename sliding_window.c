// Sliding window
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int frame[30], n , w , i , j ;
    int ack=0 , k , m ;
    printf("Enter size of frame to be send : ");
    scanf("%d",&n);
    printf("Enter elements of frame : ");
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&frame[i]);
    }
    printf("\nEnter size of window : ");
    scanf("%d",&w);
    i=1;
    while(i<=n)
    {
        for(int j=i;j<i+w && j<=n;j++)
        {
            printf("Sent Frame=%d\t Data=%d\n",j, frame[j-1]); 
        } 
        printf("\n");
        l1:
        ack = rand() % (i+w) ;
        if(ack>=i && ack<=(i+w) && ack<=n)
        {
            printf("Acknowledgment for Frame=%d\n",ack);
            i=ack+1;
        }
        else
        goto l1;
        printf("\n");
        
    }
    return 0;
}