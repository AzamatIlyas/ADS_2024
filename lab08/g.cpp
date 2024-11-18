#include <iostream>

using namespace std;

const long long p = 231;
const long long mod = 1000000007;

long long rabinKarp(string s){

    long long n = s.size();

    long long sum = 0;

    long long p_pow = 1;

    for(long long i = 0; i < n; i++){
        sum = (sum * p + s[i]) % mod;
        // p_pow = p_pow*p;
    }

    return sum;

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

    string s; cin >> s;

    long long n; cin >> n;

    long long len = s.size();

    for(long long i = 0; i < n; i++){
        long long l, r; cin >> l >> r;

        string pattern = s.substr(l-1,r - l + 1);

        long long m = pattern.size();

        long long patternHash = rabinKarp(pattern);

        long long p_m1 = power(p, m-1, mod);

        long long currentHash = rabinKarp(s.substr(0,m));

        long long count = 0;

        for(long long j = 0; j <= len - m; j++){
            if(currentHash == patternHash){
                count++;
            }
            if(j + m < len){
                currentHash = ((currentHash - s[j] * p_m1) * p + s[j+m]) % mod;
                if(currentHash < 0) currentHash += mod;
                // cout << currentHash << endl;
            }
        }

        cout << count << endl;

    } 

    return 0;
}