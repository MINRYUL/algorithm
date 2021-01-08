//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;

int a, b, n;
vector<pair<char, int>> v;
vector<int> x, y, ti;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> n;
    
    for(int i = 0; i < n; i++){
        char c; int t, m;
        cin >> t >> c >> m;
        ti.push_back(t); v.push_back({c, m});
    }
    int cur = 0, blue = 0, red = 0, cut = 1, check1 = 0, check2 = 0;
    for(int i = 1; i <= 86400; i++){
        if(ti[cur] == i && cur < ti.size()){
            if(v[cur].first == 'B') blue += v[cur++].second;
            else  red += v[cur++].second;
        }
        if(!check1 && blue){
            if(a && blue){ x.push_back(cut++); blue--; check1 = a; }
            while(!a && blue){ x.push_back(cut++); blue--; }
        }
        if(!check2 && red){
            if(b && red){ y.push_back(cut++); red--;  check2 = b; }
            while(!b && red){ y.push_back(cut++); red--; }
        }
        if(check1) check1--;
        if(check2) check2--;
    }
    
    while(blue || red){
        if(!check1 && blue){
            if(a && blue){ x.push_back(cut++); blue--; check1 = a; }
            while(!a && blue){ x.push_back(cut++); blue--; }
        }
        if(!check2 && red){
            if(b && red){ y.push_back(cut++); red--;  check2 = b; }
            while(!b && red){ y.push_back(cut++); red--; }
        }
        if(check1) check1--;
        if(check2) check2--;
    }
    cout << x.size() << endl;
    for(int i : x)  cout << i << ' ';
    cout << endl << y.size() << endl;
    for(int i : y)  cout << i << ' ';
    return 0;
}
