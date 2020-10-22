import numpy as np 
if __name__ == "__main__":
    n = int(input())
    k = int(input())
    np.random.seed(0)
    with open('in', 'w') as f:
        f.write(f"{n} {k}\n")
        for i in range(n):
            x = np.random.randint(0, 500)
            if i == 0:
                f.write(str(x))
            else:
                f.write(' ' + str(x))
        f.write('\n')

        for i in range(k):
            x = np.random.randint(0, 500)
            if i == 0:
                f.write(str(x))
            else:
                f.write(' ' + str(x))
            
