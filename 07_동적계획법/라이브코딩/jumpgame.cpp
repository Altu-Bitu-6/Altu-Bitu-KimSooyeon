#include <iostream>
#include <vector>

using namespace std;
int n;

int jumpgame(int x, int y, vector< vector<int> > &board, vector< vector<int> > &check){

    //현재위치 board[x][y]에서 오른쪽으로 혹은 아래로 board[x][y]만큼
    //움직여서 board[n-1][n-1]에 도달할 수 있어야 함
    if (x >= n || y >= n) {  //마지막 위치 넘어감
        return 0;
    }

    if (x == n - 1 && y == n - 1) {
        return 1;
    }
 
    if (check[x][y] != -1) {   //이미 확인한 정보가 있을 경우
        return check[x][y];
    }
 
    check[x][y] = (jumpgame(x + board[x][y], y, board, check) || jumpgame(x, y + board[x][y], board, check));
 
    return check[x][y];

    
}

int main(){
    
    //입력
    int c;
    cin >> c;

    for(int t=0; t<c; t++){
        cin >> n;
        vector< vector<int> > board(n, vector<int>(n, -1));
        vector< vector<int> > check(n, vector<int>(n, -1));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> board[i][j];
            }
        }
        int result = jumpgame(0, 0, board, check);

        if(result){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    
    return 0;
}