#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, arr[65][65];

bool check(int x, int y, int n){
    for(int i = x; i < x + n; i++)  for(int j = y; j < y + n; j++)  if(arr[x][y] != arr[i][j])  return false;
    return true;
}

void Divide(int x, int y, int n){
    if(check(x, y, n))  cout << arr[x][y];
    else{
        cout << "(";
        for(int i = 0; i < 2; i++)  for(int j = 0; j < 2; j++)  Divide(x + i*(n/2), y + j*(n/2), n/2);
        cout << ")";
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for(int i = 0; i < N; i++)  for(int j = 0; j < N; j++)  scanf("%1d", &arr[i][j]);
    Divide(0, 0, N);
    return 0;
}
