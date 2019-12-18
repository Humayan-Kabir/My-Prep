#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int val) {
        this->val = val;
        left = right = NULL;
    }
};
void inorder(node *root) {
    stack<node *> st;
    node *cur = root;
    while(cur != NULL || !st.empty()) {
        while(cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cout << cur->val << " ";
        cur = cur->right;
    }
    cout << endl;
}
int main() {
    
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    inorder(root);
    return 0;
}