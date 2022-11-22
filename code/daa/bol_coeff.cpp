#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    int C[n+1][k+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<=min(i,k);j++){
            if(i==j || j==0){
                C[i][j]=1;
            }
            else{
                C[i][j]=C[i-1][j-1]+C[i-1][j];
            }
        }
    }
    cout<<C[n][k];
}