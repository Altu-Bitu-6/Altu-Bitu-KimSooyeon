#include <iostream>
#include <map>

using namespace std;

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    map<string, int> byname;
    map<int, string> bynum;

    string pokemon, query;

    for(int i=1; i<n+1; i++){
        cin >> pokemon;
        byname[pokemon] = i;
        bynum[i] = pokemon;
    }

    for(int i=0; i<m; i++){
        cin >> query;
        if(isdigit(query[0])){
            cout << bynum[stoi(query)] << '\n';
        }
        else{
            cout << byname[query] << '\n';
        }
    }


    return 0;
}