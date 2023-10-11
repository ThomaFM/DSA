queue<int> q; 
vector<int> ordering; 
vector<int> indegree(n,0);
//priority_queue<int, vector<int>, greater<int>> q; //for lexic minimal
for(auto u: graph) for(auto v: u) indegree[v]++;
for(int i = 0; i < n; i++) if(!indegree[i]) q.push(i);
while(!q.empty()){
   int u = q.front(); q.pop();
   ordering.push_back(u);
   for(auto v: graph[u]){
       if(--indegree[v] == 0) q.push(v);
   }
} //if ordering.size() != # nodes no valid ordering
