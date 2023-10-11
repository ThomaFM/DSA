ll INF = 1e16; vector<int> path;
vector<tuple<int,int,ll>> edgelist; //u,v,w
vector<ll> dists(n,INF); //can be changed to n,0 to find all cycles
vector<int> par(n,-1); vector<bool> nCycle(n); 
dists[0] = 0; int cycleStart;
for(int i = 0; i < n; i++){
    cycleStart = -1;
    for(auto [u,v,w]: edgelist){
        if(dists[u] >= INF) continue;
        if(dists[u] + w < dists[v]){
            dists[v] = max(-INF,dists[u]+w);
            par[v] = u; cycleStart = v;
            if(i+1 == n) nCycle[v] = true;
        }
    }
} //if cycleStart == -1 no negative cycle
for(int i = 0; i < n; i++) cycleStart = par[cycleStart];
for(int cur = cycleStart; true; cur = par[cur]){
    path.push_back(cur); if(cur == cycleStart && path.size()>1) break;
} //don’t forget this bracket
reverse(path.begin(),path.end());
//for ssp from u -> v, dfs for reachable nodes of u, reachable nodes
//on rev edge graph for v see if any cycle node is reachable from both //to see if path is -inf
