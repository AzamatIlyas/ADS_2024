#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = nullptr;
    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    int len;
    int era;

    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
        this->era = 0;
    }

    void insert(int data){
        Node* newElement = new Node(data);
        if(!head){
            head = newElement;
            tail = newElement;
            return;
        }
        else{
            tail->next = newElement;
            tail = tail->next;
        }
        len++;
        
    }


    void getFirst(){
        Node* current;
        current = head;
        while(current){
            if(era%2 == 0){
                cout << current->data << " ";
            }
            current = current->next;
            era++;
        }

    }

    

    void print(){
        Node* step = head;
        while(step!=NULL){
            cout << step -> data << ' ';
            step = step->next;
        }
    }

};


int main(){
    LinkedList ll;
    int san; cin >> san;
    for(int i = 0; i < san; i++){
        int a; cin >> a;
        ll.insert(a);
    }
    ll.getFirst();
    

    return 0;
}