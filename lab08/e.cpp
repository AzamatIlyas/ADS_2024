#include <bits/stdc++.h>

using namespace std;

char rabinKarp(long long san, long long n,long long prev){

    long long current = san - prev;

    char letter = (char)((long long)(current / (long long)pow(2,n)) + 97);

    return letter;

}



int main(){

    long long n; cin >> n;
    string s = "";
    long long prev = 0;
    for(long long i = 0; i < n; i++){
        long long a; cin >> a;
        char letter = rabinKarp(a,i,prev);
        s += letter;
        prev = a;
    }

    cout << s;

    return 0;
}