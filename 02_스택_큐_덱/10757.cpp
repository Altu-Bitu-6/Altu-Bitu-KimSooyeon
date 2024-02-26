#include <iostream>
#include <stack>
#include <string>

using namespace std;

void add(stack<int> &s1, stack<int> &s2, stack<int> &result){
    
    if (s1.size() < s2.size()){
        swap(s1, s2);       //s1이 더 큰 숫자 스택
    }

    int over = 0, t, a = s1.size(), b = s2.size();

    while(!s1.empty() || !s2.empty()){
        if(!s2.empty()){
            t = s1.top() + s2.top() + over;
            over = t >= 10;
            result.push(t%10);
            s1.pop();
            s2.pop();
        }
        else {
            t = s1.top() + over;
            over = t >= 10;
            result.push(t%10);
            s1.pop();
        }
    }
    
    if (over){
        result.push(over);
    }
 
    while(!result.empty()){
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

    for(int i=0; i<n1.size(); i++){
        s1.push(n1[i] - '0');
    }

    for(int i=0; i<n2.size(); i++){
        s2.push(n2[i] - '0');
    }

    add(s1, s2, result);
    
    return 0;
}