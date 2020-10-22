// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define DEBUG

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;

bool equ(double a, double b){
    return fabs(a-b) < eps;
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

using namespace std;

const int maxn = 100;
const int maxname = 8;

int n, m;


struct Disk{
    char tmp[32];
    int b[3];
    int seq, stripesize, num; // seq < num
    int manner; // 0, 4, 8, 12
    int id;
    int uid;

    void rdBasic(const char filename[]){
        FILE* f = fopen(filename, "rb");
        fseek(f, -8, SEEK_END);
        fread(tmp, 8, 1, f);
        uu(i, 0, 3) b[i] = (unsigned char)tmp[i];
        seq = (unsigned char)tmp[3];
        stripesize = (unsigned char)tmp[4];
        num = (unsigned char)tmp[5];
        manner = (unsigned char)((tmp[6] >> 6) & 0x03);
        id = (unsigned short)((tmp[6] & 0x3f) << 8) + (unsigned short)tmp[7];
        uu(i, 4, 8){
            uid += (uint32_t)(tmp[i] << ((7 - i)*8));
        }
        // uid = (unsigned int)((tmp[4] & 0xff) << 24) + (unsigned int)((tmp[5] & 0xff) << 16) + (unsigned int)((tmp[6] & 0xff) << 8) + (unsigned int)(tmp[7]);

    }

}disk[maxn];

map<int, vector<Disk*>> M;

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &n, &m);
    uu(i, 0, n){
        char filename[maxname];
        sprintf(filename, "%d.dsk", i);
        disk[i].rdBasic(filename);
        #ifdef DEBUG
        uu(j, 0, 3){
            pf("b[%d]=%d ", i, disk[i].b[j]);
        }
        pf("seq=%d, strip size=%d, ncm of members=%d, manner=%d", 
        disk[i].seq, disk[i].stripesize, disk[i].num, disk[i].manner);
        pf(", id = ");
        pf("%d, ", disk[i].id);
        pf("uid=%u", disk[i].uid);
        pf("\n");
        #endif
    }
    uu(i, 0, n){
        M[disk[i].uid].push_back(&disk[i]);
    }

    for(const auto& it : M){
        pf("uid=%u, ", it.first);
        for(const auto & it2 : it.second){
            pf("seq=%d ", it2->seq);
        }
        pf("\n");

    }



    return 0;
}