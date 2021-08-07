#include <string>

using namespace std;

bool check(string s) {
    for (int i = 0; i <= s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1])
            return false;
    
    return true;
}

int solution(int n, int m) {
    int answer = 0;
    
    for (int i = n; i <= m; i++)
        answer += check(to_string(i));
    
    return answer;
}
