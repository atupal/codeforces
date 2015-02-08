

n, k = map(int, raw_input().split())
p = map(int, raw_input().split())


def get(a):
  ret = 0
  for i in xrange(len(a)):
    for j in xrange(i+1, len(a)):
      if a[i] > a[j]:
        ret += 1
  return ret

cnt = 0.
s = 0.

def dfs(a, idx):
  if idx == 0:
    global cnt
    global s
    cnt += 1
    s += get(a)
    return

  for i in xrange(n):
    for j in xrange(i, n):
      t = a[:i] + a[i:j+1][::-1] + a[j+1:]
      dfs(t, idx-1)

dfs(p, k)
#for i in xrange(n):
#  for j in xrange(i, n):
#    a = p[:i] + p[i:j+1][::-1] + p[j+1:]
#    cnt += 1
#    s += get(a)

print s/cnt
