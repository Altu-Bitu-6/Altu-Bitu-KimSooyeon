#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    //입력
    int n, x;
    cin >> n;

    //n개의 원소 가지는 min heap - 루트 노드 값이 n번째로 큰 값이 되도록 할 거임
    //n*n개의 원소 가지는 max heap 에서 n-1번 pop() 했을 때의 top() 값을 쓰려니까 메모리 초과 ~
    priority_queue<int, vector<int>, greater<int> > pq;

    //일단 n개 값 넣어줌
    for(int i=0; i<n; i++){
        cin >> x;
        pq.push(x);
    }
    
    //나머지 값들
    for(int i=0; i<n*(n-1); i++){
        cin >> x;
        if(x >= pq.top()){  //지금까지의 n번째 큰 값(루트 노드)보다 큰 값이 들어오면 pop해주고 push, n개 유지됨
            pq.pop();
            pq.push(x);
        }
    }

    //출력
    cout << pq.top() << "\n";

    return 0;
}