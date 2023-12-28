#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void pain(int target, int numHeights, vector<int> v, int numUsed, vector<int>& stored, bool& done, string &sad){
    // Check if we have the right amount of numbers to compare
    if(numHeights == numUsed){
        // Check if the numbers add up to the total
        if(target == 0){
            // Check if the indexes are unique
            map<int,int> mp;
            bool unique = true;
            for(int i:stored){
                mp[i]+=1;
                if(mp[i] == 2) unique = false;
            }
            if(unique){
                // We found one part of our answer
                for(int i = 0; i < stored.size(); i++){
                    sad+=to_string(v[stored[i]]);
                    sad.push_back(' ');
                }
                stored.clear();
                done = true;
            }
        }
        return;
    }
    if(!done){
        for(int i = 0; i < v.size(); i++){
            stored.push_back(i);
            pain(target-v[i], numHeights, v, numUsed+1, stored, done, sad);
            if(done) return;
            stored.pop_back();
        }
   }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    
    vector<int> numbers;
    int number;
    while(cin>>number){
        numbers.push_back(number);
    }

    int target2 = numbers[numbers.size()-1];
    numbers.pop_back();
    int target1 = numbers[numbers.size()-1];
    numbers.pop_back();
    sort(numbers.begin(), numbers.end(), greater<>());

    string sad="";
    vector<int> ans;
    bool flag1 = false;
    bool flag2 = false;
    pain(target1, numbers.size()/2, numbers, 0, ans, flag1, sad);
    pain(target2, numbers.size()/2, numbers, 0, ans, flag2, sad);
    cout<<sad<<endl;

    return 0;
}