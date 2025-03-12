#include <iostream>
using namespace std;

class Stack {
    private:
        struct node {
            int data;
            struct node* next;
        };
        struct node * top;
    public:
        Stack(){ top = NULL; }
        ~Stack(){ 
            struct node * temp;
            while(top){
                temp=top;
                top=top->next;
                delete temp;
            }
        }
        bool push(const int item);
        bool pop();
        inline bool StackEmpty() {
            if(top) return false;
            else return true;
        }
};

bool Stack::push(const int item) {
    struct node * temp = new node;
    if(temp) {
        temp->data = item;
        temp->next = top;
        top=temp;
        return true;
    } else {
        cout << "Out of space!" << endl;
        return false;
    }
}

bool Stack::pop() {
    if(StackEmpty()) {
        cout << "Stack is empty" << endl;
        return false;
    } else {
        int item; struct node * temp;
        item=top->data; temp=top;
        top=top->next;
        delete temp; 
        cout << "Poppping: " << item << "." << endl; 
        return true;
    }
}

int main() {
    Stack st = Stack();
    st.push(1);
    st.push(2);
    st.pop();
    st.push(3);
    st.push(4);
    st.pop();
    st.push(5);
    st.push(6);
    st.pop();
    st.push(7);
    st.push(8);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}