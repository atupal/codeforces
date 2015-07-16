#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<map>
#include<string>
#include<string.h>
#include<vector>
#include<stdio.h>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <cmath>
#include <bitset>
#include <limits.h>
#include <limits>
#include <utility>
#include <time.h>
#include <set>
#include <numeric>
#include <functional>
#define LL long long int
#define R(i) freopen(i,"r",stdin)
#define W(i) freopen(i,"w",stdout)
#define R_W R("i.txt"),W("o.txt");
#define FOR(i,f,t) for(int i=f;i<t;i++)
#define r(e) for(int i=0;i<e;i++)
#define oo (LL)numeric_limits<int>::max()
#define readVector(n,in,v) r(n){cin>>in;v.push_back(in);}
#define readGrid(n,m,data) r(n)FOR(j,0,m){cin>>data[i][j];}
#define DFS_WHITE -1
#define DFS_GRAY 0
#define DFS_BLACK 1
#define pp pair<bool,bool> 
#define all(x) x.begin(),x.end()
using namespace std;
#define vi vector<int>
#define iii pair<ii, int>
typedef pair<int, int> ii;
int Numbers[100011];
int counter[100011];
int mx=100001;
void gms(int in,int t){
    if (!in) return;
    counter[in]++;
    Numbers[in] += t;
    while (in*2 < mx) in *= 2, counter[in]++, Numbers[in] += (++t);
}
void Solver(int in,int t){
    if (in<1 || in>mx) return;
    gms(in,t);
    
    while (in){
        if (in % 2 == 1){
            gms(in / 2, ++t);
            in /= 2;
        }
        else{
            in /= 2;
            counter[in]++;
            Numbers[in] += (++t);
        }
    }
}
int main(){
    /////R_W;
    memset(counter, 0, sizeof counter);
    memset(Numbers, 0, sizeof Numbers);
    int n;
    cin >> n;
    r(n){
        int in;
        cin >> in;
        
        Solver(in, 0);

    }
    int ans;
    bool first = true;
    r(100001){
        if (counter[i] == n){
            if (first){
                ans = Numbers[i];
                first = false;
            }
            else{
                if (Numbers[i] < ans) {
                  printf("%d\n", i);
                }
                ans = min(ans,Numbers[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
