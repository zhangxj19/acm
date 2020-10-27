bool spfa(int S){
    init(S);
    Q.push(S);
    bk[S] = 1;
    bk_time[S]++;
    while(!Q.empty()){
        int from = Q.front(); Q.pop();
        bk[from] = 0; // !!!!!from not in the queue
        uu(i, 0, node[from].edge.size()){
            int to = node[from].edge[i].to, newdis = node[from].edge[i].d + dis[from];
            if(newdis < dis[to]){
                dis[to] = newdis;
                if(bk[to] == 0){
                    Q.push(to);
                    bk[to] = 1;
                    bk_time[to]++;
                    if(bk_time[to] > (N+M+1)) return false;
                }
            }
        }

    }
    return true;
}