#include <iostream>
#include <vector>

using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector <char> wheel (n,'0');

    int last = 0, move;
    char letter;
    while(k--){
        
        cin >> move >> letter;

        last = (last + move)%n;
        if(wheel[last]!='0'){
            if(wheel[last]!=letter){
                cout << '!' << '\n';
                return 0;
            }
            continue;    
        }
        wheel[last] = letter;
    }

    //빈자리 ?로 채움
    for(int i=0; i<n; i++){
        if(wheel[i] == '0'){
            wheel[i] = '?';
        }
        
    }

    //시계방향으로 출력
    for(int i=0; i<n; i++){
        last += n;
        cout << wheel[last%n];
        last --;
    }

    cout << '\n';

    return 0;
}