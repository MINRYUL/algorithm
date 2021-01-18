#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int k, x;
vector<int> v, ans[MAX];

void col(int pos, int s, int e){
    ans[pos].push_back(v[(e + s)/2]);
    if(pos == 1) return;
    col(pos - 1, s, (e + s)/2 - 1);
    col(pos - 1, (e + s)/2 + 1, e);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    while(cin >> x) v.push_back(x);
    col(k, 0, v.size() - 1);
    for(int i = k; i > 0; i--){
        for(int j : ans[i]) cout << j << ' ';
        cout << endl;
    }
    return 0;
}
