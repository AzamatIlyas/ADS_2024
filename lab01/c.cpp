#include <bits/stdc++.h>
using namespace std;
int main(){
    string str1;
    string str2;
    cin >> str1 >> str2;
    deque<char> first;
    deque<char> second;
    for(int i = 0; i < str1.size();i++){
        first.push_back(str1[i]);
        if(str1[i] == '#'){
            first.pop_back();
            first.pop_back();
        }
    }
    for(int i = 0; i < str2.size();i++){
        second.push_back(str2[i]);
        if(str2[i] == '#'){
            second.pop_back();
            second.pop_back();
        }
    }
    bool ok = true;
    if(first.size() == second.size()){
        for(int i = 0; i < first.size(); i++){
            if(first[i] != second[i]){
                ok = false;
                break;
            }
        }
    }else{
        ok = false;
    }
    if(ok){
        cout << "Yes";
    }else{
        cout << "No";
    }

    
    
}