import sys
sys.setrecursionlimit(25000)

cnt = 0

def fuck():
  global cnt
  cnt +=1
  fuck()

try:
  fuck()
except:
  print cnt
