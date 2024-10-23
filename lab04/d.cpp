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

    int getHeight(Node* node){
        if(!node) return 0;

        int l = getHeight(node->left);
        int r = getHeight(node->right);

        return 1 + max(l,r);
    }


    void getTree(){
        if(!root) return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            int levelSum = 0;

            for(int i = 0; i < levelSize; i++){
                Node* current = q.front();
                q.pop();
                levelSum += current->data;

                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }

            cout << levelSum << " ";
        }
    }




};



int main(){
    BinaryTree bt;

    int san; cin >> san;
    for(int i = 0; i < san; i++){
        int a; cin >> a;
        bt.insert(a);
    }

    cout << bt.getHeight(bt.root) << endl;
    bt.getTree();

    return 0;
}