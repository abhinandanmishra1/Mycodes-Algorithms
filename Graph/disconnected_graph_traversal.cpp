#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges,int n,int *visited,int start=0){
    visited[start]=1;
    cout<<start+1<<endl;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[start][i]==1){
            printDFS(edges,n,visited,i);
        }
    }

}

void printBFS(int **edges,int n,int *visited,int start=0){
    visited[start]=1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        cout<<q.front()+1<<endl;
        int k=q.front();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[k][i]==1){
                q.push(i);
                visited[i]=1;
            }
        }
        q.pop();
    }
}

void DFS(int **edges,int n){
    int *visited=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,visited,i);
        }
    }

    delete[] visited;
}
void BFS(int **edges,int n){
    int *visited=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,visited,i);
        }
    }
    delete[] visited;
}

int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
    }

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        edges[x-1][y-1]=1;
        edges[y-1][x-1]=1;
    }
    cout<<"DFS :: \n";
    DFS(edges,n);
    cout<<"BFS :: \n";
    BFS(edges,n);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;

}
