#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

struct Job{
    char id;
    int dead;
    int money;
};

bool comp(Job a,Job b){
    return a.money>b.money;
}

void job_seq(Job arr[],int n){
    sort(arr,arr+n,comp);
    int tot=0;
    int result[n];
    bool busy[n];

    for(int i=0;i<n;i++){
        busy[i]=false;
    }

    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead);j>0;j--){
            if(busy[j]==false){
                busy[j]=true;
                result[j]=i;
                tot+=arr[i].money;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(busy[i]){
            cout<<arr[result[i]].id<<" ";
        }
        cout<<"\n";
    }
    cout<<"total profit "<<tot;
}

int main(){
    Job arr[] = {
        { 'a', 2, 100 },
        { 'b', 1, 19 },
        { 'c', 2, 27 },
        { 'd', 1, 25 },
        { 'e', 3, 15 }
    };
    int n = sizeof(arr)/sizeof(arr[0]);

    job_seq(arr,n);


}