#include <iostream>
#include <cmath>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int value){
        this ->data = value;
        this->next = nullptr;
    }
};
class LinkedList{
public:
    Node* head;

    LinkedList(){
        this->head = nullptr;
    }

    void insert(int data){
        Node* newElement = new Node(data);
        if(!head){
            head = newElement;
            return;
        }
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newElement;
    }

    int NearestNum(int k){
        Node* current;
        current = head;
        int i = 0;
        int minIndex = 0;
        int near = head->data; //7
        int distance =abs(head -> data - k); //5
        while(current->next){ // 2
            if(abs(current->data - k) < distance){
                distance = abs(current->data - k);
                minIndex = i;
                
            }current = current->next;
            i++;
        }
        return minIndex;
        
    }
};

int main(){ 
    LinkedList LL;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int san;
        cin>>san;
        LL.insert(san);
    }
    int k;
    cin>>k;
    int index = LL.NearestNum(k);
    cout << index;

}