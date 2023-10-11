//Persistent Segment returns a copy of the new segment tree for each update operation.
//O(log(n)) memory/timecomplexity for updates.
struct node{
   int lo,hi,mid;
   ll val;
   node *left; node *right;
   node(int l, int r){
       lo = l; hi = r;
       mid = (lo+hi)/2;
       val = vals[lo];
       if(l==r) return;
       left = new node(l,mid);
       right = new node(mid+1,r);
       val = left->val+right->val;
   }
   ll query(int l, int r){
       if(hi < l || r < lo) return 0;
       if(l <= lo && r >= hi) return val;
       return left->query(l,r)+right->query(l,r);
   }
   node(node *other){ *this = *other; }
   node* update(int i, ll x){
       node *res = new node(this);
       if(lo==hi){ res->val = x; return res;}
       if(i<=mid) res->left = left->update(i,x);
       else res->right = right->update(i,x);
       res->val = res->left->val + res->right->val;
       return res;
   }
};
