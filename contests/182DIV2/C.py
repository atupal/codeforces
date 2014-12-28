
n = int(raw_input())
A = raw_input().split(' ')
A = [int(i) for i in A]

cnt_1 = 0
s = 0
m = abs(A[0])
for i in A:
    cnt_1 += 1 if i < 0 else 0
    s += abs(i)
    m = abs(i) if abs(i) < m else m

if cnt_1 == n:
    print s
elif cnt_1 % 2:
    print s - m * 2
else:
    print s


