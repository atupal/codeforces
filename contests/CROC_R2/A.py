n  = int(raw_input())

tmp = raw_input()
tmp = tmp.split(' ')
A = [int(i) for i in tmp]
m = A[0]
for i in A:
    if i < m:
        m = i

for  i in A:
    if m == 1:
        print '1'
        exit()
    if not i % m == 0:
        print '-1'
        exit()


print m
