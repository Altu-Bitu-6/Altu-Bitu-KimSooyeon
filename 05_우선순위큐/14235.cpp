#include <iostream>
#include <queue>

using namespace std;

int main(){

    //입력
    int n, a, x;
    cin >> n;

    //선물들의 가치, 가장 가치 있는 선물을 줘야하므로 max heap 사용
    priority_queue<int> present;

    while(n--){
        cin >> a;

        if(a==0){    //아이들
            if(present.empty()){    //가진 선물이 없으면 -1 출력
                cout << "-1\n";
            }
            else{                   //가장 가치있는 즉 루트 노드값 출력하고 pop
                cout << present.top() << "\n";
                present.pop();
            }
        }
        else{       //거점지
            while(a--){     //선물 정보 업데이트
                cin >> x;
                present.push(x);
            }
        }
    }
    return 0;
}