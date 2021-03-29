#include<iostream>
using namespace std;
void printDFS(int **edges,int n,int start,int *visited){
    cout<<start<<endl;
    visited[start]=1;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[start][i]==1){
            printDFS(edges,n,i,visited);
        }
    }
}
int main(){
   int n,e;
   cin>>n>>e;
   int **edges=new int*[n];
   for(int i=0;i<n;i++){
       edges[i]= new int[n];
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

   printDFS(edges,n,0,visited);

   for(int i=0;i<n;i++){
       delete[] edges[i];
   }
   delete[] edges;
   delete[] visited;

   return 0;
}
