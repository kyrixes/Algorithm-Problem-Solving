#include <bitset>

int count(int n) {
    int bits = 0;
    while (n) {
        bits += (n & 1);
        n >>= 1;
    }
    
    return bits;
}

int solution(int n) {
    int bits = count(n);
    
    while (bits != count(++n));
    
    return n;
}
