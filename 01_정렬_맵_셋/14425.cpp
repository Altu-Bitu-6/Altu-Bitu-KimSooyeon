#include <iostream>
#include <set>

using namespace std;;

int main(){

    int n, m;
    cin >> n >> m;

    set<string> S;
    string ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        S.insert(ele);
    }

    int cnt=0;
    for(int i=0; i<m; i++){
        cin >> ele;
        if(S.find(ele) != S.end()){
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}