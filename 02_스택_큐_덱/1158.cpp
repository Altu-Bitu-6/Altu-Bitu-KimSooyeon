#include <iostream>
#include <queue>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;

    queue<int> q;
    int i = 1;

    while(k--){
        q.push(i++);  //q에 1,2,...,k 집어넣음
    }

    cout << "<";

    while(!q.empty()){
        int m = n;

        while(--m){
            q.push(q.front());
            q.pop();
        }
        
        if (q.size()==1){
            cout << q.front() << ">\n";
            q.pop();
        }
        else{
            cout << q.front() << ", ";
            q.pop();
        }

    }
    return 0;
}