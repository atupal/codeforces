

def main():
    n = raw_input()
    n = int(n)
    ans = 0
    for i in range(n):
        j = i + 1
        ans += (n - j) * j + 1
    print ans
main()
