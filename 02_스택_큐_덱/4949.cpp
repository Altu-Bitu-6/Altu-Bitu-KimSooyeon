#include <iostream>
#include <stack>
#include <string>

using namespace std;


void balance(const string s){

    stack <char> p;                                 //괄호 스택

    int i = 0;
    while(s[i] != '.'){                             //문장 끝까지
        if (s[i] == '[' or s[i] == '('){            //왼쪽 괄호일시 스택
            p.push(s[i]);
        }

        else if (s[i] == ']'){                      //오른쪽 대괄호가 등장했을 때
            if(p.empty() or p.top() != '['){        //스택이 비었거나 top이 왼쪽 대괄호가 아니면 안 됨
                cout << "no\n";
                return;
            }
            else{
                p.pop();                            //top이 왼쪽 대괄호면 짝이 맞으므로 삭제
            }
        }

        else if (s[i] == ')'){                      //오른쪽 소괄호가 등장했을 때
            if(p.empty() or p.top() != '('){        //스택이 비었거나 top이 왼쪽 소괄호가 아니면 안 됨
                cout << "no\n";
                return;
            }
            else{       
                p.pop();                            //top이 왼쪽 소괄호면 짝이 맞으므로 삭제
            }
        }
        i++;
    }

    if(p.empty()){                                  //문장 끝까지 확인했을 때 스택이 비어있어야 함
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
        
}



int main(){
    
    string s;                                       //문자 배열로 도전해봤다가 실패함

    while(true){
        getline(cin, s);                            //띄어쓰기 포함한 문장 입력 받음
        if (s[0] == '.'){                           //입력 종료 조건
            break;
        }
        balance(s);
    }

    return 0;
}