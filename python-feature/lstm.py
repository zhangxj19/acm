import torch
import numpy as np
  # 123
    #123
a = torch.tensor(np.random.randn(3, 4))
b = torch.tensor(np.random.randn(3, 4))
c = a * b
# torch.sigmoid()
# torch.tan()
c = torch.sigmoid(a).detach().numpy()
print(a)
print(b)
# print(c.detach())
print(c)

a = np.random.randn(3, 4)
b = np.random.randn(3, 4)
print(np.concatenate((a, b), 0))