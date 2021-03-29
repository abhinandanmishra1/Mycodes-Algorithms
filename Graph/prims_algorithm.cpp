//solve it 
//this is not prims
//this is copied from kruskal algorithm code
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2){
    return p1.second<p2.second;
}
int findParent(int x,int * parent){
    if(parent[x]==x){
        return x;
    }
    return findParent(parent[x],parent);
}

void kruskals(vector<pair<pair<int,int>,int>> edges,int n){
    vector<pair<pair<int,int>,int>> output;

    int count =0;
    int i=0;
    int * parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
        
    }
    while(count!=n-1){
        
      pair<pair<int,int>,int> input=edges[i];
      
      int sourceParent=findParent(input.first.first,parent);
      int destParent=findParent(input.first.second,parent);

      if(destParent!=sourceParent){
          output.push_back(input);
          count++;
          parent[sourceParent]=destParent;
      }
      i++;

    }
    cout<<"MST ->\n";

    for(auto x:output){
        if(x.first.first<x.first.second)
        cout<<x.first.first<<"--"<<x.first.second<<"::"<<x.second<<endl;
        else
        cout<<x.first.second<<"--"<<x.first.first<<"::"<<x.second<<endl;
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<pair<int,int>,int>> edges;
    for(int i=0;i<e;i++){
        int k,l,w;
        cin>>k>>l>>w;
        edges.push_back({{k,l},w});
    }
    sort(edges.begin(),edges.end(),cmp);
    kruskals(edges,n);
   
    
    

    return 0;
}