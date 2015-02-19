# -*- coding: utf-8 -*-

import numpy as np
import copy

maxn = 100
MOD = 10**9 + 7
d = { i+1: 0 for i in xrange(maxn)}
n, x = map( int, raw_input().split() )

for i in raw_input().split():
  d[int(i)] += 1

A = [ [0] * (maxn+1) for _ in xrange(maxn+1) ]
X = [0] * maxn + [1]
X = [X]

for i in xrange(maxn-1):
  A[i+1][i] = 1
for i in xrange(maxn):
  A[i][maxn-1] = d[maxn-i]
A[maxn][maxn-1] = 1
A[maxn][maxn] = 1

A, ret, base = np.mat(A, dtype=np.uint64), np.mat(A, dtype=np.uint64), np.mat(A, dtype=np.uint64)

#ret = copy.deepcopy(A)
#base = copy.deepcopy(A)

def mul(a, b):
  ret = [ [0]*len(b[0]) for _ in xrange(len(a)) ]
  for i in xrange(len(a)):
    for j in xrange(len(b[0])):
      for k in xrange(len(b)):
        ret[i][j] += a[i][k] * b[k][j]
      ret[i][j] %= MOD
  return ret

while x:
  if x&1:
    #ret  = mul(ret, base)
    ret *= base  # TODO wil overflow when the number is huge.
    ret %= MOD
  #base = mul(base, base)
  base *= base
  base %= MOD
  x >>= 1

#ans = mul(X, ret)
ans = np.asarray(X*ret, dtype=np.uint64)
print int( ans[0][-2]%MOD )
