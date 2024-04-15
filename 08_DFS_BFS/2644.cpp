#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

int bfs(int from, int to, vector<vector <int> > &family, vector <bool> &visited){

    queue <pair<int, int> > q;      //검사할 사람
    q.push(make_pair(from, 0));     //인덱스, 촌수 pair로
    visited[from] = true;

    while(!q.empty()){
        int f = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(f == to){            //찾았을 때의 촌수 반환
            return cnt;
        }

        for(int i = 1; i<=n; i++){
            if(family[f][i] == 1 && !visited[i]){   //이어져있고 방문하지 않았을 때
                visited[i] = true;                  //방문 표시
                q.push(make_pair(i, cnt+1));        //검사할 사람에 추가
            }
        }
    }
    return -1;//발견 못 했을 때 -1 반환
}

int main(){

    //입력
    int p1, p2, m;
    cin >> n >> p1 >> p2 >> m;

    vector<vector <int> > family (n+1, vector <int> (n+1,0));
    vector <bool> visited (n+1, false);

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        family[a][b] = 1; 
        family[b][a] = 1;
    }

    //연산 및 출력
    cout << bfs(p1, p2, family, visited) << "\n";

    return 0;
}
