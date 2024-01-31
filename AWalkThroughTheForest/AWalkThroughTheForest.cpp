#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(int graph[1001][1001], int r, int c, int size, int sum){
    if(r == 2){
        cout<<sum<<endl;
        return;
    }
    for(int i = 0; i < size; i++){
        cout<<i<<endl;
        if(graph[i][c] != 0) dfs(graph, i, c, size, sum+graph[i][c]); 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cout<<"sad"<<endl;
    int n,m;
    while(true){
        cin>>n;
        cout<<"fds"<<endl;
        if(n == 0) return 0;
        cin>>m;
        
        // Read in graph
        cout<<"fds"<<endl;
        int graph[1001][1001];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < n+1; j++){
                graph[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++){
            int nodeA,nodeB, weight;
            cin>>nodeA;
            cin>>nodeB;
            cin>>weight;
            graph[nodeA][nodeB] = weight;
            graph[nodeB][nodeA] = weight;
        }

        // Traverse graph
        for(int j = 0; j < n+1; j++){
            if(graph[1][j] != 0){
                dfs(graph, 1, j, n+1, graph[1][j]);
                // dfs(graph, j, 1);
            }
        }
    }

    return 0;
}