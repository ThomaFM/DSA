//Find the max flow between source and sink
//worst case O(E*F), (Use Dinics if you need a faster flow algorithm)
typedef vector<int> vi;
typedef vector<bool> vb;
struct flowGraph{
   int INF = 1e9;
   vector<vi> cap; vb seen;
   int nodes, so, si;
   flowGraph(int n, int source, int sink){
       nodes = n; so = source; si = sink;
       cap = vector<vi>(n,vi(n,0));
       seen = vb(n);
   }
   void updateEdge(int i, int j, int c){ cap[i][j]+=c; }
   int dfs(int i, int flow, vb& seen){
       if(i == si) return flow;
       seen[i] = 1;
       for(int j = 0; j < nodes; j++){
           if(cap[i][j] && !seen[j]){
               if(int sent = dfs(j,min(flow,cap[i][j]),seen)){
                   cap[i][j] -= sent;
                   cap[j][i] += sent;
                   return sent;
               }
           }
       }
       return 0;
   }
   int maxflow(){
       int mf = 0, sent = -1;
       while(sent != 0){
           seen = vb(nodes);
           sent = dfs(so,INF,seen);
           mf += sent;
       }
       return mf;
   }
};
