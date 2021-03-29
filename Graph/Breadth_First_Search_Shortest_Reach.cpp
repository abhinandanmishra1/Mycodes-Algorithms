#include <bits/stdc++.h>

using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define ll long long

#define pb push_back

#define ppb pop_back

#define pf push_front

#define ppf pop_front

#define all(x) (x).begin(), (x).end()

#define uniq(v) (v).erase(unique(all(v)), (v).end())

#define ff first

#define ss second

#define pii pair<int, int>

#define vi vector<int>

#define vpi vector<pair<int, int>>

#define mii map<int, int>

#define rep(i, a, b) for (int i = a; i < b; i++)

#define repe(i, a, b) for (int i = a; i <= b; i++)

#define mem1(a) memset(a, -1, sizeof(a))

#define mem0(a) memset(a, 0, sizeof(a))

#define ppc __builtin_popcount

#define ppcll __builtin_popcountll

#define INF 100000000000000000

#define mod 1000000007

#define esp 10e-7

const int mx = 1e5 + 7;
void BFS(int **edges,int n,int e,int start){
    int output[n];
    
    queue<int> q;
    bool visited[n];
    rep(i,0,n){
        visited[i]=false;
        output[i]=-1;
    }
    q.push(start);
    output[start]=0;
    visited[start]=true;
    int count=6;
    while (!q.empty())
    {
        int first=q.front();
        q.pop();
        bool crack=false;
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[first][i]){
                visited[i]=true;
                output[i]=count+output[first];
                q.push(i);
                crack=true;
            }
        }
        
    }

    for(int i=0;i<n;i++){
        int x=output[i];
        if(x!=0){
            cout<<x<<" ";
        }
    }
    cout<<endl;

    

}
void solve()
{
    int n, m;
    cin >> n >> m;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int k, l;
        cin >> k >> l;
        edges[k-1][l-1]=1;
        edges[l-1][k-1]=1;
    }
    int start;
    cin>>start;
    BFS(edges,n,m,start-1);

    rep(i,0,n){
        delete[] edges[i];
    }
    delete[] edges;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}