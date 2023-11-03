#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int sadness[11][101][101];

    // Initial Grid
    for(int i = 0; i < 101; i++){
        for(int j = i; j < 101; j++){
            if(i==j) sadness[0][i][j] = 0;
            else sadness[0][i][j] = 5050;
        }
    }

    for(int k = 1; k < 11; k++){
        for(int i = 1; i < 101; i++){
            for(int j = 0; j+i < 101; j++){
                sadness[k][j][j+i] = 5050;
                for(int x = j+1; x <= j+i; x++){
                    sadness[k][j][j+i] = min(sadness[k][j][j+i], x + max(sadness[k-1][j][x-1], sadness[k][x][j+i]));
                }
            }
        }
    }
    
    // Make the Grid
    int K, M, N;
    cin >> N;

    for (unsigned short int i = 0; i < N; i++) {
        cin >> K;
        cin >> M;
        cout << sadness[K][0][M] << endl;
    }

    return 0;
}