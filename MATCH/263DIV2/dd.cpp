#include<string.h>
#include<stdio.h>
#define  LL long long
#define maxn 300005
#define MOD 1000000007
using namespace std;
char a[100][100];
LL ans;
LL sum;
LL tot;
LL next[maxn],fir[maxn],ver[maxn],f[maxn],g[maxn],col[maxn];
void add(int x,int y)
{
    next[++tot]=fir[x];
    ver[tot]=y;
    fir[x]=tot;
}
void dfs(int x,int fa)
{
    f[x]=col[x];
    g[x]=1-col[x];
    int y;
    for(int p = fir[x];p;p=next[p])
        if((y=ver[p])!=fa)
    {
        dfs(y,x);
        if(col[x])
            f[x]=f[x]*(g[y]+f[y])%MOD;
        else
        {
            f[x]=(f[x]*(f[y]+g[y])+g[x]*f[y])%MOD;
            g[x]=g[x]*(f[y]+g[y])%MOD;
        }
    }
}
int main()
{
   int n,x;
   scanf("%d",&n);
   for(int i =1;i<n;i++)
   {
       scanf("%d",&x);
       add(i,x);
       add(x,i);
   }
   for(int i = 0;i<n;i++) scanf("%d",col+i);
   dfs(0,-1);
   printf("%I64d\n",f[0]);

   return 0;
}

