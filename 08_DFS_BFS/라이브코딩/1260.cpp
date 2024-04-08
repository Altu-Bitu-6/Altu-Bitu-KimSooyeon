#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

void dfs(int v,vector<vector<int> > &adj, vector<bool> &visited_dfs, vector<int> &ans_dfs){
    visited_dfs[v] = true;
    ans_dfs.push_back(v);

    for(int i=1; i<=n; i++){
        if(!visited_dfs[i] && adj[v][i]){
            dfs(i, adj, visited_dfs, ans_dfs);
        }
    }
}

void bfs(int v, vector<vector<int> > &adj, vector<bool> &visited_bfs, vector<int> &ans_bfs){
    queue<int> q;
    q.push(v);
    visited_bfs[v] = true;

    while(!q.empty()){

        v = q.front();
        q.pop();
        ans_bfs.push_back(v);

        for(int i=1; i<=n; i++){
            if(!visited_bfs[i] && adj[v][i]){
                visited_bfs[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    int m, v;    
    cin >> n >> m >> v;

    vector<vector<int> > adj (n+1,vector<int> (n+1,0));
    vector<bool> visited_dfs(n+1, false);
    vector<bool> visited_bfs(n+1, false);

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    vector<int> ans_dfs, ans_bfs;
    dfs(v, adj, visited_dfs, ans_dfs);
    bfs(v, adj, visited_bfs, ans_bfs);

    for(int i=0; i<ans_dfs.size(); i++){
        cout << ans_dfs[i] << " ";
    }
    cout << "\n";

    for(int i=0; i<ans_bfs.size(); i++){
        cout << ans_bfs[i] << " ";
    }
    cout << "\n";

    return 0;
}