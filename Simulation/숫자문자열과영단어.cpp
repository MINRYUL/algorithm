#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    string result = "";
    map<string, char> m;
    m["zero"] = '0'; m["one"] = '1'; m["two"] = '2';
    m["three"] = '3'; m["four"] = '4'; m["five"] = '5';
    m["six"] = '6'; m["seven"] = '7'; m["eight"] = '8';
    m["nine"] = '9';
    
    string findNumber = "";
    for(char i : s) {
        if(!findNumber.empty() && m.count(findNumber)){
            result.push_back(m[findNumber]);
            findNumber.clear();
        }
        if(i >= '0' && i <= '9') result.push_back(i);
        else findNumber.push_back(i);
    }
    
    if(!findNumber.empty() && m.count(findNumber)){
        result.push_back(m[findNumber]);
        findNumber.clear();
    }
    
    return stoi(result);
}

int main(){
    return 0;
}
