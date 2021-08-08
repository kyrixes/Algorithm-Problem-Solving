#include <string>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int solution (vector<string> strs, string t) {
    set<string> s;
    
    vector<int> dp(t.length() + 1, INT_MAX);
    dp[t.length()] = 0;
    
    for (int i = 0; i < strs.size(); i++)
        s.insert(strs[i]);
    
    for (int i = t.length() - 1; i >= 0; i--) {
        string r = "";
        
        for (int j = i; j < t.length(); j++) {
            r += t[j];
            
            if (i + 5 < j)
                break;
            
            if (s.find(r) != s.end())
                if (dp[j + 1] != INT_MAX)
                    dp[i] = min(dp[i], dp[j + 1] + 1);
        }
    }
    
    return dp[0] != INT_MAX ? dp[0] : -1;
}
