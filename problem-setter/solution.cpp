#include <bits/stdc++.h>
using namespace std;

long long max_profit(int *prices,int n){
    long long profit=0;
        int i=0;
        while(i<n-1){
            if(prices[i]<prices[i+1]){
                profit+=prices[i+1]-prices[i];
            }
            i++;
        }
        return profit;
}
int main(){
    int N;
    cin>>N;
    int prices[N];
    for(int i=0;i<N;i++){
        cin>>prices[i];
    }
    cout<<max_profit(prices,N);

    return 0;

}