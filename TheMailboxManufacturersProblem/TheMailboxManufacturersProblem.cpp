#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define N 11 //max number of mail boxes + 1
#define K 11 //max number of mail boxes + 1
#define M 101 //max number of fire crakers + 1

int dp[N][M][M];
int main() {
    // for (int i=0;i<M;i++) for(int j=i;j<M;j++)
        // if(i==j) dp[0][i][j] = 0;
        // else dp[0][i][j] = dp[0][j][i] = 1e7;
    for(int i = 0; i < M; i++){
        for(int j = i; j < M; j++){
            if(i == j) dp[0][i][j] = 0; // base level is 0
            else{
                dp[0][i][j] = 5050;
                dp[0][j][i] = 5050;
            } // other levels are put to max value of fireworks possible 
        }
    }

    // for(int i=1;i<N;i++){//mailboxes
    //     for(int j=1;j<M;j++){//range, smaller range need to be solved first
    //         for(int k=0;k+j<M;k++){//start
    //             int best = 5050;
    //             for(int m=k+1;m<=k+j;m++){//midpoint
    //                 int explode = dp[i-1][k][m-1];
    //                 int not_explode = dp[i][m][k+j];
    //                 best = min(best, max(explode, not_explode) + m);
    //             }
    //             dp[i][k][k+j] = best;
    //         }
    //     }
    // }

    for(int k=1;k<K;k++){//mailboxes
        for(int i=1;i<M;i++){//range, smaller range need to be solved first
            for(int j=0;j+i<M;j++){//start
                int best = 5050;
                for(int x=j+1;x<=j+i;x++){//midpoint
                    int explode = dp[k-1][j][x-1];
                    int not_explode = dp[k][x][j+i];
                    best = min(best, max(explode, not_explode) + x);
                }
                dp[k][j][j+i] = best;
            }
        }
    }



    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, k, m;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k >> m;
        cout<<dp[k][0][m]<<endl;
    }

    return 0;
}