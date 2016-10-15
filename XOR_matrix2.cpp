#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int n,m, temp;
    cin>>n>>m;
    long long int Ap[n];
    long long int An[n];
    for(int i = 0; i < n; ++i){
       cin>>Ap[i];
    }
    if(m % 2 == 0){
        if(m == 1){
            for(int j = 0; j < n; ++j){
                An[j] = Ap[j];
            }
        }
        else if(m < n){
            for(int j = 0; j < n; ++j){
                An[j] = Ap[j]^Ap[(j+m-1) % n];
            }
        }
        else if(m == n){
            temp = Ap[0];
            for(int j = 1; j < n; ++j){
                temp = temp^Ap[j];
            }
            for(int j = 0; j < n; ++j){
                An[j] = temp;
            }
        }
        else{
            for(int j = 0; j < n; ++j){
                An[j] = 0;
            }
        }
    }
    else{
        for(int j = 0; j < n; ++j){
                An[j] = Ap[j]^Ap[(j+m-1) % n];
            }
    }
    for(int j = 0; j < n; ++j){
       cout<<An[j]<<" ";
    }
    cout<<endl;
    return 0;
}
