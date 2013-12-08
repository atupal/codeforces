
n,m = [int(_) for _ in raw_input().split()]
s=[None]*n
for i in xrange(n):
  s[i]=raw_input().replace(" ",'')


ans = [0] * 4
if '1' in s[0]:ans[0]=1 
if '1' in s[n-1]:ans[1]-=1

for i in xrange(n):
  if s[i][0] == '1':
    ans[2]=1
    break

for i in xrange(n):
  if s[i][m-1] == '1':
    ans[3]=1
    break


if sum(ans):
  print 2
else:
  print 4
