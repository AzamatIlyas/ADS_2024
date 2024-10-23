#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string data;
    Node* next;

    Node(string value){
        this->data = value;
        this->next = nullptr;
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

    void getString(int san, int q){
        Node* current;
        current = head;
        int i = 0;
        int size = q;
        while(current){
            if(san <= i){
                cout << current->data << " ";
                
                size--;
            }
            i++;
            current = current->next;
        }
        while(size != 0){
            cout << head->data << " ";
            head = head->next;
            size--;
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
    int quantity; cin >> quantity;
    int san ; cin >> san;
    for(int i = 0; i < quantity; i++){
        string s; cin >> s;
        ll.insert(s);
    }

    ll.getString(san,quantity);

    return 0;
}