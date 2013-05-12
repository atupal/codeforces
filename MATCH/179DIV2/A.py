n = raw_input()
n = int(n)
A = raw_input()
A = A.split(' ')
A = [int(_) for _ in A]
m = 0

for i in A:
    cnt = 0
    for j in A:
        if i == j:
            cnt += 1
    if cnt > m:
        m = cnt

if n % 2 == 0:
    n = n / 2
else:
    n = n / 2 + 1

print "YES" if m <= n else "NO"
