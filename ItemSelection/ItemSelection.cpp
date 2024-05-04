#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n, m, s, p, q;
    cin>>n;
    cin>>m;
    cin>>s;
    cin>>p;
    cin>>q;
    // (m+n+1)/n
    int pages = (int) ceil((double) n/m);
    bool book[m+1][pages+1];
    bool res[m+1][pages+1];
    for(int i = 0; i < m+1; i++){
        for(int j = 0; i < pages+1; j++){
            book[i][j] = false;
            res[i][j] = false;
        }
    }

    for(int i = 0; i < p; i++){
        int num;
        cin>>num;
        int pageNum = (int) ceil((double) num/m);
        int pagePos = num % m;
        book[pagePos][pageNum] = true;
    }

    for(int i = 0; i < q; i++){
        int num;
        cin>>num;
        int pageNum = (int) ceil((double) num/m);
        int pagePos = num % m;
        res[pagePos][pageNum] = true;
    }

    int totalChanges = 0;

    for(int c = 1; c < pages+1; c++){
        // Check if page needs to be changed along with ratio
        bool changeNeeded = true;
        while(changeNeeded){
            changeNeeded = false; //TODO match this edge case for the satesfactory end pages
            int marked = 0;
            int match = 0;
            for(int r = 1; r < m+1; r++){
                if(book[r][c] != res[r][c]){
                    changeNeeded = true;
                }

                if(book[r][c]){
                    marked++;        
                }

                if(book[r][c] == res[r][c]){
                    match++;
                }
            }
            if(!changeNeeded) break;
            int selectChanges = abs(marked - match);

            // SELECT ALL AND DESELECT ALL NOT ADDED.
            for(int r = 1; r < m+1; r++){
                book[r][c] = true;
            }
        }



    }

    cout<<totalChanges<<endl;

    return 0;
}