#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    stack<int> prime;
    prime.push(2);
    
    for(int i = 3; prime.size() < n; i++){
        for(int j = 2; j < i; j++){
            if(i%j == 0){
                break;
            }else if(i%j != 0 && i-1==j){
                prime.push(i);
            }
        }
    } 
    cout << prime.top();
    
}