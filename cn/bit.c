// Bit Stuffing
#include<stdio.h>
void main()
{
    int i=0, j=0, k=0, l=0, m=0, n, count=0;
    int a[10], b[10], c[10];
    printf("Enter Length: ");
    scanf("%d",&n);
    printf("Enter Bits: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Original Data: ");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            count++;
            b[j] = a[i];
            j++;
        }
        else
        {
            count=0;
            b[j] = a[i];
            j++;
        }
        if(count==5)
        {
            b[j]=0;
            j++;
            count=0;
        }
    }
    printf("\nStuffed Data: ");
    for(i=0;i<j;i++)
    {
        printf("%d",b[i]);
    }

    for(i=0;i<j;i++)
    {
        if(b[i]==1)
        {
            count++;
            c[m] = b[i];
            m++;
        }
        else
        {
            count=0;
            c[m] = b[i];
            m++;
        }
        if(count == 5)
        {
            i++;
            count=0;
        }
    }
    printf("\nDestuffed Data: ");
    for(i=0;i<m;i++)
    {
        printf("%d",c[i]);
    }
}