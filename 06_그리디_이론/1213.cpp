#include <iostream>
#include <vector>

using namespace std;

/*
알파벳별 개수가 전부 짝수인 경우 양쪽에 반 나눠서
알파벳별 개수가 홀수인 경우는 딱 하나의 알파벳에 대해서만 허용 - 중앙에 위치 하도록 함, 그 외에는 모두 짝수 개 존재해야 함
*/

//알파벳 개수
const int MAX = 26;

//알파벳별 개수 배열
void cnt_al(string word, vector<int> &word_al){
    for(int i=0; i<word.size(); i++){
        word_al[word[i]-'A'] ++;
    }
}

//홀수 개 존재하는 알파벳 개수 확인
int cnt_odd(vector<int> &word_al){
    int cnt=0, idx;

    for(int i=0; i<MAX; i++){
        if(word_al[i]%2 == 1){
            idx = i;
            cnt ++;
        }
    }

    //홀수 개가 1개 이하인 경우 펠린드롬 만들 수 있음 - 0 이상의 값을 반환
    if(cnt == 1){       //홀수 가 한 개 있는 경우 해당 알파벳 번호 반환 (0~MAX-1)
        return idx;
    }

    if(cnt == 0){       //홀수가 없는 경우
        return MAX;
    }
    
    //그 이외의 경우 펠린드롬 만들 수 없음 - 0보다 작은 수 반환
    return -1;
}

void palindrome(string word, vector<int> &word_al){

    int odd;
    string al, front, back;

    cnt_al(word, word_al);
    odd =  cnt_odd(word_al);

    if(odd < 0){                        //홀수개의 알파벳이 두 개 이상 있는 경우 펠린드롬 만들 수 없음
        cout << "I'm Sorry Hansoo\n";
    }
    else{                               
        for(int i=0; i<MAX; i++){
            al = 'A'+ i;
            for(int j=0; j< word_al[i]/2; j++){     //각 알바벳별 등장 횟수의 반을 front 와 back 에 더해줌
                front += al;                        //알파벳 순서대로 되도록 더해줌
                back = al + back;                   //알파벳 순서 반대대로 되도록 더해줌
            }
        }

        if(odd < MAX){                              //홀수 개의 알파벳이 한 개 있는 경우
            al = 'A' + odd;
            cout << front + al + back << "\n";      //중간에 해당 알파벳 삽입
        }
        else{                                       //짝수 개의 알파벳만 있는 경우
            cout << front + back << "\n";
        }
    }

}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    //입력
    string word;
    cin >> word;

    //연산 및 출력
    vector<int> word_al(MAX, 0);
    palindrome(word, word_al);
    
    return 0;
}