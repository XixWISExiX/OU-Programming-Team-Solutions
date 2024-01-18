#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int P;
    cin>>P;
    for(int i = 0; i < P; i++){
        int n,base10;
        cin>>n;
        cin>>base10;

        bool flag = true;
        string base8 = to_string(base10);
        for(int i = 0; i < base8.size(); i++){
            if((int) base8[i] - '0' > 7){
                flag = false;
            }
        }

        int ans8 = 0;
        if(flag){
            for(int i = 0; i < base8.size(); i++){
                ans8 += ((int) base8[i] - '0') * pow(8,base8.size()-1-i);
            }
        }
        // base8 = to_string(ans8);

        string base16 = to_string(base10);
        int ans16 = 0;
        for(int i = 0; i < base16.size(); i++){
            ans16 += ((int) base16[i] - '0') * pow(16,base16.size()-1-i);
        }

        cout<<n<<" "<<ans8<<" "<<base10<<" "<<ans16<<endl;
    }
    return 0;
}