#include <iostream>
#include <deque>

using namespace std;

//카드 옮기는 함수
void card(deque <int> &yourgr, deque <int> &mygr, deque <int> &me){ //상대방 그라운드, 내 그라운드, 내 덱

    //상대방 그라운드에 있는 카드들 뒤집어서(back부터) 내 덱 뒤에(push_back) 넣음
    while(!yourgr.empty()){
        me.push_back(yourgr.back());
        yourgr.pop_back();
    }

    //내 그라운드에 있는 카드를 뒤집어서 내 덱 뒤에 넣음
    while(!mygr.empty()){
        me.push_back(mygr.back());
        mygr.pop_back();
    }
}

pair<int,int> check(int gd, int gs){

    pair<int,int> c = make_pair(0,0);

    //그라운드가 비지 않았고 두 카드의 합이 5일 때 수연이 종 칠 수 있음
    if(gd && gs && (gd + gs == 5)){
        c.first = 1;
    }

    //둘 중 한 카드가 5일 때 도도가 종 칠 수 있음
    if(gd == 5 || gs == 5){
        c.second = 1;
    }

    return c;
}

int halligalli (int m, deque <int> &dodo, deque <int> &su){
    int gd = 0, gs = 0;
    deque <int> gdo, gsu;
    pair <int,int> c;

    for(int i = 0; i < m; i++){

        if(i%2 == 0){ //번갈아가며 진행
            //도도가 그라운드에 카드 내려둠
            gd = dodo.front();
            gdo.push_front(gd);
            dodo.pop_front();
        }
        else{
            //수연이가 그라운드에 카드 내려둠
            gs = su.front();
            gsu.push_front(gs);
            su.pop_front();
        }

        //게임 도중에 덱이 비면 상대방이 이김
        if(dodo.empty()){
            return 1;
        }
        if(su.empty()){
            return 0;
        }

        //종을 칠 수 있는 지 확인
        c = check(gd, gs);

        if(c.first){    //수연이가 종 칠 수 있으면
            card(gdo, gsu, su);
            gd = 0;
            gs = 0;
        }
        if(c.second){   //도도가 종 칠 수 있으면
            card(gsu, gdo, dodo);
            gd = 0;
            gs = 0;
        }

    }

    if(dodo.size() < su.size()){    //수연이가 이김
        return 1;
    }
    if(dodo.size() > su.size()){    //도도가 이김
        return 0;
    }
    if(dodo.size() == su.size()){   //비김
        return -1;
    }
    
}



int main() {
    int n, m, a, b;
    cin >> n >> m;

    deque <int> dodo, su;

    //입력
    while(n--){
        cin >> a >> b;
        dodo.push_front(a);
        su.push_front(b);
    }
    
    //연산
    int result = halligalli(m, dodo, su);
    
    //출력
    if(result == 1){
        cout << "su\n";
    }
    if(result == 0){
        cout << "do\n";
    }
    if(result == -1){
        cout << "dosu\n";
    }

    return 0;
}