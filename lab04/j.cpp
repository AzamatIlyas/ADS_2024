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

    

    

    


};



int main(){
    BinaryTree bt;

    int san; cin >> san;
    int n = pow(2,san);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        bt.insert(bt.root, a);
    }




    return 0;
}