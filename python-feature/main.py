import numpy as np
# np.random.seed(0)

def isGirl():
  return np.random.rand() > 0.5

n = 1000000
girl = 0
boy = 0
for i in range(n):
  while isGirl() != True:
    boy += 1
  girl += 1

print(girl / (girl + boy))
