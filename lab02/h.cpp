#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node* next;
    node* prev;

    node(int x){
        prev = next = NULL;
        val = x;
    }
};

struct dll{
    private:
        node* head;
        node* tail;
        int len;
    public:
        dll(){
            head = tail = NULL;
            len = 0;
        }
        
        void insert(int value, int in){
            node* block = new node(value);
            if(len == 0){
                tail = head = block;
            }
            else if(in == 0){
                head -> prev = block;
                block -> next = head;
                head = block;
            }
            else if(in == len){
                tail -> next = block;
                block -> prev = tail;
                tail = block;
            }
            else{
                int i = 0;
                node* step = head;
                while(in != i){
                    i += 1;
                    step = step -> next;
                }
                block -> prev = step -> prev;
                step -> prev -> next = block;
                block -> next = step;
                step -> prev = block;
            }
            len += 1;
        }

        void remove(int in){
            if(len == 1)
                head = tail = NULL;
            else if(in == 0){
                node* block = head;
                head = block -> next;
                head -> prev = NULL;
                delete block;
            }
            else if(in == len - 1){
                node* block = tail;
                tail = block -> prev;
                tail -> next = NULL;
                delete block;
            }
            else{
                int i = 0;
                node* step = head;
                while(in != i){
                    i += 1;
                    step = step -> next;
                }
                step -> next -> prev = step -> prev;
                step -> prev -> next = step -> next;
                delete step;
            }
            len -= 1;
        }

        void print(){
            if(len == 0){
                cout << -1 << endl;
            }
            else{
                node* step = head;
                while(step != NULL){
                    cout << step->val << ' ';
                    step = step->next;
                }
                cout << endl;
            }    
        }  

        void replace(int val1, int val2){
            node* step = head;
            int i = 0;
            while(i != val1){
                step = step -> next;
                i += 1;
            }
            int num = step -> val;
            remove(val1);
            insert(num, val2);
        }

        void reverse(){
            node* step1 = head;
            node* step2 = tail;
            int i = len / 2;
            while(i != 0){
                swap(step1 -> val, step2 -> val);
                step1 = step1 -> next;
                step2 = step2 -> prev;
                i -= 1;
            }
        }

        void cyclic_left(int x){
            while(x){
                insert(head -> val, len);
                remove(0);
                x -= 1;
            }
        }

        void cyclic_right(int x){
            while(x){
                insert(tail -> val, 0);
                remove(len - 1);
                x -= 1;
            }
        }
};

int main(){
    int a;
    dll ll;
    while(cin >> a){
        int c, b;
        if(a == 0)
            break;
        else if(a == 1){
            cin >> c >> b;
            ll.insert(c, b);
        }
        else if(a == 2){
            cin >> c;
            ll.remove(c);
        }
        else if(a == 3){
            ll.print();
        }
        else if(a == 4){
            cin >> c >> b;
            ll.replace(c, b);
        }
        else if(a == 5){
            ll.reverse();
        }
        else if(a == 6){
            cin >> c;
            ll.cyclic_left(c);
        }
        else if(a == 7){
            cin >> c;
            ll.cyclic_right(c);
        }
    }
    return 0;
}