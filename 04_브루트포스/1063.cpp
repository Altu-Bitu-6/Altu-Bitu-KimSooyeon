#include <iostream>
#include <string>

using namespace std;

string move(string tmp, string op){

    if(op.find('R') != -1){     //오른쪽으로 이동
        tmp[0] += 1;
    }
    if(op.find('L') != -1){     //왼쪽으로 이동
        tmp[0] -= 1;
    }
    if(op.find('B') != -1){     //아래로 이동
        tmp[1] -= 1;
    }
    if(op.find('T') != -1){     //위로 이동
        tmp[1] += 1;
    }

    return tmp;
}

pair<string,string> chess(string king, string dol, string op){
    
    string tmpk = king;     //원래 자리 값 저장
    king = move(king, op);  //움직인 킹
    if (king[0] < 'A' or king[0] >'H' or king[1]<'1' or king[1]>'8'){   //킹이 체스판 벗어난 경우 돌 확인 필요 없이 원래 자리 반환
        return make_pair(tmpk, dol);
    }
    
    string tmpd = dol;      //원래 자리 값 저장
    if (king == dol){       //움직인 킹이 돌의 자리로 이동할 때
        dol = move(dol, op);    //움직인 돌
        if(dol[0] < 'A' or dol[0] >'H' or dol[1]<'1' or dol[1]>'8'){    //돌이 체스판 벗어난 경우 원래 자리 반환
            dol = tmpd;
            king = tmpk;
        }
    }

    return make_pair(king, dol);    //움직인 킹과 돌의 자리 반환
}


int main(){

    string king, dol, op;
    int n;
    
    cin >> king >> dol >> n;
    pair <string, string> ans;

    while(n--){
        cin >> op;
        ans = chess(king, dol, op);
        king = ans.first;
        dol = ans.second;
    }
    cout << ans.first << "\n" << ans.second << "\n";

    return 0;
}