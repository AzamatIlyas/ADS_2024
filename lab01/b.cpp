#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n; cin >> n;
    vector<long long> dq(n);

    vector<long long> dq2(n);

    for(int i = 0; i < n; i++){
        cin >> dq[i];
        dq2[i] = dq[i];
    }

    vector<long long> vec(n);

    for(int i = 0; i < n; i++){
        long long min = -1;
        for(int j = i-1; j >= 0;j--){
            if(dq[j] <= dq[i]){
                min = dq[j];
                break;
            }
        }
        vec[i]=min;
        
    }

    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    
    return 0;
}
