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

#define MAXN 10000000

const int mx=1e5+7;
int *spf=new int[MAXN];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
    
        spf[i] = i; 
  
    
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
  
               
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
int main(){

    int t;
    cin>>t;
    sieve();
    while(t--){
        ll l,r;
        ll count=0;
        cin>>l>>r;
        rep(i,l,r){
            int x=spf[i];
            if(spf[x]==1){
                count++;
            }
        }

        cout<<count<<endl;


    }
    return 0;

}