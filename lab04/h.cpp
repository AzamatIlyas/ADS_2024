#include <bits/stdc++.h>

using namespace std;

int main(){

    int sum = 0;
    int san; cin >> san;
    vector<int> vec;

    for(int i = 0; i < san; i++){
        int a; cin >> a;
        vec.push_back(a);
    }

    sort(vec.rbegin(),vec.rend());

    for(int i = 0; i < san; i++){
        sum = sum + vec[i];
        cout << sum << " ";
    }

    // for(int i = 0; i < san; i++){
    //     cout << vec[i] << " ";
    // }



    return 0;
}