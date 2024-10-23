#include <bits/stdc++.h>

using namespace std;

vector<long long> heap;

void swap (long long& a, long long& b){
    long long temp = a;
    a = b;
    b = temp;
}

long long parent(long long i){
    return (i - 1) / 2;
}

long long leftChild(long long i){
    return 2*i + 1;
}

long long rightChild(long long i){
    return 2*i + 2;
}

void heapifyUp(long long i){
    while(i != 0 && heap[i] < heap[parent(i)]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void heapifyDown(long long i){
    long long smallest = i;
    long long left = leftChild(i);
    long long right = rightChild(i);

    if(left < heap.size() && heap[left] < heap[smallest]){
        smallest = left;
    }
    
    if(right < heap.size() && heap[right] < heap[smallest]){
        smallest = right;
    }

    if (smallest != i){
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(long long key){
    heap.push_back(key);
    long long i = heap.size() - 1;
    heapifyUp(i);
}

long long extractMin(){
    if (heap.empty()){
        cout << "Heap is empty\n";
        return 0;
    }
    long long min = heap[0];
    long long back = heap.size() - 1;
    heap[0] = heap[back];
    heap.pop_back();

    heapifyDown(0);

    return min;

}



int main() {
    long long n;    
    cin >> n;
    for (long long i = 0; i < n; ++i){
        long long k;
        cin >> k;
        insert(k);
    }
    long long total = 0;
    for(long long i = 1; i < n; ++i){
        long long tmp = extractMin() + extractMin();
        total += tmp;
        insert(tmp);
    }

    cout << total;
    return 0;
}