//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define MAX 100001
using namespace std;
vector<int> tree[MAX];
int n, in[MAX], post[MAX], pos[MAX];

void sol(int is, int ie, int ps, int pe){
    if(is > ie || ps > pe) return;
    printf("%d ", post[pe]); int ir = pos[post[pe]];
    sol(is, ir - 1, ps, ps + ir - is - 1);
    sol(ir + 1, ie, ps + ir - is, pe - 1);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> in[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    for(int i = 0; i < n; i++) pos[in[i]] = i;
    sol(0, n - 1, 0, n - 1);
    return 0;
}
