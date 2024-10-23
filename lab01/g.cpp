#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    stack<int> prime;
    stack<int> superprime;
    superprime.push(3);
    prime.push(2);
    for(int i = 3; superprime.size() < n; i++){
        for(int j = 2; j < i; j++){
            if(i%j == 0){
                break;
            }else if(i%j != 0 && i-1==j){
                prime.push(i);
                for(int k = 2; k < prime.size(); k++){
                    if(prime.size() % k == 0){
                        break;
                    }else if(prime.size()%k != 0 && prime.size()-1==k ){
                        superprime.push(i);
                    }
                }
            }
        }

    } 
    cout << superprime.top();
    
}