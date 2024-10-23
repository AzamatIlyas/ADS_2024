#include <bits/stdc++.h>

using namespace std;


void merge(vector<int>& vec, int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1), rightArray(n2);

    for(int i = 0; i < n1; i++){
        leftArray[i] = vec[left + i];
    }
    for(int i = 0; i < n2; i++){
        rightArray[i] = vec[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(leftArray[i] <= rightArray[j]){
            vec[k] = leftArray[i];
            i++;
        }else{
            vec[k] = rightArray[j];
            j++;
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

void mergeSort(vector<int>& vec, int left, int right){
    if(left < right){

        int mid = left + (right - left)/2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

void minDif(vector<int>& vec){

    int min = 100000000;

    int i = 0;
    
    while(i < vec.size()-1){
        if(abs(vec[i] - vec[i+1]) < min){
            min = abs(vec[i] - vec[i+1]);
        }
        i++;
    }

    for(int i = 0; i < vec.size() - 1; i++){
        if(abs(vec[i] - vec[i+1]) == min){
            cout << vec[i] << " " << vec[i+1] << " ";
        }
    }
}

int main(){

    int n; cin >> n;

    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    mergeSort(vec, 0, n - 1);

    minDif(vec);

    return 0;
}