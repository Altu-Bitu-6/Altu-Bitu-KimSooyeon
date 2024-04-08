#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//사방으로 갱신 우좌하상
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

pair<int,int> bfs(int n, int m, vector <vector<int> > &board, vector <vector<bool> > &visited ){

    int total_t = 0, cheese_cnt = 0;
    queue <pair<int,int> > q;       //이번 턴에 검사
    queue <pair<int,int> > tmp;     //다음 턴에 검사

    //시작점
    visited[0][0] = true;       
    q.push(make_pair(0,0)); 

    //치즈가 다 녹을 때까지
    while(!q.empty()){
        cheese_cnt = q.size();    //남은 치즈의 개수 갱신

        //한 턴
        while(!q.empty()){ 
            int x = q.front().first;
            int y = q.front().second;
            q.pop(); //지금 검사하는 요소 제거

            //동서남북으로 검사
            for(int i=0; i<4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){ //가장 자리가 아닐 때
                    if(!visited[new_x][new_y] && board[new_x][new_y]==1){   //방문한 적이 있고 치즈면 녹일 수 있는 치즈
                        tmp.push(make_pair(new_x, new_y)); //다음턴에 검사해야 함
                    }
                    else if(!visited[new_x][new_y] && board[new_x][new_y]==0){//방문한 적 없는 공기면
                        //동서남북검사해서 이번 턴에 녹일 수 있는 치즈 없는 지 확인
                        q.push(make_pair(new_x, new_y));
                    }
                    visited[new_x][new_y] = true;
                }
            }
        }

        //한 턴 다 돌았으면 녹은 치즈 주변 검사해야하니까 이번 턴 검사로 이동
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        total_t++; //턴 끝나면 개수 증가시킴
    }

    return make_pair(total_t - 1, cheese_cnt); 
}

int main(){
    //입력
    int n,m;
    cin >> n >> m;

    vector <vector<int> > board (n, vector<int>(m));
    vector <vector<bool> > visited (n, vector<bool> (m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    pair <int,int> ans =bfs(n, m, board, visited);
    cout << ans.first << "\n" << ans.second << "\n";

    return 0;
    
}