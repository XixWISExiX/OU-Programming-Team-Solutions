#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;
    cin>>n;
    vector<string> leaderBoard;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        // transform(s.begin(), s.end(), s.begin(), ::toupper);

        if(i==0 && s == "ThoreHusfeldt"){
            cout<<"Thore is awesome"<<endl;
            return 0;
        }
        if(s.find("ThoreHusfeld") != string::npos && s != "ThoreHusfeldt"){
            cout<<"Thore sucks"<<endl;
            return 0;
        }
        if(s != "ThoreHusfeldt") leaderBoard.push_back(s);
        else break;
    }


    // Don't just compare to top, compare to all before.
    string goat = "ThoreHusfeldt";
    string res = "";
    for(string names : leaderBoard){
        string temp = "";
        for(int i = 0; i < names.size(); i++){
            if(i == goat.size()) break;
            temp+=goat[i];
            if(names[i]!=goat[i]){
                if(temp.size() > res.size()) res = temp;
                break;
            }
        }

    }
    cout<<res<<endl;

    return 0;
}