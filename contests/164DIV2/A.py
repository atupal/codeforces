import sys

def main():
    n = raw_input()
    n = int(n)
    A = [ _.replace('\n', '').split(' ') for _ in sys.stdin.readlines()]
    ans = 0
    for i,a in enumerate(A):
        for j, b in enumerate(A):
            if i != j and a[1] == b[0]:
                ans += 1
    print ans

main()
