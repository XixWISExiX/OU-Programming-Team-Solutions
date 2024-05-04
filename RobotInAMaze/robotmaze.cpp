#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<char>> matrix, short int x, short int y, short int solX, short int solY, short int dir, char prevDir, int count, int& ans, bool& done){
    // cout<<count<<endl;
    // cout<<x<<", "<<y<<endl;
    // cout<<solX<<", "<<solY<<endl;
    // cout<<dir<<endl;
    if(!done){
        if(dir == 0) return;
        if(count > matrix.size() * matrix[0].size()) return;

        if(x==solX and y==solY){
            ans = min(ans, count);
            // cout<<"Ans: "<<ans<<endl;
            done = true;
            return;
        }


        // int disX = abs(x - solX);
        // int disY = abs(y - solY);
        

        map<char,short int> mp;
        mp['U'] = abs(x-solX) + abs(y-1-solY);
        mp['D'] = abs(x-solX) + abs(y+1-solY);
        mp['L'] = abs(x-1-solX) + abs(y-solY);
        mp['R'] = abs(x+1-solX) + abs(y-solY);

        vector<pair<short int, short int>> pairs; 

        for (auto& it : mp) { 
            pairs.push_back(it); 
        } 

        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) { 
            return a.second < b.second; 
        }); 


        // for(auto& it : mp){
        for (map<char,short int>::reverse_iterator it = mp.rbegin(); it!=mp.rend(); it++) { 
            // if(disX + disY == 4) cout<<it->first<<endl;
            // cout<<it->first<<endl;

            // Up
            if(y-1 > -1 and matrix[x][y-1] != 'B' and it->first == 'U'){
                if(prevDir == 'U') solve(matrix, x, y-1, solX, solY, dir-1, 'U', count+1, ans, done);
                // else solve(matrix, x, y-1, solX, solY, 2, 'U', count+1, ans);
                else if(prevDir != 'D') solve(matrix, x, y-1, solX, solY, 2, 'U', count+1, ans, done);
            }
            // Down
            if(y+1 < matrix.size()-1 and matrix[x][y+1] != 'B' and it->first == 'D'){
                if(prevDir == 'D') solve(matrix, x, y+1, solX, solY, dir-1, 'D', count+1, ans, done);
                // else solve(matrix, x, y+1, solX, solY, 2, 'D', count+1, ans);
                else if(prevDir != 'U') solve(matrix, x, y+1, solX, solY, 2, 'D', count+1, ans, done);
            }
            // Left
            if(x-1 > -1 and matrix[x-1][y] != 'B' and it->first == 'L'){
                if(prevDir == 'L') solve(matrix, x-1, y, solX, solY, dir-1, 'L', count+1, ans, done);
                // else solve(matrix, x-1, y, solX, solY, 2, 'L', count+1, ans);
                else if(prevDir != 'R') solve(matrix, x-1, y, solX, solY, 2, 'L', count+1, ans, done);
            }
            // Right
            if(x+1 < matrix[0].size()-1 and matrix[x+1][y] != 'B' and it->first == 'R'){
                if(prevDir == 'R') solve(matrix, x+1, y, solX, solY, dir-1, 'R', count+1, ans, done);
                // else solve(matrix, x+1, y, solX, solY, 2, 'R', count+1, ans);
                else if(prevDir != 'L') solve(matrix, x+1, y, solX, solY, 2, 'R', count+1, ans, done);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int iter;
    cin>>iter;

    for(int i=0; i < iter; i++){
        int rows, columns;
        cin>>rows>>columns;
        vector<vector<char>> matrix(rows, vector<char>(columns));
        short int x,y,solX,solY;
        for(int r=0; r < rows; r++){
            for(int c=0; c < columns; c++){
                char ch;
                cin>>ch;
                matrix[r][c] = ch;
                if(ch == 'R'){
                    y = r;
                    x = c;
                }
                if(ch == 'D'){
                    solY = r;
                    solX = c;
                }
            }
        }
        int ans = matrix.size() * matrix[0].size();
        // cout<<ans<<endl;
        // cout<<x<<", "<<y<<endl;
        // cout<<solX<<", "<<solY<<endl;
        bool flag = false;
        solve(matrix, x, y, solX, solY, 2, ' ', 0, ans, flag);
        // cout<<"bruh "<<i<<endl;
        if(flag) cout<<ans<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}