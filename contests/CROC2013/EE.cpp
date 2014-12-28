#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define N 101000
char s[3*N];
int p[3*N], l, r;
vector <int> m[N];
string w[N];
stack< pair<int , int> >sta;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++ i) {
        int x;
        scanf("%d %s", &x, s);
        w[i + 1] = s;
        m[x].push_back(i + 1);
    }
    int j = -1;
    p[0] = -1;
    scanf("%s", s);
    int mmm = strlen(s);
    for (int i = 1; s[i]; ++ i) {
        while (j > -1 && s[i] != s[j + 1]) 
            j = p[j];
        if(s[i] == s[j + 1])
            ++ j;
        p[i] = j;
    }
    sta.push(make_pair(1, -1));
    while (not sta.empty()) {
        pair<int, int> pop = sta.top();
        sta.pop();
        int node = pop.first;
        int y = pop.second;
        for (int i = 0; i < m[node].size(); ++ i) {
            int j = y;
            for (int x = 0; x < w[m[node][i]].size(); ++ x) {
                while (j > -1 and w[m[node][i]][x] != s[j + 1]) 
                    j = p[j];
                j += w[m[node][i]][x] == s[j + 1];
                if (j == mmm - 1) {
                    r += 1;
                    j = p[j];
                }
            }
            sta.push(make_pair(m[node][i], j));
        }
    }
    printf("%d\n", r);

    return 0;
}
