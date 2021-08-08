#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long t_min = (long long)*min_element(times.begin(), times.end());
    long long t_max = (long long)*max_element(times.begin(), times.end()) * n;

    while (t_min <= t_max) {
        long long t_mid = (t_min + t_max) / 2;

        long long t = 0;
        for (const auto& n : times)
            t += (t_mid / n);
        
        if (t < n)
            t_min = t_mid + 1;
        else
            t_max = t_mid - 1;
    }

    return t_min;
}
