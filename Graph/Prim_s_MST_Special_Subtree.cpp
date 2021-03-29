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

bool cmp(vi a1, vi a2)
{
    if (a1[2] != a2[2])
        return a1[2] < a2[2];
    else
        return a1[0] + a1[1] < a2[0] + a2[1];
}
int findminvertex(bool *visited, int *weight, int n)
{
    int minv = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minv == -1 || weight[i] < weight[minv]))
        {
            minv = i;
        }
    }
    return minv;
}
int prims(vector<vi> edges, int n, int e, int start)
{
    int parent[n];
    int weights[n];
    bool visited[n];

    rep(i, 0, n)
    {
        weights[i] = INT_MAX;
        visited[i] = false;
    }
    parent[start - 1] = -1;
    weights[start - 1] = 0;

    ll count = 0, edge = 0;
    while (edge < n - 1)
    {

        int minVertex = findminvertex(visited, weights, n);
        visited[minVertex] = true;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[minVertex][i] != -1)
            {
                if (weights[i] > edges[minVertex][i])
                {
                    weights[i] = edges[minVertex][i];

                    parent[i] = minVertex;
                }
            }
        }
        edge++;
    }
    rep(i, 0, n)
    {

        count += weights[i];
    }
    return count;
}
void solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edges[i][j]=-1;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (edges[x - 1][y - 1] != -1 )
        {
            edges[x - 1][y - 1] = edges[x - 1][y - 1]>w?w:edges[x - 1][y - 1];
            edges[y - 1][x - 1] = edges[x - 1][y - 1];
        }
        else
        {
            edges[x - 1][y - 1] = w;
            edges[y - 1][x - 1] = w;
        }
    }

    int start;
    cin >> start;
    cout << prims(edges, n, e, start);
}
int main()
{

    solve();
    return 0;
}
