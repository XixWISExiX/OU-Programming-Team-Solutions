#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    string s,t;
    cin>>s;
    t = "";
    for(int i = 0; i < s.size(); i++){
        t+=s[i];
        if(s[i] == '<'){
            t.pop_back();
            t.pop_back();
        }
    }
    cout<<t<<endl;

    return 0;
}