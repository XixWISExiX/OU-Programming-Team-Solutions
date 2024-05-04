#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> matrix, vector<bool> &visited, int node, bool bugMove, int &totalStoppedNodes){
// void dfs(vector<vector<int>> matrix, vector<int> &visited, int node, bool bugMove, int &totalStoppedNodes){
    if(visited[node]) return;
    // if(visited[node] > matrix.size()) return;
    visited[node] = true;
    // visited[node]++;
    int calls = 0;
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[node][i] != 0){
            if(matrix[node][i] == 1 and !bugMove){
                dfs(matrix, visited, i, 1, totalStoppedNodes);
                calls++; 
            }
            else if(matrix[node][i] == -1){
                dfs(matrix, visited, i, bugMove, totalStoppedNodes);
                calls++;
            }
        }
    }
    if(calls == 0) totalStoppedNodes++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n;
    cin>>m;
    // Construct n x n matrix
    vector<vector<int>> matrix(n+1, vector<int>(n+1));
    int a,b;
    for(int i = 0; i < m; i++){
        cin>>a;
        cin>>b;
        if(a < 0) matrix[a*(-1)][b] = -1;
        else matrix[a][b] = 1;
    }

    vector<bool> visited(n, false);
    // vector<int> visited(n, 0);
    int ans = 0;
    dfs(matrix, visited, 1, false, ans);
    int add = true;
    for(int i = 0; i < n+1; i++){
        if(matrix[1][i] == -1) add = false;
    }
    if(add) cout<<ans+1<<endl;
    else cout<<ans<<endl;
}