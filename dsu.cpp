struct dsu{
   vector<int> par,siz;
   dsu(int n){
       siz = par = vector<int>(n,1);
       iota(par.begin(),par.end(),0);
   }
   int find(int a){
       if(par[a] != a) par[a] = find(par[a]);
       return par[a];
   }
   bool join(int a, int b){
       a = find(a); b = find(b);
       if(a == b) return false;
       if(siz[a] < siz[b]) swap(a,b);
       par[b] = a; siz[a]+=siz[b];
       return true;
   }
};
