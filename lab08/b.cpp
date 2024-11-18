#include <bits/stdc++.h>

using namespace std;

const int p = 231;
const long long mod = 1000000007;

long long hashing(string s){
    long long res = 0;

    for(int i = 0; i < s.length(); i++){
        res = (res * p + s[i]) % mod;
    }

    return res;
}

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main(){

    string first; cin >> first;
    string second; cin >> second;
    string third; cin >> third;

    long long m = third.size();
    long long n = (first.size() < second.size()) ? first.size() : second.size();

    long long firstHash = hashing(first.substr(0,m));
    long long secondHash = hashing(second.substr(0,m));
    long long thirdHash = hashing(third);

    long long p_m1 = power(p, m - 1, mod);

    long long count = 0;

    for(int i = 0; i <= n-m; i++){
        if(firstHash == thirdHash && firstHash == secondHash){
            count++;
        }

        if(i + m < n){
            firstHash = ((firstHash - first[i] * p_m1 % mod + mod) % mod * p + first[i+m]) % mod;
            secondHash = ((secondHash - second[i] * p_m1 % mod + mod) % mod * p + second[i+m]) % mod;
            
            if(firstHash < 0) firstHash+=mod;
            if(secondHash < 0) secondHash+=mod;
        }
    }

    cout << count;

    return 0;
}