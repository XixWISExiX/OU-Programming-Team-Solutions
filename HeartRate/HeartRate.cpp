#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n,b;
    cin>>n;
    double p;
    for(int i; i < n; i++){
        cin>>b;
        cin>>p;
        double center = 60*b/p;
        double offset = 60/p;
        cout<<center-offset<<" "<<center<<" "<<center+offset<<endl;
    }

    return 0;
}