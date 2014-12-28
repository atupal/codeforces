#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int Maxn=100005;
int n,m,w,h[Maxn],v[Maxn];
bool Check(int lowh)
{
    int flag=0;
    for(int i=1;i<=w;i++)
    {
        v[i]=max(0,lowh-h[i]-v[i-1])+v[i-1];
        if(v[i]>m)return false;
    }
    for(int i=w+1;i<=n;i++)
    {
        v[i]=max(0,lowh-h[i]-(v[i-1]-v[i-w]))+v[i-1];
        if(v[i]>m)return false;
    }
    if(flag)return false;
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=n;i++)scanf("%d",h+i);
    int l=1,r=0x3f3f3f3f;
    while(l<r)
    {
        memset(v,0,sizeof(v));
        int mid=(l+r)/2;
        if(Check(mid))l=mid+1;
        else r=mid;
    }
    printf("%d\n",l-1);
}
