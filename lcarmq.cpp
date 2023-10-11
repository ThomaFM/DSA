//https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/RMQ.h
//Uses RMQ from kactl
//O(1) LCA
typedef vector<int> vi;
typedef pair<int,int> pii;
struct LCA{
   vi depth,pos; vector<pii> walk;
   void dfs(int u, int p, int d){
       depth[u] = d;
       pos[u]=walk.size();
       walk.emplace_back(d,u);
       for(auto v: adj[u]){
           if(v!=p){
               dfs(v,u,d+1);
               walk.emplace_back(d,u);
           }
       }
   }


   vector<vi> adj; RMQ<pii>*rmq;
   LCA(vector<vi> &g){
       adj=g; depth = pos = vi(g.size());
       dfs(0,-1,0);
       rmq = new RMQ<pii>(walk);
   }
   int lca(int u, int v){
       if(pos[u]>pos[v]) swap(u,v);
       return rmq->query(pos[u],pos[v]+1).second;
   }
   int dist(int u, int v) {return depth[u]+depth[v]-2*depth[lca(u,v)];}
};
