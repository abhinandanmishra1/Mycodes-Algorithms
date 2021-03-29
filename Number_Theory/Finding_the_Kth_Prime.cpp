/**
*!! Abhimanyu Bano !!
*!!कर्म करो फल की चिंता मत करो !!
* @Author  : Abhinandan Mishra
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
#define sll          set<ll>
#define FILL(arr)         rep(n)cin>>arr[i];
#define fill(arr)         for(ll i=0,i<n;i++){ ll k; cin>>k;arr.pb(k); }
#define Print(arr)         for(ll i=0,i<n;i++)cout<<arr[i]<<' ';
#define charcountmap(s)         for(ll i=0,i<s.length();i++)mp[s[i]]++;
#define rep(n)   for(ll i=0;i<n;i++)
#define repe(i,a,b)   for(ll i=a;i<=b;i++)
#define mem1(a)      memset(a,-1,sizeof(a))
#define mem0(a)      memset(a,0,sizeof(a))
#define INF 100000000000000000
#define mod 1000000007
#define esp 10e-7
#define maxN 90000000
const int mx=1e5+7;


ll gcd(ll a, ll b){
if (b == 0)
return a;
return gcd(b, a % b);
}
bool arr[maxN];
vll prime;
void seive(){
    
    arr[0]=true;
    arr[1]=true;
   
    for(ll i=2;i*i<=maxN;i++){
        if(!arr[i]){
            for(ll j=i*i;j<maxN;j+=i){
                arr[j]=true;
            }
        }
    }
    rep(maxN){
        if(!arr[i])
        prime.pb(i);
    }
}

void solve(){
    ll n;
    cin>>n;
    cout<<prime[n-1]<<endl;

}

int main(){
    ll t;cin>>t;
    seive();
    
    while(t--){
        solve();
    }

    return 0;
}