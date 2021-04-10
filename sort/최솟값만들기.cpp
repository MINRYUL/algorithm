#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    for(int i = 0; i < A.size(); i++)
        answer += (A[i] * B[i]);
    
    return answer;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    return 0;
}


