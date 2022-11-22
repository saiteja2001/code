#include<bits/stdc++.h>
using namespace std;
struct Item{
    double value;
    double weight;
};

bool comp(Item a,Item b){
    double A = a.value/a.weight;
    double B = b.value/b.weight;
    return A>B;
}

int knapsack(Item arr[],int n,double W){
    sort(arr,arr+n,comp);

    double tot_val=0;

    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            W-=arr[i].weight;
            tot_val+=arr[i].value;
        }
        else{
            tot_val+=((W/arr[i].weight)*arr[i].value);
            break;
        }
    }
    return tot_val;
}



int main(){
    Item arr[]={
        { 60, 10 }, 
        { 100, 20 }, 
        { 120, 30 }
    };

    int n=sizeof(arr)/sizeof(arr[0]);
    double W;
    cin>>W;
    cout<<knapsack(arr,n,W);

}