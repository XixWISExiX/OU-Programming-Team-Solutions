#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    // n = number of cents given
    // d = number of deviders
    int n, d, temp;
    cin >> n >> d;
    vector<int> cents;
    // Grab all cents in the input
    for(unsigned short int i = 0; i < n; i++) {
        cin >> temp;
        cents.push_back(temp);
    }

    // Matrix values for n and d which are those values + 1
    int N = n+1;
    int D = d+1;
    // Array of Matricies for all values with cent combinations with dividers
    int dp[D][N][N];
    // Matrix for all added cent values without rounding
    int dps[N][N];

    // Add all the cents to the bottm layer of the matrix
    for(int i = 0; i < N; i++){
        dp[0][i][i] = cents[i];
        dps[i][i] = cents[i];
    }

    // Add all the values to both the dps matrix and the first matrix in dp (Base Case)
    for(int i = 1; i < N; i++){
        for(int j = 0; j+i < N; j++){
            dps[j][j+i] = dps[j][j] + dps[j+1][j+i];
            dp[0][j][j+i] = dp[0][j][j] + dp[0][j+1][j+i];
        }
    }

    // Round the values in the first matrix in dp
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            dp[0][i][j] = (((dp[0][i][j]) + 5)/10)*10;
        }
    }

    // We are going through the top row in the matrix and only adding new values there. Main reason is that for this problem, most values we need are given in the base
    // case making this a n^3 problem.

    // For every matrix in the array of matricies
    for(int k = 1; k < D; k++){
        // For each column in the matrix
        for(int i = 0; i < N; i++){
            dp[k][0][i] = 20000000;
            // For the combinations 1 up to the column in the matrix + 1 (fitting all probabilities because the n + 1)
            for(int x = 1; x <= i+1; x++){
                int temp;
                // If the value we are looking at in the matrix is not stored in memory, make it equal to the most recent left value in the base case.
                if(dp[k-1][0][x-1] < 0) temp = dp[0][0][x-1];
                else temp = dp[k-1][0][x-1]; // make the value equal to the most recent left value in the most recent past case.
                // At a given position find if it's current value is the minimum or the rounded values around rounding, or the new values around rounding.
                dp[k][0][i] = min(dp[k][0][i], min((((dps[0][x-1] + dps[x][i]) + 5)/10)*10, (((temp + dp[0][x][i]) + 5)/10)*10));
            }
        }
    }

    cout<<dp[d][0][n]<<endl;
    return 0;
}