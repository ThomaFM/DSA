//Functions for finding the smallest and largest triangles in a given set of pts.
ll smallestTriangle(vector<P> pts){
    sort(pts.begin(),pts.end());
    if(pts.size() < 3) return 1e18;
    typedef tuple<P,int,int> vinfo;
    vector<vinfo> vecs;
    int n = pts.size(); ll smallest = 1e18;
    vector<int> ind(n); iota(ind.begin(),ind.end(),0);
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            vecs.emplace_back(pts[j]-pts[i],i,j);

    sort(vecs.begin(),vecs.end(), [&](vinfo av, vinfo bv)->bool {
        P a = get<0>(av); P b = get<0>(bv);
        bool sideA = a.x > 0 || (a.x == 0 && a.y > 0);
        bool sideB = b.x > 0 || (b.x == 0 && b.y > 0);
        if(sideA != sideB) return sideA;
        return a.cross(b) > 0;
    });

    for(auto[p,aorig,borig]: vecs){
        int a = ind[aorig]; int b = ind[borig];
        int le = min(a,b)-1; int ri = max(a,b)+1;
        if(le >= 0) smallest = min(smallest,abs(pts[le].cross(pts[a],pts[b])));
        if(ri != n) smallest = min(smallest,abs(pts[ri].cross(pts[a],pts[b])));
        swap(pts[a],pts[b]); swap(ind[aorig],ind[borig]);
    }
    
    return smallest;
}

ll largestTriangle(const vector<P> &pts){
    vector<P> hull = convexHull(pts);
    int hs = hull.size(); if(hs < 3) return 0;
    auto area = [&](int a, int b, int c){ return hull[a].cross(hull[b],hull[c]); };
    auto next = [&](int x) {return (x+1 == hs) ? 0 : x+1; };
    int a = 0; int b = next(a); int c = next(b);
    ll largest = hull[a].cross(hull[b],hull[c]);
    while(true){
        while(a!=c){
            while(area(a,b,next(c)) >= area(a,b,c)) c = next(c);
            if(area(a,b,c) >= largest) largest = area(a,b,c);
            b = next(b);
        }
        a = next(a); if(!a) break;
        b = next(a); c = next(b); // readline carefully
    }
    return largest;
}
