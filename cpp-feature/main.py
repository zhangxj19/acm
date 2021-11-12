import numpy as np
import matplotlib.pyplot as plt

np.random.seed(1)

def f(x, a, b):
  return a * x + b

def fit_line(x, y):
    coeffs = [0, 0]
    # write code here

    lr = 0.001
    for _ in range(2):
      for i, _x in enumerate(x):
        # loss = 0.5 * (y[i] - f(_x, coeffs[0], coeffs[1])**2
        loss = 0.5 * (f(_x, coeffs[0], coeffs[1]) - y[i])**2
        l_a = (f(_x, coeffs[0], coeffs[1]) - y[i]) * _x
        l_b = (f(_x, coeffs[0], coeffs[1]) - y[i])
        print(loss)
        coeffs[0] -= lr * l_a 
        coeffs[1] -= lr * l_b

    return coeffs

# init x and y
if False:
    # load data from std input
    n = int(input())
    x = np.zeros(n)
    y = np.zeros(n)
    raw_data = list(map(float, input().split()))
    for i in range(n):
        x[i] = raw_data[i * 2]
        y[i] = raw_data[i * 2 + 1]
else:
    # generate coeffs
    num_coeffs = 2
    np.random.uniform()
    alpha_gt = np.random.uniform(-10, 10, num_coeffs)
    print("alpha_gt: ")
    print(alpha_gt)
    # generate x and y
    x = np.linspace(-10, 10, 200)
    y = alpha_gt[0] * x + alpha_gt[1] + np.random.normal(0, 1, len(x))
# print(x)
# print(y)

alpha = fit_line(x, y)
print("%.2f %.2f" % (alpha[0], alpha[1]))

# plot the results
plt.style.use('seaborn-poster')
plt.figure(figsize=(10, 8))
plt.plot(x, y, 'b.')
y_predict = alpha[0] * x + alpha[1]
plt.plot(x, y_predict, 'r')
plt.xlabel('x')
plt.ylabel('y')
plt.show()