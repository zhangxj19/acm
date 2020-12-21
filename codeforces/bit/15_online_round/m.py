import collections
class Entourage:
    def __init__(self) -> None:
        self.h = 0
        self.v = 0

        
p1, p2 = [], []
d1, d2 = [], []
idx1, idx2 = 0, 0

class Carde(Entourage):
    cnt = [0, 0]
    def __init__(self, num) -> None:
        super(Entourage, self).__init__()
        self.h = 2
        self.v = 2
        if num == 1:
            Carde.cnt[0] += 1
        elif num == 2:
            Carde.cnt[1] += 1
    
    def die(self, num, idx):
        global idx1, idx2, p1, p2, d1, d2
        if num == 1:
            Carde.cnt[0] -= 1
            d1.append(3)
            if idx < idx1:
                idx1 -= 1
        elif num == 2:
            Carde.cnt[1] -= 1
            d2.append(3)
            if idx < idx2:
                idx2 -= 1


class Dragon(Entourage):
    def __init__(self) -> None:
        super(Entourage, self).__init__()
        self.h = 4
        self.v = 4
    
    def die(self, num, idx):
        global idx1, idx2, p1, p2, d1, d2
        if num == 1:
            d1.append(1)
            if idx < idx1:
                idx1 -= 1
        elif num == 2:
            d2.append(1)
            if idx < idx2:
                idx2 -= 1

class Egg(Entourage):
    def __init__(self) -> None:
        super(Entourage, self).__init__()
        self.h = 5
        self.v = 1
    
    def die(self, num, idx):
        global idx1, idx2, p1, p2, d1, d2
        if num == 1:
            d1.append(0)
            
            to_cnt = 1 * Carde.cnt[0]
            if idx < idx1:
                idx1 += min(7 - len(p1), to_cnt)
                idx1 -= 1

            while len(p1) < 7 and to_cnt > 0:
                p1.insert(idx+1, Dragon())
                to_cnt -= 1

        elif num == 2:
            d2.append(0)

            to_cnt = 1 * Carde.cnt[1]
            if idx < idx2:
                idx2 -= 1
                idx2 += min(7 - len(p2), to_cnt)
            while len(p2) < 7 and to_cnt > 0:
                p2.insert(idx+1, Dragon())
                to_cnt -= 1


class Junior(Entourage):
    def __init__(self) -> None:
        super(Entourage, self).__init__()
        self.h = 6
        self.v = 3
    
    def die(self, num, idx):
        global idx1, idx2, p1, p2, d1, d2
        if num == 1:
            d1.append(2)
            for num in d1[:2]:
                to_cnt = 1 * Carde.cnt[0]
                if idx < idx1:
                    idx1 -= 1
                    idx1 += min(7 - len(p1), to_cnt)
                while len(p1) < 7 and to_cnt > 0:
                    if num == 0:
                        p1.insert(idx+1, Egg())
                    elif num == 1:
                        p1.insert(idx+1, Dragon())
                    elif num == 2:
                        p1.insert(idx+1, Junior())
                    elif num == 3:
                        p1.insert(idx+1, Carde())
                    to_cnt -= 1

        elif num == 2:
            d2.append(2)
            for num in d2[:2]:
                to_cnt = 1 * Carde.cnt[1]
                if idx < idx2:
                    idx2 -= 1
                    idx2 += min(7 - len(p2), to_cnt)
                while len(p2) < 7 and to_cnt > 0:
                    if num == 0:
                        p2.insert(idx+1, Egg())
                    elif num == 1:
                        p2.insert(idx+1, Dragon())
                    elif num == 2:
                        p2.insert(idx+1, Junior())
                    elif num == 3:
                        p2.insert(idx+1, Carde())
                    to_cnt -= 1

            
def summon(v: list, num):

    if num == 0:
        v.append(Egg())
    elif num == 1:
        v.append(Dragon())
    elif num == 2:
        v.append(Junior())
    elif num == 3:
        
        global p1
        global p2
        if v == p1:
            v.append(Carde(1))
        elif v == p2:
            v.append(Carde(2))

seed = 0

def myrand(m):
    global seed
    seed = seed * 22695477 + 1;
    seed %= 4294967296
    # print(seed)
    return seed%m;

def print_dbg(rd):
    # print(rd)
    # for x in p1:
    #     print(f"{x.__class__.__name__} ({x.h},{x.v})", end=' ')
    # print(end = '; d = ')
    # print(d1)

    # for x in p2:
    #     print(f"{x.__class__.__name__} ({x.h},{x.v})", end=' ')
    # print(end = '; d = ')
    # print(d2)
    pass

def main():
    global seed, idx1, idx2, p1, p2, d1, d2
    seed = int(input())

    a = list(map(int, input().split()))
    for num in a[1:]:
        summon(p1, num)

    
    a = list(map(int, input().split()))
    for num in a[1:]:
        summon(p2, num)
    
    re = 0
    for i in range(10000):
        first = myrand(2)
        # print(first)
        rd = 0
        # print(first)
        print_dbg(0)
        while len(p1) != 0 and len(p2) != 0:
            if rd % 2 == first:
                idx1 = idx1 % len(p1)
                tar = myrand(len(p2))

                # print(f'p1 {idx1} attack {tar}')

                p2[tar].h -= p1[idx1].v

                if p2[tar].h <= 0:
                    # summon or not
                    p2[tar].die(2, tar)
                    p2.pop(tar)
                    

                idx1 += 1
                idx1 %= len(p1)

            else:
                idx2 = idx2 % len(p2)
                tar = myrand(len(p1))

                # print(f'p2 {idx2} attack {tar}')

                p1[tar].h -= p2[idx2].v

                if p1[tar].h <= 0:
                    # summon or not
                    p1[tar].die(1, tar)
                    p1.pop(tar)
                    

                idx2 += 1
                idx2 %= len(p2)
            rd += 1

            print_dbg(rd)

        
        # print("new round result is")
        # print(p1, p2)

        if len(p2) == 0 and len(p1) != 0:
            re += 1
    
    print(re)


if __name__ == "__main__":
    main()