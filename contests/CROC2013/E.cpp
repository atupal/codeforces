
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 3e5 + 5;

int ans = 0;
char **vv;

void add(int, int);

int *jump;
int **vv_x;
int **vv_y;

void go(char *s) {
    int n = strlen(s);
    jump = (int *) malloc (sizeof(int) * (n + 1));
    int j = -1;
    jump[0] = -1;
    for (int i = 1; i < n; ++ i) {
        while (j > -1 and s[i] != s[j + 1]) 
            j = jump[j];
        if (s[i] == s[j + 1]) 
            ++ j;
        jump[i] = j;
    }
}


void solve(int x, char *ts, char *p) {
    int n = strlen(ts);
    int m = strlen(p);
    int j = -1;
    for (int i = 0; i < n; ++ i) {
        while (j > -1 and ts[i] != p[j + 1]) 
            j = jump[j];
        if (ts[i] == p[j + 1])
            ++ j;

        if (j == m - 1) {
            add(x, i - m + 1);
            j = jump[j];
        }
    }
}

int *p;
char **s;
int n;

void add(int x, int y) {
    //printf("%d %d\n", vv_x[x][y], vv_y[x][y]);
    if (not vv[ vv_x[x][y] ][ vv_y[x][y] ]) {
        ++ ans;
        vv[ vv_x[x][y] ][ vv_y[x][y] ] = 1;
    }
    return;
}

int main() {
    int len;
    scanf("%d", &n);
    p = (int *) malloc (sizeof(int) * (n + 1));
    s = (char **) malloc (sizeof(char*) * (n + 1));
    char v[n + 1];
    memset(v, 0 ,sizeof(v));
    vv = (char **) malloc (sizeof(char*) * (n + 2));
    s[0] = (char *) malloc (sizeof(char) * (maxn + 1));
    s[1] = (char *) malloc (sizeof(char) * (maxn + 1));
    for (int i = 2; i <= n; ++ i) {
        char tmp[maxn];
        int t;
        scanf("%d %s", &t, tmp);
        int l = strlen(tmp);
        s[i] = (char *) malloc (sizeof(char) * (l + 1));
        strcpy(s[i], tmp);
        p[i] = t;
        v[t] = 1;
        len = strlen(tmp);
        char *_vv = (char*) malloc (sizeof(char) * (len + 2));
        memset(_vv, 0 , sizeof(char) * (len + 2));
        vv[i] = _vv;
    }

    char ts[maxn];

    char tmp[maxn];
    char mo[maxn];
    scanf("%s", tmp);
    memset(mo, 0, sizeof(mo));
    for (int i = 0; i < (signed int)strlen(tmp); ++ i) 
        mo[i] = tmp[strlen(tmp) - 1 - i];

    go(mo);

    int cnt = 0;
    vv_x = (int **) malloc (sizeof(int*) * (n + 1));
    vv_y = (int **) malloc (sizeof(int*) * (n + 1));
    for (int i = 2; i <= n; ++ i) if (not v[i]) {
        ++ cnt;
        int cur = i;
        int ind = 0;
        memset(ts, 0, sizeof(ts));
        vv_x[i] = (int*)malloc(sizeof(int) * maxn);
        vv_y[i] = (int*)malloc(sizeof(int) * maxn);
        while (cur != 1) {
            for (int x = strlen(s[cur]) - 1; x >= 0; -- x) {
                ts[ind] = s[cur][x];
                //vv_x[i] = (int*)realloc(vv_x[i], sizeof(int) * (ind + 1));
                //vv_y[i] = (int*)realloc(vv_y[i], sizeof(int) * (ind + 1));
                vv_x[i][ind] = cur;
                vv_y[i][ind] = x;
                ind ++;
            }
            cur = p[cur];
        }
        solve(i, ts, mo);
    }
    printf("%d\n", ans);

    return 0;
}

