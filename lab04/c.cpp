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
    int len = 0;

    BinaryTree(){
        this->root = nullptr;
    }

    void insert(int value){
        Node* newElement = new Node(value);

        if(!root){
            root = newElement;
            len++;
            return;
        }
        
        Node* current = root;

        while(true){
            if(value < current->data){
                if(!current->left){
                    current->left = newElement;
                    len++;
                    break;
                }else{
                    current = current->left;
                }
            }else{
                if(!current->right){
                    current->right = newElement;
                    len++;
                    break;
                }else{
                    current = current->right;
                }
            }
        }
    }

    void getTobe(int num){
        Node* current = root;

        while(true){
            if(num == current->data){
                break;
            }
            if(current->data > num){
                current = current->left;
            }else{
                current = current->right;
            }
        }

        tobe = current;
        
        
    }

    void getGift(Node* node){
        if(!node) 
        {
            return;
        }

        
        cout << node->data << " ";
        
        getGift(node->left);
        getGift(node->right);
    }



};



int main(){
    BinaryTree bt;

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        bt.insert(a);
    }

    int men; cin >> men;
    bt.getTobe(men);

    bt.getGift(bt.tobe);

    return 0;
}