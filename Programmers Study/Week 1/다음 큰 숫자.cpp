#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<vector<int>> patterns {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };

    vector<int> scores(patterns.size(), 0);

    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < patterns.size(); j++) {
            if (answers[i] == patterns[j][i % patterns[j].size()])
                scores[j]++;
        }
    }
    
    int score_max = *max_element(scores.begin(), scores.end());
    
    vector<int> answer;
    for (int i = 0; i < scores.size(); i++) {
        if (score_max <= scores[i]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
