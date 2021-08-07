#include <string>

using namespace std;

bool check (string p) {
    int prechk = 0;
    
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') {
            prechk++;
        }
        else {
            prechk--;
            if (prechk < 0) {
                return false;
            }
        }
    }
    
    return true;
}

string solution (string p) {
    if (p == "") return "";
    
    string u, v;
    
    int left = 0; int right = 0;
    
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            left++;
        else
            right++;

        if (left == right) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    
    if (check(u))
        return u + solution(v);
    
    string temp = "(" + solution(v) + ")";
    
    for (int i = 1; i < u.length() - 1; i++)
        temp += (u[i] == '(') ? ')' : '(';
    
    return temp;
}
