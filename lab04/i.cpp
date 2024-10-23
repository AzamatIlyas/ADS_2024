#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree{
    public:
    Node* root;
    Node* tobe;
    int count = 0;

    BinaryTree(){
        this->root = nullptr;
    }

    Node* insert(Node* node, int value){
        if(node == nullptr){
            return new Node(value);
        }

        if(value < node->data){
            node->left = insert(node->left, value);
        }
        else{
            node->right = insert(node->right, value);
        }

        return node;
    }

    
    void remove(int value){
        Node* current = root;
        if(current->data == value;)
    }
    

    


};



int main(){
    BinaryTree bt;

    int san; cin >> san;
    for(int i = 0; i < san; i++){
        string s ; cin >> s;
        int a; cin >> a;
        if(s == "insert"){
            bt.insert(bt.root, a);
        }else if(s == "delete"){

        }
    }






    return 0;
}