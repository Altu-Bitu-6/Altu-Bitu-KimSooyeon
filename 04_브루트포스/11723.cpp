#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    string func;
    int n, ans = 0;

    while(m--){
        cin >> func;

        if(func == "all"){      //20bit를 다 1로 채움
            ans = (1 << 21) - 1;
            continue;
        }
        if(func == "empty"){    //20bit를 다 0으로 채움
            ans = 0;
            continue;
        }

        cin >> n;

        if(func == "add"){      //이미 있으면 무시 1|1->1 , 없으면 추가 0|1->1
            ans = ans | 1 << n;
        }
        if(func == "remove"){   //없으면 무시 0&~1->0, 있으면 제거 1&~1-> 0
            ans = ans & ~(1 << n);
        }
        if(func == "check"){    //있으면 1 1&1->1, 없으면 0 0&1->0
            cout << ((ans & (1 << n)) == 0 ? 0 : 1) << "\n";
        }
        if(func == "toggle"){   //있으면 제거 1^1->0  없으면 추가 0^1->1
            ans = ans ^ (1 << n);
        }

    }


    return 0;
}