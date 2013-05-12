#pragma comment (linker, "/STACK:100000000")
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
#define N 101000
char s[3*N];
int p[3*N], l, r;
vector <int> m[N];
string w[N];
void dfs(int i, int v)
{
    int j;
    for(j=0; j<w[i].size(); v++, r+=v==l, j++)
        for(; v!=-1 && w[i][j]!=s[v]; v=p[v]);
    for(j=0; j<m[i].size(); dfs(m[i][j], v), j++);
}
int main()
{
    int i, j, n;
    for(scanf("%d", &n), i=1; i<n; scanf("%d%s", &j, s), j--, m[j].push_back(i), w[i]=s, i++);
    scanf("%s", s);
    for(p[0]=-1, j=-1, l=0; s[l]; j++, p[l+1]=j, l++)
        for(; j!=-1 && s[l]!=s[j]; j=p[j]);
    s[l]='$';
    dfs(0, 0);
    printf("%d\n", r);
    return 0;
}
