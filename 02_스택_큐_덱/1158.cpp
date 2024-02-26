#include <iostream>
#include <queue>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;

    queue<int> q;
    
    int i = 1;
    while(k--){
        q.push(i++);                            //q에 1,2,...,k 집어넣음
    }

    cout << "<";

    while(!q.empty()){                          //n명의 사람이 모두 제거될 때까지
        int m = n;

        while(--m){                             //n번이 큐의 맨 앞에 오도록 함 
            q.push(q.front());                  //n번 앞의 사람들은 차례대로 뒤로 보냄
            q.pop();
        }
        
        if (q.size()==1){                       //마지막 출력
            cout << q.front() << ">\n";
            q.pop();
        }
        else{                                   //맨 앞에 온 n번을 출력하고 큐에서 삭제
            cout << q.front() << ", ";
            q.pop();
        }
    }
    return 0;
}