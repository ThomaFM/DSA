//Written by Thomas Meeks
//BFS with Path Reconstruction - 0 Based
//graph is adjecency list vector<vector<int>> 
//graph[u] = List of Nodes connected to u
//nodes = #number of nodes in graph i.e graph.size()
//source is source node

vector<bool> vis(nodes);
vector<int> prev(nodes,-1);
queue<int> q;
vis[source] = true;
q.push(source);

while(!q.empty()){
    int u = q.front(); q.pop();
    for(auto v: graph[u]){
        if(!vis[v]){
            vis[v] = true;
            prev[v] = u;
            q.push(v);
        }
    }
}

vector<int> path;
for(int at = nodes-1; at != -1; at = prev[at]){
    path.push_back(at);
}

reverse(path.begin(),path.end());
//if path[0] != source NO PATH
