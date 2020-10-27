bool spfa(int S){ // bellman-ford
    init(S);
    // N-1 round
    Q.push(S);
    bk[S] = 1;
    bk_time[S]++;
    while(!Q.empty()){
        int from = Q.front(); Q.pop();
        bk[from] = 0;

        for(const auto & edge : node[from].edge){
            int to = edge.to, newdis = dis[from] + edge.d;
            if(newdis < dis[to]){
                dis[to] = newdis;

                if(bk[to] == 0){
                    bk[to] = 1;
                    bk_time[to]++;
                    if(bk_time[to] > N+M) return false; // have negative cycle from S
                    Q.push(to);
                }
            }
        }
    }
    return true;
}