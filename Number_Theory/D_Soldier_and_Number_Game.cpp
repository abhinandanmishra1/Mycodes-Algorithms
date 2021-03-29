/**
*!! Abhimanyu Bano !!
*!!कर्म करो फल की चिंता मत करो !!
* @Author  : Abhinandan Mishra
* @DateTime: 20-03-2021  02:14:58
*
**/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb        push_back
#define ppb       pop_back
#define pf        push_front
#define ppf       pop_front
#define all(x)    (x).begin(),(x).end()
#define uniq(v)   (v).erase(unique(all(v)),(v).end())
#define f        first
#define s        second
#define pll       pair<ll,ll>
#define vll        vector<ll>
#define vpll        vector<pair<ll,ll>>
#define mll          map<ll,ll>
#define umll          unordered_map<ll,ll>
#define usll          unordered_set<ll>
#define cerr if(false)cerr
#define debug(x) cerr<<'\n'<<(#x)<<" is "<<(x)<<endl;
#define sll          set<ll>
#define FILL(smallest_prime_div)         for(ll i=0,i<n;i++)cin>>smallest_prime_div[i];
#define fill(smallest_prime_div)         for(ll i=0,i<n;i++){ ll k; cin>>k;smallest_prime_div.pb(k); }
#define Print(smallest_prime_div)         for(ll i=0,i<n;i++)cout<<smallest_prime_div[i]<<' ';
#define charcountmap(s)         for(ll i=0,i<s.length();i++)mp[s[i]]++;
#define rep(n)   for(ll i=0;i<n;i++)
#define repe(i,a,b)   for(ll i=a;i<=b;i++)
#define mem1(a)      memset(a,-1,sizeof(a))
#define mem0(a)      memset(a,0,sizeof(a))
#define INF 100000000000000000
#define mod 1000000007
#define esp 10e-7
const int mx=1e5+7;
 //calling prime factorization

#define maxN 5000001
ll smallest_prime_div[maxN];
ll prime[maxN];
void sieve(){
    for(ll i=2;i<maxN;i++){
        if(smallest_prime_div[i]==0){
            for(ll j=i;j<maxN;j+=i){
                smallest_prime_div[j]=i;
            }
        }
    }
    
}
void primefactors(){
    prime[0]=prime[1]=0;
   for(ll j=2;j<maxN;j++){
       if(smallest_prime_div[j]!=j){
           prime[j]=prime[smallest_prime_div[j]]+prime[j/smallest_prime_div[j]];
       }else{
           prime[j]=1;
       }
       
   } 
   for(ll j=2;j<maxN;j++){
       prime[j]+=prime[j-1];
   }
}

// solve function


int main(){
    sieve();
    primefactors();
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll n=prime[a]-prime[b];
        printf("%lld\n",n);
    }

    return 0;
}