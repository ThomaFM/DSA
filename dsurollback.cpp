struct dsuR{
    vector<int> sz,par; int comps;
    vector<tuple<int,int,int,int>> changes;
    dsuR(int n){
        sz = par = vector<int>(n,1); comps = n;
        iota(par.begin(),par.end(),0);
    }
    int find(int u){ if(par[u] != u) u = find(par[u]); return u; }
    int time(){ return changes.size();} dsuR(){}
    bool join(int u, int v){
        u = find(u); v = find(v); if(u==v) return false;
        if(sz[u] < sz[v]) swap(u,v); //u is now big dude
        changes.emplace_back(u,sz[u],v,par[v]); //store previous
        sz[u]+=sz[v]; par[v] = u; comps--; return true;
    }
    void rollback(int t){
        while((int)changes.size() != t){
            auto[a,oldsza,b,oldparb] = changes.back(); 
            changes.pop_back();
            sz[a] = oldsza; par[b] = oldparb; comps++;
        }
    }
};
