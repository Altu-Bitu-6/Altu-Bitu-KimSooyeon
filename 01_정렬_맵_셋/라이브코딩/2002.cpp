#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cin >> n;

    string car;
    map<string, int> car_in;
    vector<int> car_out;

    for(int i=1; i<n+1; i++){
        cin >> car;
        car_in[car] = i;
    }

    for(int i=0; i<n; i++){
        cin >> car;
        car_out.push_back(car_in[car]);
    }

    int cnt=0;
    for(int i=0; i<n-1; i++){ //앞 차
        for(int j=i+1; j<n; j++){ //뒷 차
            if (car_out[i] > car_out[j]){ //뒷 차 순서가 더 작으면
                cnt++;
                break;
            }
        }
    }

    cout << cnt <<'\n';

    return 0;
}