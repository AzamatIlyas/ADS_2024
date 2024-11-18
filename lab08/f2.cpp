#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

// long long rabinKarp(string s){

//     long long p = 1;

//     long long n = s.size();

//     long long sum = 0;

//     for(long long i = 0; i < n; i++){
//         sum = (sum + s[i] * p) % mod;
//         p = (p*231);
//     }

//     return sum;

// }



int main(){

    string s; cin >> s;

    map<long long,bool> myMap;

    for(long long i = 0; i < s.size(); i++){

        long long current = 0;
        long long p_pow = 1;

        for(long long j = i; j < s.size(); j++){
            current = (current + s[j] * p_pow) % mod;
            p_pow = (p_pow*231);
            myMap[current] = true;
        }
    }

    cout << myMap.size();

    return 0;
}