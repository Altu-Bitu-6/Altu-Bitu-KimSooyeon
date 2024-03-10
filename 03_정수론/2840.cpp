#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main(){

    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, k;
    cin >> n >> k;

    //행운의 바퀴 배열로 구현, 문자 0으로 초기화
    vector <char> wheel (n,'0');

    int last = 0, move;
    char letter;
    set <char> letters;             //바퀴에 같은 글자는 두 번 이상 등장하지 않는다는 조건 확인하기 위한 바퀴에 적힌 글자셋

    while(k--){                     //k번 반복
        
        cin >> move >> letter;      

        last = (last + move) % n;       //회전을 멈추었던 곳에서부터 s만큼 움직임, 맨 처음 화살표가 가리키는 곳이 0 바퀴 반시계 방향으로 인덱스 증가
        if(wheel[last]!='0'){           //다른 글자로 업데이트 된 경우
            if(wheel[last]!=letter){        //업데이트 되어있는 글자와 입력된 글자가 다를 경우 해당하는 행운의 바퀴 없음
                cout << '!' << '\n';
                return 0;
            }
            continue;                       //같은 경우 문제 없으니 다음 입력
        }
                                                    //아직 업데이트 되지않은 상태
        if(letters.find(letter) == letters.end()){  //입력 받은 글자의 정보가 바퀴에 존재하지 않을 때
            wheel[last] = letter;                   //글자 업데이트
            letters.insert(letter);                 //글자셋 업데이트
        }
        else{                                       //입력 받은 글자의 정보가 다른 위치에 이미 존재할 때
            cout << '!' << '\n';
            return 0;
        }
    }


    //빈자리 ?로 채움
    for(int i=0; i<n; i++){
        if(wheel[i] == '0'){
            wheel[i] = '?';
        }
    }

    //마지막으로 가리킨 문자에서부터 모든 바퀴 칸 시계방향으로 출력 - 인덱스 순서대로 출력하면 반시계 방향으로 출력됨
    for(int i = last; i > last - n; i--){
        cout << wheel[(i+n)%n];
    }
    
    cout << '\n';

    return 0;
}