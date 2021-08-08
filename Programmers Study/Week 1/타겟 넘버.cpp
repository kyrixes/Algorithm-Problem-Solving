#include <vector>

using namespace std;

int add_recursive(vector<int>& numbers, int target, int i, int sum) {
    if (i == numbers.size())
        return (sum == target) ? 1 : 0;
    
    return add_recursive(numbers, target, i + 1, sum + numbers[i]) +
            add_recursive(numbers, target, i + 1, sum - numbers[i]);
}

int solution(vector<int> numbers, int target) {
    return add_recursive(numbers, target, 0, 0);
}
