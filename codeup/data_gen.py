import numpy as np
from numpy import random 

def gen_x_y(b, e):
    x, y = random.randint(b, e), random.randint(b, e)
    while y == x:
        y = random.randint(b, e)  

    return (x, y)  

if __name__ == "__main__":
    n, m = map(int, input().split())
    np.random.seed(0)
    
    with open('in', 'w') as f:
        f.write(f"{n} {m}\n")
        s = set()
        for i in range(m):
            x, y = gen_x_y(0, n)
            while (x, y) in s or (y, x) in s:
                x, y = gen_x_y(0, n)
            f.write(f"{x} {y}\n")
            s.add((x, y))
            s.add((y, x))
        

    
            
