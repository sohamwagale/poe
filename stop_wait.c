// Stop & Wait
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<process.h>
int main()
{
    int i,j=1,frame[30], timeout=5, delay=0;
    int n;
    time_t t;
    printf("Enter number of frames: ");
    scanf("%d", &n);
    printf("\nEnter the data for frames: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &frame[i]);
    }
    srand((unsigned) time(&t));
    for(i=0;i<n;i++)
    {
        printf("\nFrame sent= %d\t Data= %d",i+1,frame[i]);
        l1: delay=rand()%10;
        printf("\nDelay=%d\n",delay);
        if(delay<timeout)
        {
            printf("\nAcknowledgement received=%d\n", i+1);
            continue;
        }
        else
        {
            while(delay!=timeout)
            {
                printf("\nWaiting..\t");
                sleep(2);
                delay--;
            }
            printf("\nTimeout\n");
            printf("\nResending Frame=%d\tData=%d\n",i+1,frame[i]);
            goto l1;
        }
    }
    printf("\n\n All data frames send");
    return 0;
}