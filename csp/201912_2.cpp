w#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>

typedef long long ll;

using namespace std;

int n, score[5];

struct Node{
    int x,y;
}nodes[1001];

map<ll, vector<Node>> M;


int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nodes[i].x >> nodes[i].y;
        ll b = nodes[i].y - nodes[i].x;
        M[b].push_back(nodes[i]);
    }
    for(int i = 0; i < n; i++){
        int cnt=0, cnt_s=0, x = nodes[i].x, y = nodes[i].y;
        // printf("now check (%d, %d)\n", x, y);
        ll b = y - x;
        vector<Node> b2=M[b+2], b1=M[b+1], b0=M[b], b_1=M[b-1], b_2=M[b-2];
        for(const auto & node: b1){
            // printf("b+1: (%d, %d) ", node.x, node.y);
            if(node.x == x-1 and node.y == y) cnt++;
            else if(node.x == x and node.y == y+1) cnt++;
        }
        // printf("\n");

        for(const auto &node : b_1){
            // printf("b-1: (%d, %d) ", node.x, node.y);
            if(node.x == x and node.y == y-1) cnt++;
            else if(node.x == x+1 and node.y == y) cnt++;
        }
        // printf("\n");
        // printf("cnt=%d\n",cnt);

        if(cnt == 4){
            // printf("(%d, %d) is ok to esteblish a trash can", x, y);
            for(const auto &node : b2){
                if(node.x == x-1 and node.y == y+1){
                    cnt_s++;
                    break;
                }
            }
            for(const auto & node: b0){
                if(node.x == x-1 and node.y == y-1) cnt_s++;
                else if(node.x == x+1 and node.y == y+1) cnt_s++;
            }
            for(const auto& node: b_2){
                if(node.x == x+1 and node.y == y-1){
                    cnt_s++;
                    break;
                }
            }
            score[cnt_s]++;
        }
    }

    for(const auto & i : score){
        cout << i << endl;
    }

}