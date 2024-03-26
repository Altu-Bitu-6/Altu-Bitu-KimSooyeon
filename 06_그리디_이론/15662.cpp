#include <iostream>
#include <vector>

using namespace std;

const int NUM = 8;  //고정된 톱니바퀴 개수

void rotate(const vector <string> &wheel, vector <int> &start, int idx, int step, int before){

    //돌린 바퀴 때문에 돌아간 바퀴면 돌린 바퀴를 돌리려 하지 않아야 함, 이전 바퀴 인덱스 인자로 사용해서 확인
    //왼쪽에 톱니바퀴가 있고 맞닿은 두 톱니가 다른 극일 때
    if((before != idx-1) && (idx - 1 >= 0) && (wheel[idx-1][(start[idx-1]+2)%NUM] != wheel[idx][(start[idx] + 6)%NUM])){ 
        rotate(wheel, start, idx - 1, -1 * step, idx);      //이전 바퀴랑 다른 방향으로 돌아가야하니까 step에 -1 곱해줌
    }
    //오른쪽에 톱니바퀴가 있고 맞닿은 두 톱니가 다른 극일 때
    if((before != idx+1) && (idx + 1 < wheel.size()) && (wheel[idx][(start[idx] + 2)%NUM] != wheel[idx+1][(start[idx+1] + 6)%NUM])){
        rotate(wheel, start, idx + 1, -1 * step, idx);
    }
    //해당 바퀴 step 만큼 꼭대기 톱니 인덱스 변경
    start[idx] = (start[idx] + NUM - step)% NUM;  

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int t,k;
    cin >> t;  

    vector <string> wheel(t);
    vector <int> start (t,0);   //톱니바퀴별 12시 방향 톱니 인덱스 저장
   
    for(int i=0; i<t; i++){
        cin >> wheel[i];
    }
    
    cin >> k;
    vector <pair <int, int> > moves(k);

    for(int i=0; i<k; i++){
        cin >> moves[i].first >> moves[i].second ;
    }

    //연산
    for(int i=0; i<k; i++){
        rotate(wheel, start, moves[i].first - 1, moves[i].second, -2);  //바퀴번호가 1부터니까 1빼줌, 이전 바퀴가 없음을 의미하는 -2
    }

    int cnt = 0;
    for(int i=0; i<t; i++){
        if(wheel[i][start[i]] == '1'){
            cnt++;
        }
    }

    //출력
    cout <<  cnt << "\n";

    return 0;
}