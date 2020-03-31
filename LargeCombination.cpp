#include <bits/stdc++.h>


long long combination(int c, int k) {
    long long numerator = 1;
    long long denominator = 1;
    long long counter = 1;
    for(long long i = c; i > c-k; i--){
        numerator *= i;
        denominator *= counter++;
    }
    return numerator/denominator;
}
