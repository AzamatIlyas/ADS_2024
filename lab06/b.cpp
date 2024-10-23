#include <bits/stdc++.h>

using namespace std;


void merge(vector<int>& vec, int left, int mid, int right){
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1), rightArray(n2);

    for(int i = 0; i < n1; i++){
        leftArray[i] = vec[left+i];
    }
    for(int i = 0; i < n2; i++){
        rightArray[i] = vec[mid+i+1];
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

void mergeVector(vector<int>& first, vector<int>& second){
    
    int i = 0, j = 0;

    int n1 = first.size();
    int n2 = second.size();

    vector<int> zhana;

    while(i < n1 && j < n2){
        if(first[i] == second[j]){
            zhana.push_back(first[i]);
            i++;
            j++;
        }else if(first[i] > second[j]){
            j++;
        }else if(first[i] < second[j]){
            i++;
        }
    }

    for(int num : zhana){
        cout << num << " " ;
    }
}

int main(){

    int n,m; cin >> n >> m;

    vector<int> first(n);
    vector<int> second(m);

    for (int i = 0; i < n; i++)
    {
        cin >> first[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> second[i];
    }

    mergeSort(first, 0, n - 1);
    mergeSort(second, 0, m - 1);

    mergeVector(first,second);

    return 0;
}