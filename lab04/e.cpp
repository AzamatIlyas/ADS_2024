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

    void insert(int bas, int value, int id){
        Node* newElement = new Node(value);

        // Node* parent = new 

        if(!root){
            Node* mile = new Node(bas);
            root = mile;
        }

        Node* current = getLink(root,bas);

        if(id == 0){
            current->left = newElement;
        }else{
            current->right = newElement;
        }
        
    }

    Node* getLink(Node* node, int num){
        if (!node) {
            return nullptr; // Если узел пуст, возвращаем null
        }

        if (node->data == num) {
            return node; // Если нашли нужный узел, возвращаем его
        }

        // Ищем в левом поддереве
        Node* leftSearch = getLink(node->left, num);
        if (leftSearch) {
            return leftSearch;
        }

        // Если не нашли в левом, ищем в правом поддереве
        return getLink(node->right, num);
    }

    int getMax(){

        int maxLevel = 0;

        queue<Node*> q;
        q.push(root);

        int maxNum = 0;

        while(!q.empty()){
            int levelSize = q.size();

            if(levelSize > maxNum){
                maxNum = levelSize;
            }

            for(int i = 0; i < levelSize; i++){
                Node* current = q.front();
                q.pop();

                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
        }

        return maxNum;
    }


};



int main(){
    BinaryTree bt;

    int san; cin >> san;
    for (int i = 0; i < san-1; i++){
        int a; cin >> a;
        int b; cin >> b;
        int c; cin >> c;
        bt.insert(a,b,c);
    }

    cout << bt.getMax();


    return 0;
}