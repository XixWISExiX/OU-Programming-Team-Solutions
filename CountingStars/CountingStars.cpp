#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int num = 0;
    int rows, cols;
    while(cin>>rows>>cols){
        num++;
        vector<char> above(cols);
        vector<char> current(cols);
        int clusters = 0;
        int streak = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                char cell;
                cin>>cell;
                current[j] = cell;
                if(cell != '-') streak = 0;
                if(!((i!=0 && above[j] == cell) && streak > 0)){
                    if(cell == '-') {clusters++; streak++;}
                    if(j>0 && current[j-1] == '-') clusters--;
                }
            }
            above = current;
            streak = 0;
            // cout<<clusters<<endl;
        }
        cout<<"Case "<<num<<": "<<clusters<<endl;
    }
    return 0;
}