#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int T = 0, C = 0, G = 0;
    for(char a : s){
       if(a == 'T') T++; 
       if(a == 'C') C++; 
       if(a == 'G') G++; 
    }
    int total = pow(T, 2) + pow(C, 2) + pow(G, 2);
    int minNum = min(T, min(C, G));
    for(int i = 0; i < minNum; i++){
        total+=7;
    }
    cout<<total<<endl;
    return 0;
}