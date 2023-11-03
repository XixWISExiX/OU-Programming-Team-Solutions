#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int customRound(int num) {
    if (num % 10 >= 5) return (num / 10 + 1) * 10;
    else return (num / 10) * 10;
}

// int min_cost(int n, int k, vector<int>& prices) {
//    sort(prices.rbegin(), prices.rend());
//    vector<int> dp(n+1, 0);
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= k; ++j) {
//            for (int x = 0; x < i; ++x) {
//                dp[i] = max(dp[i], dp[x] + prices[x] * (i-x));
//                cout<<dp[i]<<endl;
//            }
//        }
//    }
//    return accumulate(prices.begin(), prices.end(), 0) - dp[n];
// }


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, d, temp;
    cin >> n >> d;
    vector<int> coins;
    for(unsigned short int i = 0; i < n; i++) {
        cin >> temp;
        coins.push_back(temp);
    }
    // cout<<min_cost(n, d, coins)<<endl;



    int N = n+1;
    int D = d+1;
    int dp[D][N][N];
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(i==j) dp[0][i][j] = 0;
            else{
                // dp[0][i][j] = 200;
                dp[0][i][j] = 20000000;
                // dp[0][i][j] = 1;
                // dp[0][j][i] = 20000000;
                }
            // else dp[0][i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++){
        cout<<endl;
        for(int j = i; j < N; j++){
            cout<<dp[0][i][j]<<" ";
        }
    }

    for(int k = 1; k < D; k++){
        for(int i = 1; i < N; i++){
            for(int j = 0; j+i < N; j++){
                // dp[k][j][j+i] = 200000;
                dp[k][j][j+i] = 20000000;
                // dp[k][j][j+i] = ;
                for(int x = j+1; x <= j+i; x++){
                    // dp[k][j][j+i] = min(customRound(dp[k][j][j+i]), customRound(dp[k][x][j+i]));
                    // dp[k][j][j+i] = min(dp[k][j][j+i], max(customRound(dp[k-1][j][x-1]), dp[k][x][j+i]));
                    // dp[k][j][j+i] = min(dp[k][j][j+i], max(customRound(dp[k-1][j][x-1]), dp[k][x][j+i]));
                    // dp[k][j][j+i] = min(dp[k][j][j+i], coins[j] + max(customRound(dp[k-1][j][x-1]), dp[k][x][j+i]));
                    dp[k][j][j+i] = min(dp[k][j][j+i], coins[j] + max(customRound(dp[k-1][j][x-1]), dp[k][x][j+i]));
                    // dp[k][j][j+i] = min(dp[k][j][j+i], coins[j] + max(dp[k-1][j][x-1], dp[k][x][j+i]));
                    // dp[k][j][j+i] = min(dp[k][j][j+i], max(customRound(dp[k-1][j][x-1])+dp[k][x][j+i], dp[k-1][j][x-1]+dp[k][x][j+i]));
                    // dp[k][j][j+i] = min(dp[k][j][j+i], max(customRound(dp[k-1][j][x-1])+dp[k][x][j+i], dp[k-1][j][x-1]+dp[k][x][j+i]));
                    // dp[k][j][j+i] = min(dp[k][j][j+i], min(customRound(dp[k-1][j][x-1]), customRound(dp[k][x][j+i])));
                    // cout<<dp[d][j][j+1]<<endl;
                    // dp[d][j][j+i] = min(dp[d][j][j+i], x + max(dp[d-1][j][x-1], dp[d][x][j+i]));
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout<<endl;
        for(int j = i; j < N; j++){
            cout<<dp[1][i][j]<<" ";
        }
    }

    // cout<<dp[1][0][5]<<endl;
    // cout<<n<<endl;
    cout<<endl;
    cout<<dp[d][0][n]<<endl;

    return 0;
}