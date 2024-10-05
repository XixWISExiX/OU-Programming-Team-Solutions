#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    double dis = 1001;
    for(int i=0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";

        if(x1 > 0 && x2 > 0) continue;
        if(x1 < 0 && x2 < 0) continue;

        double m = double(y2-y1)/(x2-x1);
        double b = y1-(m*x1);
        double newDis = b;
        // cout<<"m = "<<m<<endl;
        // cout<<"b = "<<b<<endl;
        // cout<<"newDis = "<<newDis<<endl;
        if(newDis < 0) continue;
        dis = min(newDis, dis);
    }

    if(dis==1001) dis=-1;

    cout<<dis;
    
    return 0;
}