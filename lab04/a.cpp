#include <bits/stdc++.h>

using namespace std;


class Node{
    public:
    int value;
    Node* right;
    Node* left;

    Node(int data){
        this->value = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree{
    public:
    int len = 0;
    Node* root;

    BinaryTree(){
        this->root = nullptr;
    }


    void insert(int data){
        Node* newElement = new Node(data);

        if(!root){
            root = newElement;
            len++;
            return;
        }

        Node* current = root;

        while(true){
            if (data < current->value){
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

    void checkWay(string way){
        Node* current = root;

        for(int i = 0; i < way.size(); i++){
            if(way[i] == 'L'){
                if(current->left){
                    current = current->left;
                }else{
                    cout << "NO" << endl;
                    return;
                }
            }else if(way[i] == 'R'){
                if(current->right){
                    current = current->right;
                }else{
                    cout << "NO" << endl;
                    return;
                }
            }
        }

        cout << "YES" << endl;
    }
};

int main(){

    BinaryTree bt;

    int n; cin >> n;
    int m; cin >> m;

    for(int i = 0; i < n; i++){
        int san; cin >> san;
        bt.insert(san);
    }

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        bt.checkWay(s);
    }



    return 0;
}