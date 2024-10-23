#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> boris;
    deque<int> nursik;
    for(int i = 0; i < 5; i++){
        int a;cin >> a;
        boris.push_back(a);
    }

    for(int i = 0; i < 5; i++){
        int a;cin >> a;
        nursik.push_back(a);
    }

    long long game = 0;
    while(!nursik.empty() && !boris.empty() && game <= 1000000){
        int b = boris.front();
        int n = nursik.front();

        boris.pop_front();
        nursik.pop_front();
        
        if(n == 9 && b == 0){
            boris.push_back(b);
            boris.push_back(n);
        }else if(b == 9 && n == 0){
            nursik.push_back(b);
            nursik.push_back(n);
        }else if(b>n){
            boris.push_back(b);
            boris.push_back(n);
        }else if(b<n){
            nursik.push_back(b);
            nursik.push_back(n);
        }
        game+=1;
    }
    
    if(nursik.empty()){
        cout << "Boris " << game; 
    }else if(boris.empty()){
        cout << "Nursik " << game;
    }else {
        cout << "blin nichya";
    }


}