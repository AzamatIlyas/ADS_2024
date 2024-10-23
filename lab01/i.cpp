#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<int> sak;
    queue<int> kat;
    
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < n; i++){
        if(s[i] == 'K'){
            kat.push(i);
        }else{
            sak.push(i);
        }
    }

    while(!sak.empty() && !kat.empty()){
        int k = kat.front();
        int sa = sak.front();
        kat.pop();
        sak.pop();

        if(sa < k){
            sak.push(sa+n);
        }else{
            kat.push(k+n);
        }
    }

    if(sak.empty()){
        cout << "KATSURAGI";
    }else{
        cout << "SAKAYANAGI";
    }
     

}