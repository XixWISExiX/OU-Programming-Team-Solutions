#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    string s = to_string(v[0]);
    for(int i = 1; i < n; i++){
        // Check two case
        if(v[i] == v[i-1]+1){
            //Check three case
            if(i+1 < n && v[i+1] == v[i]+1){
                s+='-';
                i+=2;
                // Check for more than three case
                while(i < n && v[i]==v[i-1]+1) i++;
                i--;
                s+=to_string(v[i]);
            }
            // Is two case
            else s+=' '+to_string(v[i]);
        }
        // Is one case
        else s+=' '+to_string(v[i]);
    }
    cout<<s;

    return 0;
}