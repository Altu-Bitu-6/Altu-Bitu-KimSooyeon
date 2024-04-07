#include <iostream>
#include <vector>

using namespace std;

void make_plan(int n, vector<pair<int, int> > &plan, vector<int> &money){
    for(int i=0; i<n; i++){  //1일차부터 n일차까지
        for(int j = i + plan[i].first; j<= n; j++){       //i일차에 시작한 상담이 끝난 날부터 n일차까지 중
            if(money[j] < money[i] + plan[i].second){   //j일차에 상담을 할 때 가장 이득인 금액으로 업데이트
                money[j] =  money[i] + plan[i].second;
            }
        }
    }
}

int main(){

    int n;
    cin >> n;

    vector<pair<int, int> > plan(n);

    for(int i=0; i<n; i++){
        cin >> plan[i].first >> plan[i].second;
    }

    vector<int> money (n+1,0);

    make_plan(n, plan, money);
    cout << money[n] << "\n";

    return 0;
}