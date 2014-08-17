#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 1000007;
int a[maxn];
int n;

struct node {
  int key;
  int val;
  node *next;
};

node *hash[maxn] = {NULL};

inline
void insert(int key) {
  int mod = key % maxn;
  node *tmp = hash[mod];
  while (tmp) {
    if (tmp->key == key) {
      ++ tmp->val;
      return;
    }
    tmp = tmp->next;
  }
  tmp = (node *) malloc (sizeof(node));
  tmp->key = key;
  tmp->val = 1;
  tmp->next = hash[mod];
  hash[mod] = tmp;
}

inline
int get(int key) {
  int mod = key % maxn;
  node *tmp = hash[mod];
  while (tmp) {
    if (tmp->key == key) {
      return tmp->val;
    }
    tmp = tmp->next;
  }
  return 0;
}

void free_hash() {
  for (int i = 0; i < maxn; ++ i)  {
    free(hash[i]);
    hash[i] = NULL;
  }
}

int ai[maxn];
int aj[maxn];

int bit[maxn] = {0};

inline
int lowbit(int x) {
  return x&(-x);
}

int sum(int x) {
  int ret = 0;
  while (x) {
    ret += bit[x];
    x -= lowbit(x);
  }
  return ret;
}

void modify(int x, int c) {
  while (x <= n) {
    bit[x] += c;
    x += lowbit(x);
  }
}

void solve() {
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a+i);
    insert(a[i]);
    ai[i] = get(a[i]);
  }
  //for(int i = 0; i < n; ++ i) {
  //  printf("%d ", ai[i]);
  //}
  //printf("\n");
  free_hash();
  for (int i = n-1; i > 0; -- i) {
    insert(a[i]);
    aj[i] = get(a[i]);
    //printf("%d ", aj[i]);
    modify(aj[i], 1);
    ans += sum(ai[i-1]-1);
  }
  //printf("\n");
  printf("%I64d\n", ans);
}

int main() {
  solve();
  return 0;
}
