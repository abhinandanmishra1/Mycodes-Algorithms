/**
*!! Abhimanyu Bano !!
*!!कर्म करो फल की चिंता मत करो !!
* @Author  : Abhinandan Mishra
* @DateTime: 29-03-2021  20:37:24
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
#define charcountmap(s)         for(ll i=0,i<s.length();i++)mp[s[i]]++;
#define rep(n)   for(ll i=0;i<n;i++)
#define repe(i,a,b)   for(ll i=a;i<b;i++)
#define mem1(a)      memset(a,-1,sizeof(a))
#define mem0(a)      memset(a,0,sizeof(a))
#define INF 100000000000000000
#define mod 1000000007
#define esp 10e-7
const int mx=1e5+7;


ll gcd(ll a, ll b){
if (b == 0)
return a;
return gcd(b, a % b);
}
// void matrix_input(ll n,ll **arr){
//     repe(i,0,n){
//         repe(j,0,n){
//             cin>>arr[i][j];
//         }
//     }
// }
void print_2d(ll n,ll **arr){
    cout<<endl;
    repe(i,0,n){
        repe(j,0,n){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void mul(ll **I,ll **arr,ll n){
    ll store[n][n];
    repe(i,0,n){
        repe(j,0,n){
            store[i][j]=0;
            repe(k,0,n){
                store[i][j]+=(I[i][k]*arr[k][j]);
            }
        }
    }
    repe(i,0,n){
        repe(j,0,n){
            I[i][j]=store[i][j];
        }
    }
}
void matrix_pow(ll **arr,ll n,ll m){
    ll **I=new ll*[n];
    repe(i,0,n){
        I[i]=new ll[n];
        repe(j,0,n){
            if(i==j){
                I[i][j]=1;
            }else{
                I[i][j]=0;
            }
        }
    }
    //exponents
    while(m){
        if(m%2){
            mul(I,arr,n);
            m--;
        }else{
            mul(arr,arr,n);
            m/=2;
        }
    }
     repe(i,0,n){
        repe(j,0,n){
            arr[i][j]=I[i][j];
        }
    }

}
void solve(){
    ll n;
    cin>>n;
    ll **arr=new ll*[n];
    rep(n){
        arr[i]=new ll[n];
    }
    repe(i,0,n){
        repe(j,0,n){
            cin>>arr[i][j];
        }
    }
    print_2d(n,arr);
    ll m;
    cin>>m;
    matrix_pow(arr,n,m);
    print_2d(n,arr);
}

int main(){
    ll t=1;
    while(t--){
        solve();
    }

    return 0;
}