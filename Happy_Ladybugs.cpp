#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;

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
            if(_Count > 0){
                cout<<"YES"<<endl;
                continue;
            }
            if(b[0] != b[1] && b[0]!= '_' && b[1]!= '_') flag = true;
            if(b[n-2] != b[n-1] && b[n-2]!= '_' && b[n-1]!= '_') flag = true;
            for(int pos = 1; pos < n - 1; pos += 2){
                if(b[pos] != '_')
                    if(b[pos] != b[pos-1] && b[pos] != b[pos+1]){
                        flag = true;
                        break;
                    }
            }
            if(!flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }    
    return 0;
}
