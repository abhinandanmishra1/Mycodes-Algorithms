#include<iostream>
#include<queue>
using namespace std;

void printBFS(int **edges,int n,int s,int *visited){
     queue<int> q;
     q.push(s);
     visited[s]=1;
     
     while(!q.empty()){
         int cur_ind=q.front();
         cout<<cur_ind<<endl;
         q.pop();
         for(int i=0;i<n;i++){ 
           if(!visited[i] && edges[cur_ind][i]==1){
             q.push(i);     
             visited[i]=1;
         }
         }
     }

     
}

int main(){
    int n,e;
    cin>>n>>e;

    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
   int *visited=new int[n];
   for(int i=0;i<n;i++){
       visited[i]=0;
   }

   printBFS(edges,n,0,visited);
   delete[] visited;
   for(int i=0;i<n;i++){
       delete[] edges[i];
   }
   delete[] edges;
   return 0;
}
