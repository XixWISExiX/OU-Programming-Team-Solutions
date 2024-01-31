#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isConquered(vector<vector<int>> matrix){
    for(int r = 0; r < matrix.size(); r++){
        for(int c = 0; c < matrix[0].size(); c++){
            if(matrix[r][c] == 0) return false;
        }
    }
    return true;
}

void keepConquering(vector<vector<int>> matrix, vector<pair<int,int>> coords, int day){
    if(isConquered(matrix)){
        cout<<day<<endl;
        return;
    }
    
    vector<pair<int,int>> newCoords;
    for(int i = 0; i < coords.size(); i++){
        int r = coords[i].first;
        int c = coords[i].second;
        // cout<<r<<" "<<c<<endl;

        // Up
        if(r-1 > -1 and matrix[r-1][c] == 0){
            pair<int,int> p;
            p.first = r-1;
            p.second = c;
            newCoords.push_back(p);
            matrix[p.first][p.second] = 1;
            // cout<<"r = "<<p.first<<" c = "<<p.second<<endl;
        }
        // Right
        if(c+1 < matrix[0].size() and matrix[r][c+1] == 0){
            pair<int,int> p;
            p.first = r;
            p.second = c+1;
            newCoords.push_back(p);
            matrix[p.first][p.second] = 1;
            // cout<<"r = "<<p.first<<" c = "<<p.second<<endl;
        }
        // Down
        if(r+1 < matrix.size() and matrix[r+1][c] == 0){
            pair<int,int> p;
            p.first = r+1;
            p.second = c;
            newCoords.push_back(p);
            matrix[p.first][p.second] = 1;
            // cout<<"r = "<<p.first<<" c = "<<p.second<<endl;
        }
        // Left
        if(c-1 > -1 and matrix[r][c-1] == 0){
            pair<int,int> p;
            p.first = r;
            p.second = c-1;
            newCoords.push_back(p);
            matrix[p.first][p.second] = 1;
            // cout<<"r = "<<p.first<<" c = "<<p.second<<endl;
        }
    }

    keepConquering(matrix, newCoords, day+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int R,C,N;
    cin>>R;
    cin>>C;
    vector<vector<int>> matrix(R, vector<int>(C, 0));
    vector<pair<int,int>> coords;
    cin>>N;
    for(int i = 0; i < N; i++){
        int r,c;
        cin>>r;
        cin>>c;
        pair<int,int> p;
        p.first = r-1;
        p.second = c-1;
        coords.push_back(p);
        // cout<<"r = "<<p.first<<" c = "<<p.second<<endl;
        matrix[p.first][p.second] = 1;
    }
    keepConquering(matrix, coords, 1);
    return 0;
}