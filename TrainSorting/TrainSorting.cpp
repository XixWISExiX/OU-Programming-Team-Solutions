#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    vector<int> v;
    int n;
    cin >> n;

    pair<int,pair<int, int>> dp[n+1][n+1];
    // Add all the cents to the bottem layer of the matrix
    for(int i = 0; i < n+1; i++){
        dp[i][i].first = 0;
    }

    // Need to read in cars in decreasing order
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        // Add all the values to both the dps matrix and the first matrix in dp (Base Case)
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j+i < n+1; j++){
                if(i == 1) dp[j][j+i].second.first, dp[j][j+i].second.second = val;
                else dp[j][j+i].second.first, dp[j][j+i].second.second = 0;
                dp[j][j+i].first = 9;
                for(int x = 1; x <= j+i+1; x++){
                    dp[j][j+i].second.first = max(dp[j][j+i].second.first, val);
                    dp[j][j+i].second.second = max(dp[j][j+i].second.second, val);
                    if(dp[j][j+1].second.first == val || dp[j][j+1].second.second == val){
                        dp[j][j+i].first = max(dp[j][j+i].first, max(dp[j][x-1].first, dp[x][j+i].first)+1);
                    }
                }
            }
        }
        // v.push_back(val);
    }
    cout<<dp[n][n].first<<endl;
}