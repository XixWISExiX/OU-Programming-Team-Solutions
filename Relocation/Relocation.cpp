
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    vector<int> companies;
    int N,Q;
    cin>>N;
    cin>>Q;
    for(int i = 0; i < N; i++){
        int temp;
        cin>>temp;
        companies.push_back(temp);
    }

    short int operation;
    for(int i = 0; i < Q; i++){
        cin>>operation;
        if(operation == 1){
            int C,X;
            cin>>C;
            cin>>X;
            companies[C-1] = X;
        }
        else{
            int A,B;
            cin>>A;
            cin>>B;
            cout<<abs(companies[A-1]-companies[B-1])<<endl;
        }
    }

    return 0;
}