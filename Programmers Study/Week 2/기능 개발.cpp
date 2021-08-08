#include <vector>

using namespace std;

vector<int> remains (vector<int>& p, vector<int>& s) {
    vector<int> r;
    
    for (int i = 0; i < p.size(); i++) {
        int t = 100 - p[i];
        r.push_back((t / s[i]) + (t % s[i] != 0));
    }
    
    return r;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> times = remains(progresses, speeds);
    
    for (int i = 0; i < times.size(); i++) {
        int t = times[i];
        
        for (int j = 0; j < times.size(); j++)
            times[j] -= t;
        
        int a = 0;
        for (int k = i; k < times.size(); k++) {
            if (times[k] <= 0) {
                a++;
                i = k;
            }
            else break;
        }
        
        answer.push_back(a);
    }
    
    return answer;
}
