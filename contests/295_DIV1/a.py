#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

def h(s, t):
  ret = 0
  for i in xrange(len(s)):
    if s[i] == t[i]:
      ret += 1

  return ret

def p(s, t):
  ret = 0
  for i in xrange(len(t)):
    ret += h(s, t[i:]+t[:i])

  return ret

class mydict(dict):
  def __missing__(self, key):
    self[key] = set()
    return self[key]

d = mydict()
def dfs(n, t):
  if n == len(s):
    d[p(s, t)].add(t)
    return
  for w in ['A', 'C', 'G', 'T']:
    dfs(n+1, t+w)

"""
s = raw_input()

dfs(0, '')

d = d.items()
d.sort(reverse=True)
print d[0], len ( d[0][1] )
exit(0)
"""

n = int(raw_input())
s = raw_input()
a = [0]*4
a[0] = s.count('A')
a[1] = s.count('C')
a[2] = s.count('G')
a[3] = s.count('T')

while 0 in a:
  a.remove(0)

a.sort()
cnt = 1
for i in a[:-1]:
  if i == a[-1]:
    cnt += 1

MOD = 10**9+7

base=cnt
ret=1
while n:
  if n&1:
    ret *= base
    ret %= MOD
  base*=base
  base5=MOD
  n >>= 1

print ret
