#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;

    vector <pair <int, int> > time (n);

    for(int i=0; i<n; i++){
        cin >> time[i].second >> time[i].first;
    }

    sort(time.begin(), time.end()); //회의 종료 시간으로 오름차순 정렬

    int cnt = 0, end = 0;
    for(int i=0; i<n; i++){
        if(end <= time[i].second){    //앞의 회의가 끝난 시간보다 회의 시작 시간이 같거나 늦어야 함
            cnt ++;
            end = time[i].first;
        }
    }

    cout << cnt << "\n";

    return 0;
}