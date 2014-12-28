

def main():
    n = raw_input()
    n = int(n)
    A = [0 for _ in range(10 * 9)]
    m = 0
    for i in range(n):
        r = raw_input()
        r = r.split(' ')
        k = int(r[0])
        a = int(r[1])
        m = k if k > m else m
        A[k] = a

    for i, k in enumerate(A):
        if i == m :
            c = 0
            while k > 0:
                c += 1
                k = k / 4

            print c + m
            return

        while k > 0:
            A[i + 1] += 1
            k = k / 4




main()
