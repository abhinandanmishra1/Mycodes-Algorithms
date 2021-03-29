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

#define ff        first

#define ss        second

#define pii       pair<int,int>

#define vi        vector<int>

#define vpi       vector<pair<int,int>>

#define mii          map<int,int>

#define rep(i,a,b)   for(int i=a;i<b;i++)

#define repe(i,a,b)   for(int i=a;i<=b;i++)

#define mem1(a)      memset(a,-1,sizeof(a))

#define mem0(a)      memset(a,0,sizeof(a))

#define ppc          __builtin_popcount

#define ppcll        __builtin_popcountll

#define INF 100000000000000000

#define mod 1000000007

#define esp 10e-7

const int mx=1e5+7;

int main(){
    int n;
    cin>>n;
    ll arr[n];
    rep(i,0,n){
        cin>>arr[i];
    }
    
    ll s1[n],s2[n];
    s1[0]=arr[0];
    s2[n-1]=arr[n-1];
    rep(i,1,n){
        s1[i]=s1[i-1]+arr[i];
    }
    for(int i=n-2;i>=0;i--){
        s2[i]=s2[i+1]+arr[i];
    }

    ll t=s1[n-1];
    ll diff=INT_MAX;
    for(int i=0;i<n-1;i++){
       diff=min(diff,abs(s1[i]-s2[i+1]));
    }

    cout<<diff;

    

    return 0;

}