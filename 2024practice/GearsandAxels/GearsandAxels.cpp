#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    double ans = 0;
    for(int i=0; i < n; i++){
        int s, c;
        cin >> s >> c;
        ans += s;
    }
    cout<<log(ans/n);
    
    return 0;
}