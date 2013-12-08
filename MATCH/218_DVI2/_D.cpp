#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

int a[300000];
int d[300000];
int dd[1000000];
set<int> st;

int lowbit(int x)
{
  return (x&(x-1))^x;
}

int add1(int x)
{
  int i;
  for (i=x;i<1000000;i+=lowbit(i))
    dd[i]++;
}

int rem1(int x)
{
  int i;
  for (i=x;i<1000000;i+=lowbit(i))
    dd[i]--;
}

int get1(int x)
{
  int i,ret;
  ret=0;
  for (i=x;i>0;i-=lowbit(i))
    ret+=dd[i];
  return ret;
}

int find1(int y,int n)
{
  int tmp,left,right,mid;
  tmp=get1(y-1);
  left=y-1;right=n+1;
  while (right-left>1)
  {
    mid=(left+right)/2;
    if (get1(mid)==tmp) left=mid;
    else right=mid;
  }
  return right;
}

int main()
{
  int i,j,k,x,y,z,n,m;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  scanf("%d",&m);
  //st.clear();
  //for (i=0;i<=n;i++)
  //  st.insert(i);
  //set<int>::iterator tmp;
  for (i=1;i<=n+1;i++)
    add1(i);
  memset(d,0,sizeof(d));
  for (i=0;i<m;i++)
  {
    scanf("%d",&x);
    if (x==1)
    {
      scanf("%d%d",&y,&z);
      //y--;
      while ((z>0)&&(y!=n+1))
      {
        //cout<<z<<" "<<st.size()<<endl;
        //tmp=lower_bound(st.begin(),st.end(),y);
        //cout<<"p:"<<y<<endl;
        y=find1(y,n);
        //cout<<"q:"<<y<<endl;
        if (y!=n+1)
        {
          d[y]+=z;
          z=0;
          if (d[y]>=a[y])
          {
            z=d[y]-a[y];
            d[y]=a[y];
            rem1(y);
          }
        }
      }
    }
    else
    {
      scanf("%d",&y);
      //y--;
      //if (st.find(y)==st.end()) printf("%d\n",a[y]);
      //else
      printf("%d\n",d[y]);
    }
  }
}
