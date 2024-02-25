#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;

    queue<int> q;

    string cmd;
    int m;

    while(n--){
        cin >> cmd;

        if(cmd == "push"){
            cin >> m;
            q.push(m);
        }
        else if (cmd == "pop"){
            if (q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (cmd == "size"){
            cout << q.size() << "\n";
        }
        else if (cmd == "empty"){
            cout << q.empty();
        }
        else if (cmd == "front"){
            if (q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.front() << "\n";
            }
        }
        else if (cmd == "back"){
            if (q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.back() << "\n";
                q.pop();
            }
        }
    }


    return 0;
}