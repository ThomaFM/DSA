ll modpow(ll b, ll p){
   ll ans = 1;
   while(p){
       if(p&1) ans = (ans*b) % mod;
       b = (b*b)%mod;
       p>>=1;
   }
   return ans;
}
