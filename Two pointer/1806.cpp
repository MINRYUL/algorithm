#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int n, s, sum, r, l, ans, arr[MAX];
bool c;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s; ans = n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    while(1){
        if (sum >= s && s) {
            c = true;
            ans = min(ans, r - l);
            sum -= arr[l++];
        }
        else if (r == n) break;
        else sum += arr[r++];
    }
    if(c) cout << ans << endl;
    else cout << ans << endl;
    return 0;
}
