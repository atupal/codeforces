#!/usr/bin/python




s = 0.
maxn = 10000
#maxn = 1
n = 5

C = [[0]*(n+1) for _ in range(n+1)]
for i in range(n+1):
  C[i][0] = 1

for i in range(1, 6):
  for j in range(1, 6):
    if i >= j:
      C[i][j] = C[i-1][j] + C[i-1][j-1]
      print (C[i][j], ' ', end='')
  print()

for i in range(1, maxn+1):
  a = 0.
  for j in range(1, n+1):
    a += C[n][j]*(1/maxn)**j  * C[n-j][1]* (maxn-i)/maxn  * ((i-1)/maxn)**max(n-j-1, 0)
  a += n*1/maxn  * (n-1)*(maxn-i)/maxn  * ((i-1)/maxn)**(n-2)
  a += n*(n-1)/2*1/maxn*1/maxn *  (n-2)*(maxn-i)/maxn * ((i-1)/maxn)**(n-3)
  a += n*(n-1)*(n-2)/2/3*1/maxn*1/maxn*1/maxn *  (n-3)*(maxn-i)/maxn * ((i-1)/maxn)**(n-4)
  a += 4*1/maxn*1/maxn*1/maxn*1/maxn *  (n-4)*(maxn-i)/maxn
  a += n*(n-1)*(n-2)*(n-3)*(n-4)*(1/maxn)**n

  s += a*i

print (s)
