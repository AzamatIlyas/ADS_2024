#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<int> dq;
    deque<string> get;
    char a;
    while(cin >> a){
        if(a == '!'){
            break;
        }else if(a == '+'){
            int num ; cin >> num;
            dq.push_front(num);
        }else if(a == '-'){
            int num; cin >> num;
            dq.push_back(num);
        }else if(a == '*'){
            if(dq.empty()){
                cout << "error" << endl;
            }else if(dq.size() == 1){
                cout << dq.back() + dq.front() << endl;
                dq.pop_back();
            }else{
                cout << dq.back() + dq.front() << endl;
                dq.pop_back();dq.pop_front();
            }
        }
    }

}
