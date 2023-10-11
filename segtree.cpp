//IDEMPOTENT_VALUE is a placeholder for the value such that merge(x,IDEMPOTENT_VALUE) = x
//This will change for different operations, for example, range product would use 1 as the idempotent value, and range min would use INFINITY.
//merge is a placeholder function for any operation you want to use (sum,min,max,gcd,bitwise,etc). It is NOT the STL Merge function.
struct node{
   int lo,hi,mid,val;
   node *left; node *right;
   node(int l, int r){
       lo = l; hi = r;
       mid = (lo+hi)/2;
       val = IDEMPOTENT_VALUE;
       if(l==r) return;
       left = new node(l,mid);
       right = new node(mid+1,r);
   }
   int query(int l, int r){
       if(l>hi||r<lo) return IDEMPOTENT_VALUE;
       if(l<=lo&&hi<=r) return val;
       return merge(left->query(l,r),right->query(l,r));
   }
   void update(int i){
       if(lo==hi) return void(val++);
       if(i<=mid) left->update(i);
       else right->update(i);
       val = merge(left->val,right->val);
   }
};


