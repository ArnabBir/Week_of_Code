#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int n,m, temp;
    cin>>n>>m;
    vector<vector<long long int>> Ap(m, vector<long long int>(n));
    for(vector<long long int>::iterator itr = Ap[0].begin(); itr != Ap[0].end(); ++itr){
       cin>>*itr;
    }
    for(int i = 1; i < m; ++i){
        for(int j = 0; j < n - 1; ++j){
            Ap[i][j] = Ap[i-1][j]^Ap[i-1][j+1];
        }
        Ap[i][n-1] = Ap[i-1][n-1]^Ap[i-1][0];
    }
    for(vector<long long int>::iterator itr = Ap[m-1].begin(); itr != Ap[m-1].end(); ++itr){
       cout<<*itr<<" ";
    }
    cout<<endl;
    return 0;
}
