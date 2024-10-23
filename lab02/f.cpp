#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int a){
        this->data = a;
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

    void push(int num){
        Node* newNum = new Node(num);
        if(!head){
            head = newNum;
            tail = newNum;
        }else{
            tail->next = newNum;
            newNum->prev = tail;
            tail = newNum;
        }
        len++;
    }


    void getList(int elem, int pos){
        Node* newElement = new Node(elem);
        Node* current;
        Node* thing;
        current = head;

        int i = 0;

        while(current){
            if(i + 1 == pos){
                thing = current->next;
                current->next = newElement;
                newElement->prev = current;
                newElement->next = thing;
                thing->prev = newElement;
                break;
            }
            else if(pos == 0){
                current->prev = newElement;
                newElement->next = current;
                head = newElement;
                break;
            }
            current = current->next;
            i++;
        }

        Node* tek = head;

        while(tek){
            cout << tek->data << " ";
            tek = tek->next;
        }

    }
};











int main(){
    LinkedList ll;
    int san;cin >> san;
    for(int i = 0; i < san; i++){
        int b; cin >> b;
        ll.push(b);
    }
    int c; cin >> c;
    int place; cin >> place;
    ll.getList(c,place);


    return 0;
}