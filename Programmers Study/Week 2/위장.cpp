#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> clths;
    
    for (vector<string> item : clothes)
        ++clths[item[1]];
    
    int answer = 1;
    for (auto& item : clths)
        answer *= (item.second + 1);
    
    return answer - 1;
}
