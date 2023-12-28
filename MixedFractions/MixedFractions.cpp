#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int n,d;
    while(true){
        cin>>n;
        cin>>d;
        if(n == 0 && d == 0) break;
        cout<<n/d<<" "<<n%d<<" / "<<d<<endl;
    }

    return 0;
}