//Given a tree find query what the minimum edge weight on
//the path between u and v.
typedef vector<int> vi; 
typedef vector<vi> vii;
typedef vector<vector<pair<int,int>>> vpi;
struct bl{
   vpi g; vii jmp; vi dep; int n; vii mi;
   bl(vpi &graph){
       g = graph; n = g.size(); dep = vi(n);
       mi = jmp = vii( __lg(n)+1,vi(n)); dfs(0,0,0,0);
   }
   void dfs(int u, int p, int d,int ew){
       jmp[0][u] = p; dep[u] = d; mi[0][u] = ew;
       for(int i = 1; i < (int)jmp.size(); i++){
           jmp[i][u] = jmp[i-1][jmp[i-1][u]];
           mi[i][u] = min(mi[i-1][u],mi[i-1][jmp[i-1][u]]);
       }
       for(auto [v,w]: g[u]) if(v != p) dfs(v,u,d+1,w);
   }   
   pair<int,int> kth(int u, int k){
       int res = INT_MAX;
       for(int i = 0; i < (int)jmp.size(); i++)
           if(k & (1<<i)){
               res = min(res,mi[i][u]); u = jmp[i][u];
           }
       return {u,res};
   }
   int smallest(int u, int v){
       int lc = lca(u,v);
       int ju = dep[u]-dep[lc]; int jv = dep[v]-dep[lc];
       return min(kth(u,ju).second,kth(v,jv).second);
   }
   int lca(int u, int v){
       if(dep[u] > dep[v]) swap(u,v);
       v = kth(v,dep[v]-dep[u]).first; if(u==v) return u;
       for(int i = (int)jmp.size()-1; i>=0; i--)
           if(jmp[i][u] != jmp[i][v])
               u = jmp[i][u], v = jmp[i][v];
       return jmp[0][u];
   }
};
