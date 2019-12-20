#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *previous;
    node(int val) {
        this->val = val;
        previous = NULL;
    }
};
node *top = NULL;
void push(int val) {
    node *newnode = new node(val);
    newnode->previous = top;
    top = newnode;
}
void pop() {
    if(top == NULL) {
        cout << "Stack Underflow" << endl;; 
        exit(1);
    } else {
        node *temp = top;
        top = top->previous;
        temp->previous = NULL;
        delete(temp);
    }
}
bool isEmpty() {
    return top == NULL;
}
int topelement() {
    if(top == NULL) {
        cout << "Stack Underflow" << endl;; 
        exit(1);
    }
    return top->val;
}
void display(node *root = top) {
    if(root == NULL) {
        return;
    }
    cout << root->val << endl;
    display(root->previous);
} 
int main() {
    push(11);
    push(12);
    cout << topelement() << endl;
    pop();
    display();
    cout << topelement() << endl;
    pop();
    pop();
    return 0;
}