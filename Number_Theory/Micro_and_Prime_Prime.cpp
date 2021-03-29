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
#define FILL(arr)         for(ll i=0,i<n;i++)cin>>arr[i];
#define fill(arr)         for(ll i=0,i<n;i++){ ll k; cin>>k;arr.pb(k); }
#define Print(arr)         for(ll i=0,i<n;i++)cout<<arr[i]<<' ';
#define charcnmap(s)         for(ll i=0,i<s.length();i++)mp[s[i]]++;
#define rep(n)   for(ll i=0;i<n;i++)
#define repe(i,a,b)   for(ll i=a;i<=b;i++)
#define mem1(a)      memset(a,-1,sizeof(a))
#define mem0(a)      memset(a,0,sizeof(a))
#define INF 100000000000000000
#define mod 1000000007
#define maxN 1000001
#define esp 10e-7
const int mx=1e5+7;



ll gcd(ll a, ll b){
if (b == 0)
return a;
return gcd(b, a % b);
}
bool prime[maxN+1];
vll cn;
vll ans;
void seive(){
    prime[0]=prime[1]=true;
    for(ll i=2;i*i<=maxN;i++){
        if(!prime[i]){
            for(ll j=i*i;j<=maxN;j+=i){
                prime[j]=true;
            }
        }
    }
    ll k=0,st=0;
    ll prev=0;
    for(ll i=0;i<maxN;i++){
        if(!prime[i]){
            k++;
        }
        if(!prime[k] ){
            ans.pb(1);
        }else{
            ans.pb(0);
        }
        // if(!prime[st]){
        //     prev++;
        // }
    }
    repe(i,1,maxN){
        ans[i]+=ans[i-1];
    }

}
void solve(){
    ll l,r;
    cin>>l>>r;
    ll c=ans[r]-ans[l-1];
    
    cout<<c<<endl;
    // l=1;
    // r=100;
    // for(;l<r;l++){
    //     cout<<l<<" : "<<ans[l]<<"\n";
    // }
    
    // for(;l<=r;l++){
    //     ll cal=cn[l];
    //     if(!prime[cal]){
    //         c++;
    //     }
    // }


}

int main(){
    seive();
    ll t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}