n = int(input())


def char2int(ch):
    ch = ord(ch)
    if ord('0') <= ch and ch <= ord('9'):
        return ch - ord('0')
    elif ord('A') <= ch and ch <= ord('Z'):
        return ch - ord('A') + 10
    else:
        return ch - ord('a') + 36
        
def int2char(x):
    if 0 <= x and x < 10:
        return chr(x + ord('0')) 
    elif 10 <= x and x < 36:
        return chr(x - 10 + ord('A')) 
    else:
        return chr(x - 36 + ord('a'))

def convert(x, y, z):
    # to 10
    
    num = 0
    for ch in z:
        num *= x
        num += char2int(ch)
    
    # to base y
    if num == 0:
        return '0'
    re = ""
    while num:
        re += int2char(num % y)
        num //= y
    
    re = re[::-1]
    
    return re
    
for t in range(n):
    x, y, z = input().split()
   
    x = int(x)
    y = int(y)
    
    print(f"{x} {z}")
    print(f"{y} {convert(x, y, z)}")
    print()