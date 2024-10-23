#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    Node* next;
    Node* prev;

    Node(char value){
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};




class LinkedList{
    public:
    Node* head;
    Node* tail;
    int len;


    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
    }


    void processStream(int N) {
        unordered_map<char, int> freq;
        queue<char> q;  
    
        for (int i = 0; i < N; ++i) {
            char ch; cin >> ch;
        
            freq[ch]++;

            if (freq[ch] == 1) {
                q.push(ch);
            }
        
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
        
            if (!q.empty()) {
                cout << q.front() << " ";
            } else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }

    // bool find(char a){
    //     Node* current = tail->prev;
    //     while(current){
    //         if(current->data == a){
    //             return true;
    //         }else{
    //             return false;
    //         }
    //         current = current->prev;
    //     }
    // }

    // void insert(char book){
    //     Node* newNum = new Node(book);
    //     if(!head){
    //         head = newNum;
    //         tail = newNum;
    //         len++;
    //         ss.push(book);
    //         return;
    //     }else{
    //         tail->next = newNum;
    //         newNum->prev = tail;
    //         tail = newNum;
    //         len++;
    //     }

    //     Node* current = newNum;
    //     Node* bas = head;
    //     if(find(book)){
    //         whil
    //     }
        
    // }

    

    
};


int main(){
    LinkedList ll;
    int t;
    cin >> t;  // Количество тестов
    
    while (t--) {
        int N;
        cin >> N;  // Количество символов в потоке
        ll.processStream(N);
    }


    return 0;
}