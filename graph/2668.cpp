#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;
int n, x, y, r[MAX];
vector<int> v, g[MAX];
bool c, visited[MAX];

void dfs(int s) {
	visited[s] = true;
	for (int i : g[s]) {
		if (i == y) 
			c = true;
		if (!visited[i]) dfs(i);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> x; g[i].push_back(x);
	}
	for (int i = 1; i <= n; i++) {	
		y = i; memset(visited, false, sizeof(visited)); c = false;
		if (!visited[i]) {
			dfs(i);  
			if(c) v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i : v) cout << i << '\n';
}