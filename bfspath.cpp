//Written by Thomas Meeks
//BFS with Path Reconstruction - 0 Based
//graph is adjacency list vector<vector<int>> 
//graph[u] = List of Nodes connected to u
//nodes = #number of nodes in graph i.e graph.size()
//source is the source node
vector<int> dist(n,-1);
vector<int> par(n,-1);
queue<int> q; q.push(source);
dist[source] = 0;
while(!q.empty()){
   int u = q.front(); q.pop();
   for(auto v: graph[u]){
       if(dist[v] != -1) continue;
       dist[v] = dist[u] + 1;
       par[v] = u; //Path Build back
       q.push(v);
   }
}

//Path build back, if path[0] != source NO PATH
vector<int> path;
for(int at = sink; at != -1; at = par[at]) path.push_back(at);
reverse(path.begin(),path.end());
