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
#include <stdlib.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    string threeStrikes;
    while(n){
        threeStrikes.push_back(n % 3 + '0');
        n /= 3;
    }

    cout << threeStrikes << endl;
    int startIndex = 0;
    while(!(threeStrikes[startIndex] - '0')) startIndex += 1;

    for(int i = startIndex; i < threeStrikes.size(); i++)
        answer += (threeStrikes[i] - '0') * pow(3, threeStrikes.size() - i - 1);
    
    return answer;
}
