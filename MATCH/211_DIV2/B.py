n,k = [int(_) for _ in raw_input().split()]
h = [int(_) for _ in raw_input().split()]

ans=0
m=sum(h[:k])
mm=m

for i in xrange(n-k):
  m-=h[i]
  m+=h[i+k]

  if m < mm:
    mm=m
    ans=i+1
print ans+1
