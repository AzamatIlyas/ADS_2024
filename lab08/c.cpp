#include <bits/stdc++.h>

using namespace std;

const long long p = 231;
const long long mod = 1000000007;

long long rabinKarp(string s){

    long long n = s.size();
    long long res = 0;

    for(long long i = 0; i < s.size(); i++){
        res = (res * p + s[i])%mod;
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

    string s; cin >> s;
    long long n; cin >> n;

    long long len = s.size();

    long long count = 0;

    string ex = "";

    for(long long i = 0; i < len; i++){
        ex+="#";
    }

    vector<string> words(n);

    for(long long i = 0; i < n; i++){
        cin >> words[i];
        count += words[i].size();
    }

    for(long long i = 0; i < n; i++){
        long long m = words[i].size();
        long long first = rabinKarp(s.substr(0, m));
        long long second = rabinKarp(words[i]);
        long long p_m1 = power(p, m-1, mod);

        for(long long j = 0; j <= len - m; j++){
            if(first == second){
                ex.replace(j,m,words[i]);
            }

            if(j + m < len){
                first = ((first - s[j] * p_m1 % mod + mod) % mod * p + s[j+m]) % mod;
                if(first < 0){
                    first += mod;
                }
            }
        }

    }

    if(ex == s){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}