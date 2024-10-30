#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    long double x1, y1, x2, y2, a;
    cin >> x1 >> y1 >> x2 >> y2 >> a;
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

    long double xc = (x1 + x2)/2;
    long double yc = (y1 + y2)/2;
    long double semi_major = a/2;
    long double foci_dist = sqrt(pow(x2-x1,2) + pow(y2-y1, 2))/2;
    long double semi_minor = sqrt(pow(semi_major, 2) - pow(foci_dist, 2));
    long double theta = atan((y2-y1)/(x2-x1));
    // long double theta = atan2(y2-y1, x2-x1);
    cout<<theta<<endl;

    long double half_width = sqrt(pow(semi_major * cos(theta), 2) + pow(semi_minor * sin(theta), 2));
    cout<<half_width<<endl;
    long double half_height = sqrt(pow(semi_major * sin(theta), 2) + pow(semi_minor * cos(theta), 2));
    cout<<half_height<<endl;

    // NOTE Incorrect answer
    cout<<xc + half_width * cos(theta) - half_height * sin(theta)<<endl;

    // cout<<xc-semi_major<<" "<<yc-semi_minor<<" "<<xc+semi_major<<" "<<yc+semi_minor<<endl;
    // cout<<xc-half_width * cos(theta) + half_height * sin(theta)<<" "<<yc-semi_minor*sin(theta)<<" "<<xc+semi_minor*cos(theta)<<" "<<yc+semi_minor*sin(theta)<<endl;
    // cout<<xc-semi_minor*cos(theta)<<" "<<yc-semi_minor*sin(theta)<<" "<<xc+semi_minor*cos(theta)<<" "<<yc+semi_minor*sin(theta)<<endl;
    // cout<<xc-semi_major*cos(theta)<<" "<<yc-semi_major*sin(theta)<<" "<<xc+semi_major*cos(theta)<<" "<<yc+semi_major*sin(theta)<<endl;
    // cout<<xc-semi_minor*sin(theta)<<" "<<yc-semi_minor*cos(theta)<<" "<<xc+semi_minor*sin(theta)<<" "<<yc+semi_minor*cos(theta)<<endl;
    return 0;
}