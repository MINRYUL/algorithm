#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0) {
        c = a % b;
        a = b; b = c;
    }
    return a;
}

long long solution(int w,int h) {
    //w와 h의 최대 공약수(gcd)를 구한다.
    //(w * h) - (((w / gcd) + (h / gcd) - 1) * gcd)
    int g = gcd(w, h);
    return ((long long) w * (long long) h) - ((((long long ) w / g) + ((long long) h / g) - 1) * g);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(8, 12) << endl;
    return 0;
}

