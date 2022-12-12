#include <bits/stdc++.h>
using namespace std;
struct ST{
    int IDEM = ???; //Neutral (Idempotent) value that will not effect result
    int lo,hi,mid;
    int val;
    ST *left; ST *right;
    ST(int l, int r){
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = IDEM;
        if(l==r) return;
        left = new st(l,mid);
        right = new st(mid+1,r);
    }

    int query(int l, int r){
        if(r < lo || l  >  hi) return IDEM; //no cover
        if(l <= lo && hi <= r) return val; //full cover
        int leftAns = left->query(l,r);
        int rightAns = right->query(l,r);
        return func(leftAns,rightAns); //function/operation could be many options
    }

    void update(int i, int v){
        if(lo == hi){
            val = v;
            return;
        }
        if(i <= mid){
            left->update(i,v);
        }else{
            right->update(i,v);
        }
        val = func(left->val,right->val); //same function/operation
    }
};

//Example usage
ST mysegtree = ST(0,n); //creation 
for(int i = 0; i < n; i++){
    //get new val each loop
    mysegtree.update(i,val); //updating each "index" with a value
}

//Query
int val = st.query(a,b); //inclusive,inclusive

