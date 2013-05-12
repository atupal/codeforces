
ans = 0
A = [0]

def f(x, m):
    global A
    A.append(x)
    ff = 0
    if len(A) - 1 == m:
        for i in A:
            t = i
            flag = 0
            for i in xrange(8):
                t = A[t]
                if t == 1:
                    flag = 1
                    break
            if flag == 0:
                ff = 1
                break
        if ff == 0:
            global ans
            ans += 1
    else:
        for i in xrange(m):
            f(i + 1, m)

for i in xrange(8):
    global ans
    ans = 0
    x = i + 1
    for j in xrange(x):
        f(j + 1, x)
    print ans


