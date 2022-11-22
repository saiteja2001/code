#include<iostream>
#include<vector>
using namespace std;

void fib(int n){
    vector<int>f;
    f.push_back(1);
    f.push_back(1);
    int count=2;
    for(int i=2;i<n;i++){
        count++;
        f.push_back(f[i-2]+f[i-1]);
    }

    for(int i=0;i<n;i++){
        cout<<f[i]<<" ";
    }
}

int step=0;
int fib_rec(int n){
    step++;
    if(n<=2){
        return 1;
    }
    return fib_rec(n-2)+fib_rec(n-1);
}

int main(){
    cout<<"enter the number of digits needed:";
    int n;
    cin>>n;
    fib(n);
    cout<<"\n";
    cout<<"steps required by iteration:"<<n<<"\n";
    cout<<"fibonacci value:"<<fib_rec(n)<<"\n";
    cout<<"steps required by recursive:"<<step<<"\n";
}