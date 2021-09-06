T = int(input())
for _ in range(T):
    t = input()
    n, k = map(int, t.split())
    # print(n, k)

    lb, rb = n, n * 10**(k)
    # print(lb, rb)
    for d in range(1, 10**k + 1):
      if d * n % (10 **k) == 0:
        print(d * n)
        break


