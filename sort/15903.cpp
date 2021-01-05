#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
long long x;
vector<long long> v;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x; v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < m; i++){
        long long temp = v[0] + v[1];
        v[0] = temp; v[1] = temp;
        sort(v.begin(), v.end());
    }
    x = 0;
    for(int i = 0; i < v.size(); i++)  x += v[i];
    
    cout << x << endl;
    return 0;
}
