/*
    Tested my knowledge of DFS and BFS;
    I succeeded;
    Notes:: making
    Queue is need when priority matters;
    when we have to goo deep go recursively;

*/

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

void printDFS(int **edges,int n,int *visited,int start=0){
        cout<<start+1<<endl;
        visited[start]=1; //mark kr lo ki isko dekh liya hu 
        //wrna bar bar yahi chalega

        //uske bad is index se sare connected index pe jao 
        //agar wo phle se nahi dekha gaya ho to call kar do function
        //ko us index pe
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[start][i]==1){
                //check kro kya start ke adjacent hai 
                //and not visited
                //then recursion
                  printDFS(edges,n,visited,i);
            }
        }
}
void printBFS(int **edges,int n,int *visited,int start=0){
    //BFS is also good 
    //we need priority here 
    //ise phle print kro use baad me
    //that's why we use queue

    visited[start]=1;  //ate hi mark kro ise queue bnao aur push kro
    queue<int> q;
    q.push(start);
    while (!q.empty())
     //tab tak loop chalao jab tak queue khali na ho jaye
     //aage pushh bhi krna hai
     //jitne bhi index queue ke first element ke adjacent hain unhe
     //queue me push mar do 
     //har bar sbse aage wale ko print krna hai aur pop mar dena hai
    {   int k=q.front();
        cout<<q.front()+1<<endl;
        for(int i=0;i<n;i++){
           if(!visited[i] && edges[k][i]==1){
               q.push(i);
            //    cout<<1;
               visited[i]=1;
           }
        }
        q.pop();

        //like ek graph hai 
        //               1
        //             /  \
        //            2    3
        //               /   \
        //              4     6
        //                   / 
        //                  5 
        // iska answer hoga 1 2 3 4 6 5
    //     sbse phle queue me 1 ko dal diya 
    //     ab print(q.front()) "q.front() =1" and q.pop() and queue me 1 ke adjacents 
    //     ko push maro  q={2,3}

    //     again print(q.front()) "q.front() =2"  and q.pop()  aur 2 ke adjacent 
    //     ko push maro   q={3}

    //     same thing print(3)->q.pop()->q={4,6}
    //     print(4)->q.pop()->q={6}
    //     print(6)->q.pop()->q={5}
    //     print(5)->q.pop()->q={}   q is empty now "loop is ended here"
    //
     }
    
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    rep(i,0,n){
        edges[i]=new int[n];
    }

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        edges[x-1][y-1]=edges[y-1][x-1]=1;
    }

    int *visited=new int[n];
    rep(i,0,n){
        visited[i]=0;
    }
    cout<<"BFS::\n";

    printBFS(edges,n,visited);
    rep(i,0,n){
        visited[i]=0;
    }
    cout<<"\nDFS::\n";
    printDFS(edges,n,visited);
    

    //clear all memory

    delete[] visited;
    rep(i,0,n){
        delete[] edges[i];
    }
    delete[] edges ;
    return 0;

}