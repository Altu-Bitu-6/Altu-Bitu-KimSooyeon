#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getSeven(vector<int> &dwarfs){
    int sum = 0;
    for(int i=0; i<9; i++){
        sum += dwarfs[i];
    }

    sum -= 100;

    sort(dwarfs.begin(), dwarfs.end());

    for(int i=0; i<9-1; i++){                       //01 02 .. 08 12 ... 18 ... 78 최소한으로 비교
        for(int j=i+1; j<9; j++){
            if (sum == dwarfs[i] + dwarfs[j]){
                dwarfs.erase(dwarfs.begin() + j);   //i부터 지우면 뒤에 있는 값 인덱스가 바뀌어서 잘못된 값 지울 수 있음
                dwarfs.erase(dwarfs.begin() + i);
                return;
            }
        }
    }
}

int main(){

    vector<int> dwarfs(9);

    for(int i=0; i<9; i++){
        cin >> dwarfs[i];
    }

    getSeven(dwarfs);

    for(int i=0; i<7; i++){
        cout<< dwarfs[i] << "\n";
    }

    return 0;
}