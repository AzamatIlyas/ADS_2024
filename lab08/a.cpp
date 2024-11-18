#include <bits/stdc++.h>

using namespace std;

string rabinKarp(string text){
    long long mod = 1000000007;

    long long hash_sum = 0;

    long long len = text.size();

    long long power = 1;

    for(long long i = 0; i < len; i++){
        long long san = text[i];
        long long div = (san - 47 + mod) % mod;
        hash_sum = (hash_sum + (div % mod * power) % mod) % mod;
        power = (power * 11) % mod ;
    }

    string result = to_string(hash_sum);

    return result;
}

int main(){

    int n; cin >> n;

    vector<string> vec(n*2);
    map<string, string> newbie;

    for(int i = 0; i < n*2; i++){
        cin >> vec[i];
        string str = rabinKarp(vec[i]);
        newbie.insert(make_pair(vec[i], str));
    }

    int count = 0;

    for(string a : vec){
        string text = rabinKarp(a);
        if(newbie.find(text) != newbie.end()){
            cout << "Hash of string \"" << a << "\" is " << text << "\n";
            count++;
        }
        if(count == n){
            break;
        }
    }  


    return 0;
}