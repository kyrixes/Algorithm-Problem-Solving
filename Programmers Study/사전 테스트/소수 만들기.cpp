#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

vector<int> primes;

bool isPrime (int n) {
    for (int i = 2; i <= sqrt(n) && n > 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

void pick (vector<int>& nums, vector<int>& picked, int index) {
    if (picked.size() == 3) {
        primes.push_back(accumulate(picked.begin(), picked.end(), 0));
        return;
    }
    
    for (int i = index; i < nums.size(); i++) {
        picked.push_back(nums[i]);
        pick(nums, picked, i + 1);
        picked.pop_back();
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    
    vector<int> picked;
    
    pick(nums, picked, 0);
    
    for (int i = 0; i < primes.size(); i++) {
        answer += isPrime(primes[i]);
    }
    
    return answer;
}
