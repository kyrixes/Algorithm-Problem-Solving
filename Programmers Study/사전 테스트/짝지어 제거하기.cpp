#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> stk;
    
    for (char c : s) {
        if (stk.empty() || stk.top() != c) stk.push(c);
        else stk.pop();
    }
    
    return (stk.empty());
}
