#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int people, groups;
	int a,b,c;

    freopen("input.txt", "r", stdin);

	cin>>people;
	cin>>groups;

	int table[100001];
	int pointer[100001];
	int groupID = 0;

	for(int i = 0; i < groups; i++){
		cin>>a;
		cin>>b;
		cin>>c;
		//cout<<a<<" "<<b<<" "<<c<<endl;
		groupID++;

		// All same group 
		//if((table[a] == table[b] && table[b] == table[c]) || (table[a] == 0 && table[b] == 0 && table[c] == 0)){
		if(table[a] == 0 && table[b] == 0 && table[c] == 0){
		    //table[a] = groupID;
		    //table[b] = groupID;
		    //table[c] = groupID;

			// Group size after pointer 
		    table[a] = 3;
		    //table[b] = a;
		    //table[c] = a;

			// while for group look up (if val == 0, set other groups to 1)
			pointer[a] = 0;
			pointer[b] = a;
			pointer[c] = a;

			people -= 2;
			cout<<people<<endl;
		}

		// 2 same group
		else if(table[a] == table[b] && table[a] != 0 && pointer[a]){
		    table[c] = table[a];

		    pointer[c] = pointer[a];
			people--;
			cout<<people<<endl;
		}
		else if(table[a] == table[c] && table[a] != 0){
		    table[b] = table[a];
			people--;
			cout<<people<<endl;
		}
		else if(table[b] == table[c] && table[b] != 0){
		    table[a] = table[b];
			people--;
			cout<<people<<endl;
		}
		// All different non-zero

			// while for group look up
			pointer[a] = a;
			pointer[b] = a;
			pointer[c] = a;

			people -= 2;
			cout<<people<<endl;
		}

		// 2 same group
		else if(table[a] == table[b] && table[a] != 0 && pointer[a]){ //
		    table[c] = table[a];

		    pointer[c] = pointer[a];
			people--;
			cout<<people<<endl;
		}
		else if(table[a] == table[c] && table[a] != 0){
		    table[b] = table[a];
			people--;
			cout<<people<<endl;
		}
		else if(table[b] == table[c] && table[b] != 0){
		    table[a] = table[b];
			people--;
			cout<<people<<endl;
		}
		// All different non-zero
		else if((table[a] != table[b] && table[b] != table[c] && table[a] != table[c]) && (table[a] != 0 && table[b] != 0 && table[c] != 0)){
		//else if(table[a] != 0 && table[b] != 0 && table[c] != 0){
			people -= 2;
			cout<<people<<endl;
		}
		else cout<<people<<endl;

	}
	return 0;
}

/*
 *P1
 *{1:nan, 2:nan, 3:nan} | 6 - 2 = 4 | {1:0, 2:0, 3:0}
 *{1:0, 2:0, 4:nan} | 6 - 3 = 3 | {1:0, 2:0, 4:0}
 *{1:0, 5:nan, 6:nan} | 6 - 3 = 3 
 *
 *P2
 *{1:nan, 2:nan, 3:nan} | 10 - 2 = 8 | {1:0, 2:0, 3:0}
 *{4:nan, 5:nan, 6:nan} | 10 - 4 = 6 | {4:1, 5:1, 6:1}
 *{1:0, 4:1, 7:nan} | 10 - 4 = 6 | {1:0, 4:1, 7:nan}
 *{7:nan, 8:nan, 9:nan} | 10 - 6 = 4 | {7:2, 8:2, 9:2}
 *{1:0, 4:1, 7:2} | 10 - 8 = 2
 *
 *
 * (if all values are not nan, then don't count it)
 * (error can be found if all problem conditions aren't met)
 */
