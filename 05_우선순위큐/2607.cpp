#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//각 알파벳별 개수 배열 반환
vector<int> alphabet (string word){
    vector<int> al(26,0);
    for(int i=0; i<word.size();i++){
        al[word[i]-'A'] ++;
    }
    return al;
}

//두 단어의 길이의 차가 1이 넘는 지 여부 반환
bool wronglen(const string &w1, const string &w2){
    int diff = w1.size() - w2.size();
    if(abs(diff) <= 1){
        return false;
    }
    return true;
}

//입력의 두 단어가 비슷한 두 단어인지 반환
bool similar(const string &w1, const string &w2){

    //2-1. 2개 다른 경우에 길이가 2 다른 경우 포함돼버림 길이는 1차이까지만 가능
    if(wronglen(w1, w2)){
        return false;
    }

    vector<int> al1 = alphabet(w1), al2 = alphabet(w2);

    //1. 같은 구성인 경우
        //알파벳 구성이 0개 다름

    //2. 한 단어에서 한 문자를 더하거나, 빼거나, 하나의 문자를 다른 문자로 바꾸어 나머지 한 단어와 같은 구성을 갖게 되는 경우
        //알파벳 구성이 각각 1개 다르거나, 1개 다르거나, 2개 다름

    int cnt = 0;
    for(int i=0; i<26; i++){
        if(al1[i] != al2[i]){
            cnt += abs(al1[i] - al2[i]);  //구성이 얼마나 차이나는지
        }
    }
    //길이가 1이하로 차이나고 구성이 2이하로 차이나면 비슷한 단어
    if(cnt <= 2){
        return true;
    }
    //더 차이나면 안 됨
    return false;
    
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    //입력
    int n;
    cin >> n;

    string word1, word2;
    cin >> word1;

    //나머지 단어들에 대해서 word1과 비슷한 단어가 몇 개 있는지
    int cnt = 0;
    while(n-- > 1){
        cin >> word2;
        cnt += similar(word1, word2);
    }
    
    cout << cnt << "\n";

    return 0;
}