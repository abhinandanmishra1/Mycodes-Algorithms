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

bool cmp(vi a1,vi a2){
    if(a1[2]!=a2[2])
    return a1[2]<a2[2];
    else
    return a1[0]+a1[1]<a2[0]+a2[1]; 
}
int findparent(int x,int *parent){
    if(parent[x]==x){
        return x;
    }
    return findparent(parent[x],parent);
}
int kruskal(vector<vi> edges,int n,int e){
    int parent[n];
    
    rep(i,0,n){
        parent[i]=i;    
    }

    int count=0,edge=0,i=0;
    while(edge!=n-1){
        vi input=edges[i];
        int firstP=findparent(input[0]-1,parent);
        int secondP=findparent(input[1]-1,parent);
       
        if(firstP !=secondP){
                count+=input[2];
                
                parent[firstP]=secondP;
                edge++;
        }
        i++;
    }
    return count;
}
void solve(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges.pb({x,y,w});
    }
    sort(all(edges),cmp);
    cout<<kruskal(edges,n,e);
}
int main(){

    solve();
    return 0;

}