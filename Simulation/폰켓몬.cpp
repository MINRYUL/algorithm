#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(), nums.end()); int before = -1;
    for(int i = 0; i < nums.size(); i++){
        if(before != nums[i]) answer++;
        before = nums[i];
    }
    if(answer >= nums.size()/2) return nums.size()/2;
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    return 0;
}

