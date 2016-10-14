#include<algorithm>
#include <iostream>
#include<vector>
using namespace std;
bool onHouse(int i, int s, int t){
    return (i >= s && i <= t);
}
int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }
    int count_apple = 0;
    for(vector<int>::iterator itr = apple.begin(); itr != apple.end(); ++itr){
        if(*itr + a >= s && *itr + a <= t ) ++count_apple;
    }
    int count_orange = 0;
    for(vector<int>::iterator itr = orange.begin(); itr != orange.end(); ++itr){
        if(*itr + b >= s && *itr + b <= t) ++count_orange;
    }
    cout<<count_apple<<endl<<count_orange<<endl;
    return 0;
}
