#include<bits/stdc++.h>
using namespace std;
void print(int **Q,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;i++){
            cout<<Q[i][j]<<"-";
        }
        cout<<"\n";
    }
}

bool safe(int **Q,int x,int y,int n){
    for(int i=0;i<x;i++){
        if(Q[i][y]==1){
            return false;
        }
    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(Q[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(Q[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    
    return true;
}

void fill_queen(int** Q,int x,int n){
    if(x==n){
        print(Q,n);
    }
    
    for(int i=0;i<n;i++){
        if(safe(Q,x,i,n)){
            Q[x][i]=1;
            fill_queen(Q,x+1,n);
            Q[x][i]=0;

        }
    }
    
}

int main(){

    int n;
    cin>>n;

    int **Q=new int*[n];
    for(int i=0;i<n;i++){
        Q[i]=new int[n];
        for(int j=0;j<n;j++){
            Q[i][j]=0;
        }
    }
    fill_queen(Q,0,n);
    
}