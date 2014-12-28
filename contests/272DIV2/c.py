
a, b = map(int, raw_input().split())

MOD = 1000000007

print b*(b-1)/2 * (   b * (1+a)*a/2 + a ) % MOD
