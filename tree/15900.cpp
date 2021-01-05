#include <iostream>
#include <vector>
using namespace std;
vector<int> v[500001];
bool check[500001];
int N, a, b;
void DFS(int node, int d)
{
    bool leaf = true;
    check[node] = true;
    for (int i : v[node])
        if (!check[i]) leaf = false, DFS(i, d + 1);
    if (leaf) a += d;
}
int main()
{
    cin >> N;
    while (cin >> a >> b) v[a].push_back(b), v[b].push_back(a);
    a = 0; DFS(1, 0);
    cout << (a % 2 ? "Yes" : "No");
    return 0;
}
