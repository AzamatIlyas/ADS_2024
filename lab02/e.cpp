#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string data;
    Node* next;
    Node* prev;

    Node(string value){
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

    void insert(string data){
        Node* bas;
        bas = head;
        Node* newElement = new Node(data);
        if(!head){
            head = newElement;
            tail = newElement;
            len++;
        }
        else{
            if(head->data == data){
                return;
            }
            else{
                head->prev = newElement;
                head = newElement;
                head->next = bas;
                len++;
            }
        }
        
    }


    void getName(){
        Node* current;
        current = head;
        cout << "All in all: " << len << endl << "Students:" << endl;
        while(current){
            cout << current->data << endl;
            current = current->next;
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
        string s;cin >> s;
        ll.insert(s);
    }
    ll.getName();
    return 0;
}