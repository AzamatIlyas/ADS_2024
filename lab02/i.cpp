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

    void add_back(string book){
        Node* newBook = new Node(book);
        if(!head){
            head=newBook;
            tail=newBook;
        }else{
            tail->next = newBook;
            newBook->prev = tail;
            tail = newBook;
        }
        len++;
    }

    void add_front(string book){
        Node* newBook = new Node(book);
        if(!head){
            head = newBook;
            tail = newBook;
        }else{
            head->prev = newBook;
            newBook->next = head;
            head = newBook;
        }
        len++;
    }

    void erase_front(){
        Node* current = head;
        if(len == 0){
            cout << "error" << endl;
        }else if(len == 1){
            cout << head->data << endl;
            delete current;
            head = nullptr;
            tail = nullptr;
            len--;
        }else{
            cout << head->data << endl;
            Node* currentNext = current->next;
            current->next = nullptr;
            currentNext->prev = nullptr;
            head = currentNext;
            len--;
        }
    }

    void erase_back(){
        Node* current = tail;
        if(len == 0){
            cout << "error" << endl;
        }else if(len == 1){
            cout << tail->data << endl;
            delete current;
            head = nullptr;
            tail = nullptr;
            len--;
        }else {
            cout << tail->data << endl;
            Node* currentPrev = current->prev;
            current->prev = nullptr;
            currentPrev->next = nullptr;
            tail = currentPrev;
            len--;
        }
    }

    void front(){
        if(len == 0){
            cout << "error" << endl;
        }else{
            cout << head->data << endl;
        }
    }

    void back(){
        if(len == 0){
            cout << "error" << endl;
        }else{
            cout << tail->data << endl;
        }
    }

    void clear(){
        Node* current = head;;
        while(current){
            Node* currentNext = current->next;
            delete current;
            current = currentNext;
        }

        head = nullptr;
        tail = nullptr;
        len = 0;
    }


    

    

    

};


int main(){
    LinkedList ll;
    string line;

    while(cin >> line){
        if(line == "exit"){
            cout << "goodbye" << endl;
            break;
        }else if(line == "add_front"){
            string name; cin >> name;
            ll.add_front(name);
            cout << "ok" << endl;
        }else if(line == "add_back"){
            string name; cin >> name;
            ll.add_back(name);
            cout << "ok" << endl;
        }else if(line == "erase_back"){
            ll.erase_back();
        }else if(line == "erase_front"){
            ll.erase_front();
        }else if(line == "back"){
            ll.back();
        }else if(line == "front"){
            ll.front();
        }else if(line == "clear"){
            ll.clear();
            cout << "ok" << endl;
        }
    }


    return 0;
}