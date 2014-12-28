#int(raw_input())
#[ int(_) for _ in raw_input().split() ]

n = int(raw_input())

#A = [ [] ] * (n+1)
A = []
for i in xrange(n+1):
  A.append([])

for i in xrange(n-1):
  x, y, t = [ int(_) for _ in raw_input().split() ]
  A[x].append( (y, t) )
  A[y].append( (x, t) )


dp = [0] * (n+1)

ans = set()

al = set()

#for i,j in enumerate(A[1:]):
  #print i+1, ':', j

queue = [1]
p = [None] * (n+1)

while queue:
  new_queue = []
  for i in queue:
    al.add(i)
    for x, t in A[i]:
      if x not in al:
        p[x] = (i, t)
        new_queue.append(x)
    del queue
    queue = new_queue

def go(r):
  it = r
  while it != 1:
    x, t  = p[it]
    if t == 2 and not dp[r]:
      dp[r] = 1
      ans.add(r)
    if dp[x]:break
    dp[x] += dp[r]
    it = x



for i in xrange(2, n+1):
  if len(A[i]) == 1:
    go(i)

print len(ans)
for i in ans:
  print i,
