n = int(raw_input())

s = map(int, raw_input().split())

s.sort()

d = []
i = 0
while i < n:
  cnt = 1
  while i+1 < n and s[i+1] == s[i]:
    cnt += 1
    i += 1
  d.append([s[i], cnt])
  i += 1


n = len(d)
mo = [0] * n

if n < 2:
  print d[0][0] * d[0][1]
  exit(0)
mo[0] = (d[0][0] * d[0][1], 1)
if d[1][0] == d[0][0] + 1:
  if d[1][0] * d[1][1] > mo[0][0]:
    mo[1] = (d[1][0] * d[1][1], 1)
  else:
    mo[1] = (mo[0][0], 0)
else:
    mo[1] = (d[1][0] * d[1][1]+mo[0][0], 1)

for i in xrange(2, n):
  if d[i][0] == d[i-1][0] + 1 and mo[i-1][1]:
    if d[i][0] * d[i][1] + mo[i-2][0] > mo[i-1][0]:
      mo[i] = (d[i][0]*d[i][1]+mo[i-2][0], 1)
    else:
      mo[i] = (mo[i-1][0], 0)
  else:
    mo[i] = (d[i][0]*d[i][1]+mo[i-1][0], 1)

print mo[n-1][0]
