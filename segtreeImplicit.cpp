//Implicit segment tree
struct ST{
   ll lo,hi,mid; 
   ll val;
   ST *left = nullptr; ST *right = nullptr;
   ST(int l, int r){
       lo = l; hi = r;
       mid = (lo+hi)/2;
       val = 0;
   }
   void check(){
       if(!left){
           left = new ST(lo,mid);
           right = new ST(mid+1,hi);
       }
   }
   ll query(ll l, ll r){
       if(r < lo || l > hi) return IDEMPOTENT_VALUE;
       if(l <= lo && hi <= r) return val;
       check();
       return merge(left->query(l,r),right->query(l,r))
   }
   void update(ll i, int v){
       if(lo == hi) return //void(“change val with v”);
       check();
       if(i<=mid) left->update(i,v);
       else right->update(i,v);
       val = merge(left->val,right->val);
   }
};
