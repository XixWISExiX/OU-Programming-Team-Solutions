#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned short int h,w;

const unsigned short int CHARACTERS_SIZE = 26;
class Node{
public:
    Node* children[CHARACTERS_SIZE];
    bool isEndOfWord;
    Node() : isEndOfWord(true){
        for(unsigned short int i = 0; i < CHARACTERS_SIZE; i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word) {
        Node* current = root;
        for (char c : word) {
            int index = c - 'A';
            if (!current->children[index]) {
                current->children[index] = new Node();
            }
            current = current->children[index];
        }
    }

    bool search(string word) {
        Node* current = root;
        for (char ch : word) {
            int index = ch - 'A';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
};

Trie trie;

void searchNeighbors(vector<vector<char>> grid, unsigned short int r, unsigned short int c, string word){
    // Longest combination possible is 10
    if(word.length() > 10) return;
    // Put current combination in the trie
    trie.insert(word);
    // left
    if(c-1 > -1 && grid[r][c-1] != '#'){
        char temp = grid[r][c-1];
        grid[r][c-1] = '#';
        word.push_back(temp);
        searchNeighbors(grid, r, c-1, word); 
        word.pop_back();
        grid[r][c-1] = temp;
    }
    // down 
    if(r+1 < h && grid[r+1][c] != '#'){
        char temp = grid[r+1][c];
        grid[r+1][c] = '#';
        word.push_back(temp);
        searchNeighbors(grid, r+1, c, word); 
        word.pop_back();
        grid[r+1][c] = temp;
    }
    // right
    if(c+1 < w && grid[r][c+1] != '#'){
        char temp = grid[r][c+1];
        grid[r][c+1] = '#';
        word.push_back(temp);
        searchNeighbors(grid, r, c+1, word); 
        word.pop_back();
        grid[r][c+1] = temp;
    }
    // up 
    if(r-1 > -1 && grid[r-1][c] != '#'){
        char temp = grid[r-1][c];
        grid[r-1][c] = '#';
        word.push_back(temp);
        searchNeighbors(grid, r-1, c, word); 
        word.pop_back();
        grid[r-1][c] = temp;
    }
}

void gridToTrie(vector<vector<char>> grid){
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            char temp = grid[r][c];
            grid[r][c] = '#';
            string s = "";
            s.push_back(temp);
            searchNeighbors(grid, r, c, s);
            grid[r][c] = temp;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    // Make the Grid
    cin >> h;
    cin >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (unsigned short int r = 0; r < h; r++) {
        for (unsigned short int c = 0; c < w; c++) {
            cin >> grid[r][c];
        }
    }

    // Make Trie with all possible combinations up to size 10 in depth
    gridToTrie(grid);

    // Add the words
    unsigned int n;
    cin >> n;
    string word;
    int counter = 0;
    for(unsigned int i = 0; i < n; i++){
        cin >> word;
        if(trie.search(word)) counter++;
    }
    cout<<counter<<endl;
    return 0;
}