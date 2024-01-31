#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N,W;
    cin>>N;
    cin>>W;

    unordered_map<char, int> hasLoc;
    unordered_set<char> has;
    unordered_set<char> hasnt;
    for(int i = 0; i < N; i++){
        string s;
        cin>>s;
        string rules;
        cin>>rules;
        for(int j = 0; j < 5; j++){
            if(rules[j] == 'G'){
                hasLoc[s[j]] = j;
            }
            if(rules[j] == 'Y'){
                has.insert(s[j]);
            }
            // Edge conditions here
            if(rules[j] == '-'){
                hasnt.insert(s[j]);
            }
        }
    }

    vector<string> strings;
    vector<int> totals(W,0);
    int theMax = 0;
    for(int i = 0; i < W; i++){
        string s;
        cin>>s;
        strings.push_back(s);
        for(int j = 0; j < 5; j++){
            if(hasLoc.find(s[j]) != hasLoc.end() && hasLoc[s[j]] == j){
                totals[i]+=1;
            }
            if(has.find(s[j]) != has.end()){
                totals[i]+=1;
            }
            if(hasnt.find(s[j]) != hasnt.end() && (has.find(s[j]) != has.end() || hasLoc.find(s[j]) != hasLoc.end())){
                totals[i]+=1;
            }
        }
        // cout<<totals[i]<<endl;
        theMax = max(theMax, totals[i]);
    }

    vector<string> res;
    for(int i = 0; i < totals.size(); i++){
        if(theMax == totals[i]){
            res.push_back(strings[i]);
        }
    }

    for(string s : res){
        cout<<s<<endl;
    }

    return 0;
}