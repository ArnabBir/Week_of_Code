#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;

string makeHappy(char b[], int n, int _Count){
    bool flag = true;
    int pos = 0;
    for(int pos = 1; pos < n - 1; pos += 2){
        if(b[pos] != '_')
            if(b[pos] != b[pos-1] && b[pos] != b[pos+1]){
                flag = false;
                break;
            }
    }
    if(flag) return "YES";
    //swap(b[pos], b[find(b,b + n, '_' )]);
    if(_Count == 0) return "NO";
    else return "YES";
}
int main(){
    int g;
    cin >> g;
    while(g--){
        bool flag = false;
        int n;
        cin >> n;
        char underscore = '_';
        char * b = new char[n];
        cin >> b;
        int _Count = count(b, b + n, '_');
        if(_Count == n) cout<<"YES"<<endl;
        else{
            
            vector<int> colCount(26);
            int color = 0;
            for(vector<int>::iterator itr = colCount.begin(); itr != colCount.end(); ++itr){
                colCount[*itr] = count(b, b + n, (char)(color + 65));
                ++color;
                if(colCount[*itr] == 1){
                    cout<<"NO"<<endl;
                    flag = true;
                    break;
                }
                if(colCount[*itr] == n){
                    cout<<"YES"<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            cout<<makeHappy(b, n, _Count)<<endl;
        }
    }    
    return 0;
}
