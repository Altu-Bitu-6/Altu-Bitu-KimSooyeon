#include <iostream>
#include <set>

using namespace std;

int main(){

    int n;
    cin >> n;

    string name, state;
    set <string> names;

    while(n--){
        cin >> name >> state;

        if(state == "enter"){
            names.insert(name);
        }
        else{
            names.erase(name);
        }

    }

    for(auto iter = names.rbegin(); iter != names.rend(); iter++){
        cout << *iter << '\n';
    }

    return 0;
}