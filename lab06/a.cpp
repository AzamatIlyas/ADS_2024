#include <bits/stdc++.h>

using namespace std;


void merge(vector<char>& vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<char> leftArray(n1), rightArray(n2);

    for(int i = 0; i < n1; i++){
        leftArray[i] = vec[left+i];
    }
    for(int i = 0; i < n2; i++){
        rightArray[i] = vec[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if((leftArray[i] == 'a' || leftArray[i] == 'e' || leftArray[i] == 'i' || leftArray[i] == 'o' || leftArray[i] == 'u') && 
        (rightArray[j] == 'a' || rightArray[j] == 'e' || rightArray[j] == 'i' || rightArray[j] == 'o' || rightArray[j] == 'u')){
            if(leftArray[i] <= rightArray[j]){
                vec[k] = leftArray[i];
                i++;
            }else{
                vec[k] = rightArray[j];
                j++;
            }
        }else if(leftArray[i] == 'a' || leftArray[i] == 'e' || leftArray[i] == 'i' || leftArray[i] == 'o' || leftArray[i] == 'u'){
            vec[k] = leftArray[i];
            i++;
        }else if(rightArray[j] == 'a' || rightArray[j] == 'e' || rightArray[j] == 'i' || rightArray[j] == 'o' || rightArray[j] == 'u'){
            vec[k] = rightArray[j];
            j++;
        }else{
            if(leftArray[i] <= rightArray[j]){
                vec[k] = leftArray[i];
                i++;
            }else{
                vec[k] = rightArray[j];
                j++;
            }
        }
        k++;
    }

    while(i < n1){
        vec[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2){
        vec[k] = rightArray[j];
        j++;
        k++;
    }
}


void mergeSort(vector<char>& vec, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}




int main(){

    int n; cin >> n;

    string s; cin >> s;

    vector<char> letter(n);

    for(int i = 0; i < n; i++){
        letter[i] = s[i];
    }

    mergeSort(letter, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << letter[i] ;
    } 


    return 0;
}