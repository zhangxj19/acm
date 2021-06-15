
t = int(input())
for i in range(t):
    n = int(input())
    re = 0
    P = 1e9 + 7
    a = list(map(int, input().split()))
    for j in range(n):
        x1, x2 = 0, 0
        for i in range(n):
            x1 += (a[i] & a[j])
        
        for k in range(n):
            x2 += (a[j] | a[k])

        re += x1*x2
    print((re) % P)
