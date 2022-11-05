struct dsu{
    vector<int> parent;
    vector<int> siz;
    dsu(int n){
        siz = vector<int>(n,1);
        for(int i = 0; i < n; i++)
            parent.push_back(i);
    }
    int find(int a){
        if(parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(siz[a] < siz[b])
            swap(a,b);
        parent[b] = a;
        siz[a]+=siz[b];
        return true;

    }
};