#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
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


    void getModa(){
        Node* current;

        current = head;
        

        vector<int> vec;
        unordered_map<int,int> aza;
        
        while(current){
            vec.push_back(current->data);
            current = current -> next;
        }

        for(int num : vec){
            aza[num]++;
        }

        int max_elem = 0;
        for(const auto& pair:aza){
            if(pair.second > max_elem){
                max_elem = pair.second;
            }
        }

        vector<int> modes;
        for(const auto& pair:aza){
            if(pair.second == max_elem){
                modes.push_back(pair.first);
            }
        }

        sort(modes.rbegin(),modes.rend());

        for(int i = 0; i < modes.size(); i++){
            cout << modes[i] << " ";
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
        int a ;cin >> a;
        ll.insert(a);
    }

    ll.getModa();

    
    return 0;
}