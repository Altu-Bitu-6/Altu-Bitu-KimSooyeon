#include <iostream>
#include <stack>
#include <string>

using namespace std;

void add(stack<int> &s1, stack<int> &s2, stack<int> &result){
    //스택에서 작은 자릿수부터 꺼내서 더해준 값을 result 스택에 쌓음
    //result 스택 출력할 때 큰자릿수부터 출력됨
    
    if (s1.size() < s2.size()){
        swap(s1, s2);                                           //s1이 더 큰 숫자의 스택이 되도록
    }

    int over = 0, t;                                            //over : 받아올림

    while(!s1.empty() || !s2.empty()){                          //두 스택이 모두 빌 때 까지
        if(!s2.empty()){                                        //더 작은 숫자의 스택이 빌 때까지
            t = s1.top() + s2.top() + over;
            over = t >= 10;
            result.push(t%10);
            s1.pop();
            s2.pop();
        }
        else {
            t = s1.top() + over;                                //더 큰 숫자의 스택이 빌 때까지
            over = t >= 10;
            result.push(t%10);
            s1.pop();
        }
    }
    
    if (over){                                                  //마지막 연산 결과 10이상인 경우
        result.push(over);
    }
 
    while(!result.empty()){                                     //결과 출력
        cout << result.top();
        result.pop();
    }

    cout << '\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string n1, n2;
    cin >> n1 >> n2;

    stack <int> s1, s2, result;

    for(int i=0; i<n1.size(); i++){                             //문자열로 받은 숫자를 int로 변환하여 스택에 큰자릿수부터 쌓음
        s1.push(n1[i] - '0');
    }

    for(int i=0; i<n2.size(); i++){
        s2.push(n2[i] - '0');
    }

    add(s1, s2, result);
    
    return 0;
}