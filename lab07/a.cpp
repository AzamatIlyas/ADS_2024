#include <bits/stdc++.h>

using namespace std;

void merge(vector<string>& vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> leftArray(n1), rightArray(n2);

    for(int i = 0; i < n1; i++){
        leftArray[i] = vec[left+i];
    }
    for(int i = 0; i < n2; i++){
        rightArray[i] = vec[mid+i+1];
    }

    int i = 0, j = 0, k = left;

    while(n1 > i && n2 > j){
        if(leftArray[i].size() <= rightArray[j].size()){
            vec[k] = leftArray[i];
            i++;
        }else {
            vec[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(n1 > i){
        vec[k] = leftArray[i];
        i++;
        k++;
    }

    while(n2 > j){
        vec[k] = rightArray[j];
        j++;
        k++;
    }

}


void mergeSort(vector<string>& vec, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}


int main(){

    int san; cin >> san;
    cin.ignore();

    for(int i = 0; i < san; i++){
        string s; getline(cin, s);

        vector<string> word;
        string letter = "";
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ' ' && !letter.empty()){
                word.push_back(letter);
                letter = "";
            }else if(s[j] != ' '){
                letter+=s[j];
            }
        }

        if(!letter.empty()){
            word.push_back(letter);
        }

        mergeSort(word, 0, word.size() - 1);

        for(int j = 0; j < word.size(); j++){
            cout << word[j] << " " ;
        }
        cout << endl;
    }
    

    return 0;
}