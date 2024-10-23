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

    void insert(int value){
        Node* newElement = new Node(value);

        if(!root){
            root = newElement;
            return;
        }
        
        Node* current = root;

        while(true){
            if(value < current->data){
                if(!current->left){
                    current->left = newElement;
                    break;
                }else{
                    current = current->left;
                }
            }else{
                if(!current->right){
                    current->right = newElement;
                    break;
                }else{
                    current = current->right;
                }
            }
        }
    }


    int triangleCheck(Node* node){
        if(!node) return 0;

        if(node->left && node->right){
            count++;
        }

        int l = triangleCheck(node->left);
        int r = triangleCheck(node->right);

        return count+1;
    }

    int getCount(){
        return count;
    }



};



int main(){
    BinaryTree bt;

    int san; cin >> san;
    for(int i = 0; i < san; i++){
        int a; cin >> a;
        bt.insert(a);
    }

    bt.triangleCheck(bt.root);

    cout << bt.getCount();

    return 0;
}