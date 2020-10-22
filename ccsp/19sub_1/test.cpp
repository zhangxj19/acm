#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1000000;
char types[N];
std::vector<std::vector<int>> edges(N);
int numsC[N], numsS[N], numsP[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", types);
    for(int i=0;i<m;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        edges[x].emplace_back(y);
        edges[y].emplace_back(x);
        numsC[x] += types[y]=='C'; numsC[y] += types[x]=='C';
        numsS[x] += types[y]=='S'; numsS[y] += types[x]=='S';
        numsP[x] += types[y]=='P'; numsP[y] += types[x]=='P';
    }
    for(int i=0;i<n;i++) std::sort(edges[i].begin(), edges[i].end());
    uint64_t num = 0;
    for(int i=0;i<n;i++)
    {
        int l = std::upper_bound(edges[i].begin(), edges[i].end(), i) - edges[i].begin();
        for(int j=0;j<l-1;j++)
        {
            int x = edges[i][j];
            for(int k=j+1;k<l;k++)
            {
                int y = edges[i][k];
                auto iter = std::lower_bound(edges[x].begin(), edges[x].end(), y);
                if(iter != edges[x].end() && *iter == y)
                {
                    int numC=2, numS=1, numP=1;
                    numC -= types[i]=='C'; numC -= types[x]=='C'; numC -= types[y]=='C';
                    numS -= types[i]=='S'; numS -= types[x]=='S'; numS -= types[y]=='S';
                    numP -= types[i]=='P'; numP -= types[x]=='P'; numP -= types[y]=='P';
                    if(numC < 0 || numS < 0 || numP < 0) continue;
                    if(numC) num += numsC[i] + numsC[x] + numsC[y] - 2;
                    if(numS) num += numsS[i] + numsS[x] + numsS[y];
                    if(numP) num += numsP[i] + numsP[x] + numsP[y];
                }
            }
        }
    }
    printf("%lu\n", num);
    return 0;
}
