
from random import randint

def main():
    n = raw_input()
    n = int(n)
    if n == 0 or n == 1:
        print "0"
        return
    A = raw_input()
    A = A.split(' ')
    A = [int(_) for _ in A]
    cnt = 0
    if len(A) == 1:
        print cnt
        return

    min =  A[len(A)  - 1]
    max = 0
    A = [A[_] for _ in range(len(A) - 1, -1, -1)]

    for i, k in enumerate(A[1:]):
        if k > min:
            cnt += 1
            if k > max:
                k = max
        elif k < max:
            cnt += 1

        min = min if min < k else k

    print cnt

main()
