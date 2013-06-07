#include <stdio.h>
#include <stdlib.h>

long long a[200001],n,k;

int main()
{
    int i,j,k,m;
    long long sum=0;
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    m=n;j=2;
    for (i=2;i<=n;i++)
        if ((sum-a[i]*(m-j)*(j-1))<k) 
        {
            printf("%d\n",i);
            m--;
        }
        else 
        {
            j++;
            sum+=(j-2)*a[i];
        }

    return 0;
}
