'''
1900:01:01
2038:12:31
'''

t = raw_input().split(':')
a_y = int(t[0])
a_m = int(t[1])
a_d = int(t[2])

t = raw_input().split(':')
b_y = int(t[0])
b_m = int(t[1])
b_d = int(t[2])


m = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31]

def cnt(a, b,c):
    ret = 0
    for i in xrange(1889, a, 1):
        flag = 0
        if i % 100 == 0:
            if i % 400 == 0:
                flag = 1
        elif i % 4 == 0:
            flag = 1

        if flag:
            ret += 366
        else:
            ret += 365

    flag = 0
    if a % 100 == 0:
        if a % 400 == 0:
            flag = 1
    elif a % 4 == 0:
        flag = 1

    m[2]  = 28
    if flag:
        m[2] = 29

    for i in xrange(1, b, 1):
        ret += m[i]

    ret += c

    return ret

t  = cnt(b_y, b_m, b_d) - cnt(a_y, a_m, a_d)
print abs(t)
