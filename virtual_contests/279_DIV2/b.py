n = int(raw_input())

maxn = 10**6+1;
prev = [0] * maxn
next = [0] * maxn
tmp = [1] * maxn
s = set()

for i in xrange(n):
  x, y= map(int, raw_input().split())
  s.add(x)
  s.add(y)
  tmp[y] = 0
  prev[y] = x
  next[x] = y
  if x== 0: a2 = y

out1 = []
while a2:
  out1.append(a2)
  a2 = next[a2]

out2 = []
for i in s:
  if tmp[i]:
    a1 = i

while a1:
  out2.append(a1)
  a1 = next[a1]

for i in xrange(n):
  if not (i&1):
    print out2[i>>1],
  else:
    print out1[i>>1],

print 
