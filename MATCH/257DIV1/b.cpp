#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

#define maxn  200010
#define INF 1000000010

typedef struct G_NODE {
    int u, v, w;
    struct G_NODE *next;
} Gnode;

int n, m, k, d[maxn];
int s[maxn];
int ans;
Gnode *a[maxn];

void add_edge(int x, int y, int c) {
    Gnode *p = new Gnode;
    p->u = x;
    p->v = y;
    p->w = c;
    p->next = a[x]->next;
    a[x]->next = p;
}

void init_g() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        a[i] = new Gnode;
        a[i]->next = NULL;
    }
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        add_edge(x, y, c);
        add_edge(y, x, c);
    }
    for (int i = 2; i <= n; ++ i)
      s[i] = INF;
    for (int i = 0; i < k; ++ i) {
      int a, b;
      scanf("%d %d", &a, &b);
      s[a] = b;
    }
}

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;
bool done[maxn];

void dijkstra(int s) {
    Gnode *p;

    memset(done, false, sizeof(done));
    for (int i = 1; i <= n; ++i)
        d[i] = (i == s ? 0 : INF);
    
    q.push(make_pair(d[s], s));
    while (!q.empty()) {
        pii u = q.top();
        q.pop();
        int x = u.second;
        if (done[x])
            continue;
        for (p = a[x]->next; p; p = p->next) if (d[p->v] > d[x] + p->w) {
            d[p->v] = d[x] + p->w;
            q.push(make_pair(d[p->v], p->v));
        }
    }
}

int main() {
    init_g();
    dijkstra(1);
    ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (d[i] == s[i])
          ans ++;
    }
    printf("%d\n", ans);

    return 0;
}
