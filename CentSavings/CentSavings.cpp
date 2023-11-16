#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int customRound(int num) {
    if (num % 10 >= 5) return (num / 10 + 1) * 10;
    else return (num / 10) * 10;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, d, temp;
    cin >> n >> d;
    vector<int> cents;
    for(unsigned short int i = 0; i < n; i++) {
        cin >> temp;
        cents.push_back(temp);
    }

    int N = n+1;
    int D = d+1;
    int dp[D][N][N];
    int dps[N][N];

    for(int i = 0; i < N; i++){
        dp[0][i][i] = cents[i];
        dps[i][i] = cents[i];
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j+i < N; j++){
            dps[j][j+i] = dps[j][j] + dps[j+1][j+i];
            dp[0][j][j+i] = dp[0][j][j] + dp[0][j+1][j+i];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            dp[0][i][j] = customRound(dp[0][i][j]);
        }
    }

    for(int k = 1; k < D; k++){
        for(int i = 0; i < N; i++){
            dp[k][0][i] = 20000000;
            for(int x = 1; x <= i+1; x++){
                int temp;
                if(dp[k-1][0][x-1] < 0) temp = dp[0][0][x-1];
                else temp = dp[k-1][0][x-1];
                dp[k][0][i] = min(dp[k][0][i], min(customRound(dps[0][x-1] + dps[x][i]), customRound(temp + dp[0][x][i])));
            }
        }
    }

    cout<<dp[d][0][n]<<endl;
    return 0;
}