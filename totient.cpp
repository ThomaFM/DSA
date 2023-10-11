ll phi(ll n){
   ll ans = n;
   for(ll i = 2; i*i <= n; i++){
       bool f = 0;
       while(n % i == 0)
           f = (n /= i);
       if(f){ans-=(ans/i);}
   }
   if(n>1){ans-=ans/n;}
   return ans;
}
