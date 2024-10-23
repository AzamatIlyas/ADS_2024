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
    int maxSum;
    int len;

    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
        this->maxSum = 0;
    }

    void insert(int num){
        Node* newNum = new Node(num);
        if(!head){
            head = newNum;
            tail = newNum;
            maxSum = num;
            len++;
            return;
        }else{
            tail->next = newNum;
            newNum->prev = tail;
            tail = newNum;
            len++;
        }
        
        Node* current = head;
        Node* leg = current->next;
        Node* thing;

        long long sum = -1000000000;
        int size = len;

        while(current){
            thing = current;
            int count = 0;
            
            int sanau = 0;
            while(sanau < size){

                count+=thing->data;

                thing = thing->next;
                sanau++;
            }

            if(count > sum){
                sum = count;
            }
            current = current->next;
            size--;
        }
         
        if(sum > maxSum){
            maxSum = sum;
        }
         
    }

    int print(){
        return maxSum;
    }



};











int main(){
    LinkedList ll;
    int san; cin >> san;
    for(int i = 0 ; i < san; i++){
        int n ; cin >> n;
        ll.insert(n);
    }
    cout << ll.print();


    return 0;
}