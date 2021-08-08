#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<int, int> state;
    unordered_map<string, bool> spokenWords;
    
    for (int i = 0; i < n; i++)
        state[i + 1] = 0;
    
    for (int i = 0; i < words.size(); i++)
        spokenWords[words[i]] = false;
    
    for (int i = 0; i < words.size() - 1; i++) {
        ++state[(i % n) + 1];
        
        string currentWord = words[i];
        string nextWord = words[i + 1];

        // 다음 단어가 이미 나온 단어 이거나 현재 단어의 맨 뒷 글자와 다음 단어의 첫 글자가 다르다면
        if (spokenWords[nextWord] || (currentWord.back() != nextWord.front())) {
            answer.push_back((i + 1) % n + 1);  // 몇 번째 사람인지
            answer.push_back(((i + 1) % n == 0) ? state[(i % n) + 1] + 1 : state[(i % n) + 1]); // 자신의 몇 번째인지
            return answer;
        }
        
        spokenWords[currentWord] = true;
    }

    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}
