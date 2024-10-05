#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    int ans = 0;
    for(int i=0; i < n; i++){
        int num;
        cin >> num;
        if(num % 2 == 1) ans+=1;
    }

    cout<<ans;
    
    return 0;
}