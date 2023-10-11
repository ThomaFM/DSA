struct node{
    int lo, hi, mid;
    ll val,delta;
    node *left; node *right;
    node(int l, int r){
        lo = l; hi = r; mid = (lo+hi)/2;
        val = delta = 0;
        if(lo==hi) return;
        left = new node(l,mid);
        right = new node(mid+1,r);
    }


    void prop(){
        left->delta +=delta; 
        right->delta +=delta;
        delta = 0;
    }

    ll value(){ return val+(delta*(hi-lo+1)); }
    ll merge(ll left, ll right){ return left+right; }
    ll query(int l, int r){
        if(l>hi||r<lo) return 0;
        if(l<=lo&&hi<=r) return value();
        prop(); 
        val = merge(left->value(),right->value());
        return left->query(l,r)+right->query(l,r);
    }


    void update(int l, int r, int v){
        if(l>hi||r<lo) return;
        if(l<=lo&&hi<=r) return void(delta+=v);
        prop();
        left->update(l,r,v); right->update(l,r,v);
        val = merge(left->value(),right->value());
    }
};
