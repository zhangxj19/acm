import numpy as np
from numpy import random 
if __name__ == "__main__":
    n = int(input())
    np.random.seed(0)
    
    
    with open('in', 'w') as f:
        for i in range(n):
            d = {}
            num = np.random.randint(1, 65)
            f.write(f"{num}\n")
            for j in range(num):
                c = np.random.randint(32, 96)
                while c in d :
                    c = np.random.randint(32, 96)
                
                w = np.random.randint(0, 1000)
                f.write(f"{chr(c)} {str(w)}\n")
            
