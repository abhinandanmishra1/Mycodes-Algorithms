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

    string s1,s2;
    cin>>s1>>s2;

    ll a=count(all(s2),'0');
    ll b=s2.length()-a;
    ll t=s1.length();
    vector<pair<ll,ll>> v;
    for(int x=1;x<t/a;x++){
        pair<ll,ll> p;
        ll k=t-a*x;
        if((k)%b==0){
            p.first=x;
            p.second=k/b;
        }
        
    }

     
            if(s2[0]=='0' && s2[1]=='1' ){
                 for(auto x:v){
                     
                 }
            }
            else if(s2[0]=='1' && s2[1]=='0' ){
                 for(auto x:v){
                     if((s1.substr(0,x.first))!=( s1.substr(x.first,x.first))){

                     }
                 }
            }
            else if(s2[0]=='0' && s2[1]=='0' ){
                 
            }
            else{
             
            }
        
    


    return 0;

}