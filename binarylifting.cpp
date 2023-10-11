//lca in O(lgn) with binary lifting.
typedef vector<int> vi;
typedef vector<vi> vii;
struct bl{
   vii g, jmp;
   vi dep; int n;
   bl(vii &graph){
       g = graph; n = g.size(); dep = vi(n);
       jmp = vii( __lg(n)+1,vi(n));
       dfs(0,0,0);
   }
   void dfs(int u, int p, int d){
       jmp[0][u] = p; dep[u] = d;
       for(int i = 1; i < (int)jmp.size(); i++)
           jmp[i][u] = jmp[i-1][jmp[i-1][u]];
       for(auto v: g[u]) if(v != p) dfs(v,u,d+1);
   }   
   int kth(int u, int k){
       for(int i = 0; i < (int)jmp.size(); i++)
           if(k & (1<<i)) u = jmp[i][u];
       return u;
   }
   int lca(int u, int v){
       if(dep[u] > dep[v]) swap(u,v); //v is now deeper
       v = kth(v,dep[v]-dep[u]); if(u==v) return u;
       for(int i = (int)jmp.size()-1; i>=0; i--){
           if(jmp[i][u] != jmp[i][v]){
               u = jmp[i][u];
               v = jmp[i][v];
           }
       }
       return jmp[0][u];
   }
};
