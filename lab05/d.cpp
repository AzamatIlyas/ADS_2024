#include <bits/stdc++.h>

using namespace std;

vector<long long> heap;

void heapifyUp(long long i){
    while(i != 0 && heap[(i-1)/2] > heap[i]){
        swap(heap[(i-1)/2],heap[i]);
        i = (i-1)/2;
    }
}

void heapifyDown(long long i){
    long long smallest = i;
    long long left = i*2+1;
    long long right = i*2+2;

    if(left < heap.size() && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(right < heap.size() && heap[right] < heap[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }

}

void insert(long long san){
    heap.push_back(san);
    long long i = heap.size() - 1;
    heapifyUp(i);
    
} 

long long find(){
    if(heap.empty()){
        return 0;
    }
    long long min = heap[0];
    long long back = heap.size() - 1;
    heap[0] = heap[back];
    heap.pop_back();

    heapifyDown(0);

    return min;
}


int main(){
    long long n; cin >> n;
    long long min; cin >> min;
    for(long long i = 0; i < n; i++){
        long long a; cin >> a;
        insert(a);
    }

    bool ok = false;
    long long count = 0;

    for(long long i = 0; heap.size() > 0; i++){
        long long first = find();
        if(first>=min){
            ok = true;
            break;
        }
        if(heap.size() == 1){
            if(first < min){
                break;
            }
        }else{
            long long second = find();
            long long element = first + (second*2);
            count++;
            insert(element);

        }
        
    }

    if(!ok){
        cout << -1;
    }else{
        cout << count;
    }

    return 0;
}