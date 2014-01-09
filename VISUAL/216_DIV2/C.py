#int(raw_input())
#[ int(_) for _ in raw_input().split() ]
import sys
sys.setrecursionlimit(10000)

n = int(raw_input())

#A = [ [] ] * (n+1)
A = []
for i in xrange(n+1):
  A.append([])

for i in xrange(n-1):
  x, y, t = [ int(_) for _ in raw_input().split() ]
  A[x].append( (y, t) )
  A[y].append( (x, t) )


dp = [-1] * (n+1)

cnt = 0
ans = []


al = set()

#for i,j in enumerate(A[1:]):
  #print i+1, ':', j


def dfs(r):
  al.add(r)
  if dp[r] != -1:
    return dp[r]
  ret = 0
  for x, t in A[r]:
    if x != r and x not in al:
      tmp = dfs(x)
      ret += tmp
      if t == 2:
        ret += 1
        if not tmp:
          global cnt
          cnt += 1
          ans.append(x)

  dp[r] = ret
  return ret


dfs(1)

print cnt
for i in ans:
  print i,
