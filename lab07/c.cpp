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
        if(leftArray[i] <= rightArray[j]){
            vec[k] = leftArray[i];
            i++;
        }else{
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


void mergeVectors(vector<int>& leftArray, vector<int>& rightArray){
    int n1 = leftArray.size();
    int n2 = rightArray.size();

    int i = 0, j = 0, k = 0;

    vector<int> vec(n1+n2);

    while(n1 > i && n2 > j){
        if(leftArray[i] == rightArray[j]){
            vec[k] = leftArray[i];
            i++;
            j++;
        }else if(leftArray[i] == rightArray[j]){
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

    for(int l = 0; l < n1+n2; l++){
        cout << vec[l] << " ";
    } 
}


int main(){

    int san; cin >> san;
    int num; cin >> num;

     
    

    return 0;
}