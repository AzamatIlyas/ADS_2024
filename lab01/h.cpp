#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n; cin >> n;
    bool ok = false;
    if(n == 2){
        cout << "YES";
    }else{
        for(int i = 2; i < n; i++){
            if(n%i == 0){
                break;
            }else if( n%i != 0 && i+1==n){
                ok = true;
            }
        }
        if(ok){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }

    return 0;
}
