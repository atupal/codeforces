#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 1100;
int w[maxn];
int b[maxn];
int vis[maxn];
int ans;
int n, m;

struct node {
  int w;
  int key;
  node *next;
  node *prev;
};

node *map[maxn];

void out(node *head) {
  head = head->next;
  while (head->key) {
    printf("%d <- ", head->key);
    head = head->next;
  }
  printf("\n");
}

void solve() {
  ans = 0;
  memset(vis, 0, sizeof(vis));

  node *head;
  head = (node*) malloc (sizeof(node));
  head->key = 0;
  head->w = 0;
  head->prev = head;
  head->next = head;
  for (int i = 0; i < m; ++ i) {
    if (!vis[b[i]]) {
      node *new_node = (node*) malloc (sizeof(node));
      map[b[i]] = new_node;
      new_node->w = w[b[i]];
      new_node->key = b[i];

      new_node->prev = head->prev;
      new_node->next = head;
      head->prev->next = new_node;
      head->prev = new_node;

      vis[b[i]] = 1;
    }
  }

  //out(head);
  for (int i = 0; i < m; ++ i) {
    node *tmp = map[b[i]]->prev;
    while (tmp != head) {
      ans += tmp->w;
      tmp = tmp->prev;
    }
    tmp = map[b[i]];
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    tmp->prev = head;
    tmp->next = head->next;
    head->next->prev = tmp;
    head->next = tmp;
    //out(head);
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", w+i);
  }
  for (int i = 0; i < m; ++ i) {
    scanf("%d", b+i);
  }
  solve();

  return 0;
}
