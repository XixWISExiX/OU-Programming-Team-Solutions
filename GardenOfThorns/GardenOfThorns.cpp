#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n,r,w,h;
    cin>>n;
    cin>>r;
    cin>>w;
    cin>>h;
    vector<vector<int>> vec;
    for(int i = 0; i < n; i++){
        int x,y,v;
        cin>>x;
        cin>>y;
        cin>>v;
        vector<int> sub;
        sub.push_back(x);
        sub.push_back(y);
        sub.push_back(v);
        vec.push_back(sub);
    }
    int scaler = 50;
    int scaler2 = scaler*scaler;
    int r2 = r*r;
    int sum = 0;
    for(int i = 0; i < w*scaler; i++){
        for(int j = 0; j < h*scaler; j++){
            for(int k = 0; k < n; k++){
                if(pow(vec[k][0]*scaler-i,2)+pow(vec[k][1]*scaler-j,2) < r2*scaler2){
                    sum+=vec[k][2];
                }
            }
        }
    }
    cout<<sum/((float)w*h*scaler2)<<endl;
}