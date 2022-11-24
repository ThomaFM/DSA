#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> sieve(int n){
    vector<bool> ip(n+1,true);
    ip[0] = ip[1] = false;
    for(ll i = 2; i <= n; i++){
        if(ip[i] && i*i <=n){
            for(int j = i*i; j <= n; j+=i) ip[j] = false;
        }
    }
    return ip;
}

//Usage
//vector<int> isprime = sieve(num);
