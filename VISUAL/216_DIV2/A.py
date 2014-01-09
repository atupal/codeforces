#int(raw_input())
#[ int(_) for _ in raw_input().split() ]

n, m, k =  [ int(_) for _ in raw_input().split() ]

A = [ int(_) for _ in raw_input().split() ]

x = y = 0

cnt = 0

for i in A:
  if i == 1:
    x += 1
  else:
    if y + 1 > k:
      x += 1
    else:
      y += 1

  if x > m:
    cnt += 1
    x -= 1

  if y > k:
    cnt += 1
    y -= 1

print cnt
