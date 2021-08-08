#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    if (s[0] == ')' || s[0] == ']' || s[0] == '}' ) return false;
    
    stack<char> brck;
    
    for (char c : s) {
        if (!brck.empty()) {
            if (brck.top() == '(' && c == ')') { brck.pop(); continue; }
            if (brck.top() == '[' && c == ']') { brck.pop(); continue; }
            if (brck.top() == '{' && c == '}') { brck.pop(); continue; }
        }
        brck.push(c);
    }
    
    return brck.empty();
}
