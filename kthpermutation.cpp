//Lexigraphically Kth Permutation O(n^2)
vector<int> kthperm(int n, ll k){
   //0 indexed (k = 0 returns sorted array) //k > n! > 20! is bad
   vector<int> res; vector<int> order(n);
   vector<ll> fact(n+1,1);
   iota(order.begin(),order.end(),1);
   for(ll i = 2; i <=n; i++)
       fact[i] = fact[i-1] * i;
   for(int i = n-1; i>=0; i--){
       ll temp = k/fact[i];
       k%= fact[i];
       res.push_back(order[temp]);
       order.erase(order.begin()+temp);
   }
   return res;
}
