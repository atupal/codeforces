
import dis
from random import choice

def func():
  a = 1
  b = 's'
  c = []
  random = choice([a, b, c])
  print type(random)

dis.dis(func)
