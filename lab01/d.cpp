#include <bits/stdc++.h>
using namespace std;
int main(){
    string balance;
    cin >> balance;
    deque<char> name;

    bool ok = true;

    while(ok){
        for(int i = 0; i < balance.size(); i++){
            name.push_back(balance[i]);
            for(int j = 1; j < name.size(); j++){
                if(name[j] == name[j-1] ){
                    name.pop_back();
                    name.pop_back();
                }
            }
        }
        break;
    }   
    if(name.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }


}