#include <iostream>
#include <vector>

using namespace std;

int n, virus_cnt = 0;

void virus_dfs(int idx, vector<vector<int> > &com, vector <bool> &visited){
    
    visited[idx] = true; //방문

    for(int i = 1; i<=n; i++){
        if(com[idx][i] == 1 && !visited[i]){    //연결되어있고 방문하지 않았다면 
            virus_cnt ++;                       //바이러스 전파됨
            virus_dfs(i, com, visited);
        }
    }

}

int main(){

    //입력
    int m;
    cin >> n >> m;

    vector <vector<int> > com (n+1, vector<int> (n+1,0));   //컴퓨터 연결 정보 행렬
    vector <bool> visited (n+1, false);                     //방문 기록

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        com[a][b] = 1;
        com[b][a] = 1;
    }

    //연산
    virus_dfs(1, com, visited);

    //출력
    cout << virus_cnt << "\n";

    return 0;
}