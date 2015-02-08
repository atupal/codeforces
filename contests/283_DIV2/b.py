n = int(raw_input())
s = raw_input()

ans = int(s)
out = s
vis = set()

def dfs(x):
  global ans,out
  if x in vis:
    return
  vis.add(x)
  if int(x) < ans:
    ans = int(x)
    out = x
  t = []
  for i in x:
    t.append('%s' % ((int(i)+1)%10))
  dfs(''.join(t))
  dfs('%s%s' % (x[1:], x[0]))

dfs(s)
print out
