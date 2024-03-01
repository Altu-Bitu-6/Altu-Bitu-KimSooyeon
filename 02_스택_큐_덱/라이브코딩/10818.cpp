#include <iostream>
#include <stack>

using namespace std;

int main(){
    
    int n;
    cin >> n; //명령의 수

    stack <int> s;

    string cmd;
    int m;

    while(n--){
        
        cin >> cmd;

        if(cmd == "push"){
            cin >> m;
            s.push(m);
        }
        else if (cmd == "pop"){
            if(s.empty()){
                cout << "-1\n";
            }
            else{
                cout << s.top() << "\n";  //top에 있는 원소 출력한 다음에 pop으로 삭제
                s.pop();
            }
        }
        else if (cmd == "size"){
            cout << s.size() << "\n";
        }
        else if (cmd == "empty"){
            cout << s.empty() << "\n";
        }
        else if (cmd == "top"){
            if(s.empty()){
                cout << "-1\n";
            }
            else{
                cout << s.top() << "\n";
            }
        }
    }

    return 0;
}