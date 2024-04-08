#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 19, result = 0;

// 시작부분이 제일 왼쪽이 되도록
// 오른쪽, 오른쪽대각위, 오른쪽대각아래, 아래
int dx[] = { 0, -1, 1, 1}; //행   행,열이랑 x,y축 혼동해서 헤맸음
int dy[] = {1, 1, 1, 0};   //열

pair<int,int> omok(vector <vector<int> > &board){
 
    for(int i=1; i<N+1; i++){       
        for(int j=1; j<N+1; j++){   
            if(board[i][j]){
                int s = board[i][j];    //시작한 돌의 색

                for(int k=0; k<4; k++){
                    int new_x = i; 
                    int new_y = j;
                    int cnt = 1;    //시작할 때 자기자신 하나
                    
                    while(true){
                        //한 칸씩 같은 방향으로 계속 이동
                        new_x += dx[k]; 
                        new_y += dy[k];

                        if(new_x>0 && new_x< N+1 && new_y>0 && new_y< N+1){ //바둑판 위에 있을 때
                            //이동한 돌이 시작한 돌의 색과 같다면 개수 늘리고 같은 방향으로 계속 이동, 다르면 때려침
                            if(board[new_x][new_y] == s){
                                cnt++;
                            }
                            else{
                                break;
                            }
                        }
                        else{   //바둑판 범위 밖 탐색 x
                            break;
                        }

                        if(cnt == 6){  //해당 방향으로 6개 이상 연속될 때
                            break;
                        }
                    }

                    if(cnt == 5){   //반대 방향으로도 시작 전에 더 있어서 6개 이상 연속일 수 있음
                        int opp_x = i - dx[k];
                        int opp_y = j - dy[k];

                        //반대 방향 돌이 색이 다른 돌이거나 바둑판 밖이면 오목 성립
                        if(opp_x>0 && opp_x< N+1 && opp_y>0 && opp_y< N+1){
                            if(board[opp_x][opp_y] != s){
                                result = s;
                                return make_pair(i ,j);
                            }

                        }else{
                            result = s;
                            return make_pair(i, j);
                        }

                    }
                }
            }
        }
    }
    
    return make_pair(0,0);

}
int main(){

    //입력
    vector <vector<int> > board (N+1, vector<int> (N+1, 0)); //바둑판 

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }

    //연산
    pair <int,int> ans = omok(board);

    //출력
    if(result){ //1,2면 승부 결정남
        cout << result << "\n" << ans.first << " " << ans.second << "\n";
    }
    else{       //0이면 승부 결정 안 났음
        cout << result << "\n";
    }

    

    return 0;
}