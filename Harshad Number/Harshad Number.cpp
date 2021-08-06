bool solution (int x) {
    int sum = 0;
    for (int t = x; t != 0; t /= 10) { sum += t % 10; }
    return x % sum == 0;
}
