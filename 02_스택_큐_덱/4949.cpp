#include <iostream>
#include <stack>
#include <string>

using namespace std;


void balance(const string s){

    stack <char> p;         //괄호 스택

    int i = 0;
    while(s[i] != '.'){     //문장 끝까지
        if (s[i] == '[' or s[i] == '('){
            p.push(s[i]);
        }

        else if (s[i] == ']'){
            if(p.empty() or p.top() != '['){
                cout << "no\n";
                return;
            }
            else{
                p.pop();
            }
        }

        else if (s[i] == ')'){
            if(p.empty() or p.top() != '('){
                cout << "no\n";
                return;
            }
            else{
                p.pop();
            }
        }
        i++;
    }

    if(p.empty()){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
        
}



int main(){
    
    string s;    //최대 길이 100 글자

    while(true){
        getline(cin, s); //문장 입력 받음
        if (s[0] == '.'){
            break;
        }
        balance(s);
    }

    return 0;
}