//graph is vector<vector<pair<int,weight data type>>>
//nodes - > #nodes
typedef long long ll;
typedef pair<ll,int> pli;
ll INF = 1e15;
priority_queue<pli,vector<pli>,greater<pli>> pq;
vector<ll> dist(nodes,INF);
vector<int> par(nodes,-1); //path buildback
dist[source] = 0;
pq.emplace(0,source);
while(!pq.empty()){
    auto[cost,u] = pq.top(); pq.pop();
    if(cost > dist[u]) continue;
    for(auto[v, w]: graph[u]){
        if(cost+w < dist[v]){
            dist[v] = cost+w;
            pq.emplace(cost+w,v);
            par[v] = u; //path buildback
        }
    }
}

//Buildback path
vector<int> path;
for(int at = nodes-1; at != -1; at = par[at]){
    path.push_back(at);
}

reverse(path.begin(),path.end());
//if path[0] != source, no path
