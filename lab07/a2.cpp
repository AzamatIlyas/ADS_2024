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

    while(i < n1 && j < n2){
        if(leftArray[i].size() <= rightArray[j].size()){
            vec[k] = leftArray[i];
            i++;
        }else {
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


void mergeSort(vector<string>& vec, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}


int main(){
    int san; 
    cin >> san;
    cin.ignore(); // Очистка буфера после чтения числа

    for(int i = 0; i < san; i++){
        string s; 
        getline(cin, s); // Ввод строки

        vector<string> word;
        string letter = "";
        
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ' ' && !letter.empty()){  // Если встречаем пробел и слово непустое
                word.push_back(letter);           // Добавляем слово в вектор
                letter = "";                      // Очищаем строку для нового слова
            }else if(s[j] != ' '){                // Если это не пробел, добавляем символ в слово
                letter += s[j];
            }
        }

        if(!letter.empty()){                      // Добавляем последнее слово, если оно непустое
            word.push_back(letter);
        }

        mergeSort(word, 0, word.size() - 1);      // Сортируем слова по длине

        for(int j = 0; j < word.size(); j++){
            cout << word[j] << " ";               // Вывод отсортированных слов
        }
        cout << endl;
    }

    return 0;
}
