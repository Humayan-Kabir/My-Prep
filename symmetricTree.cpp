#include<bits/stdc++.h>
using namespace std;
struct node {
    int key;
    node *left, *right;
    node(int k) {
        key = k;
    }
};
void dfs(node *root) {
    if(root == NULL) return;
    cout << root->key << " ";
    dfs(root->left); dfs(root->right);
}
bool isSymmetric(node *root1, node *root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 && root2 && root1->key == root2->key) {
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
    return false;
}
int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    cout << isSymmetric(root->left, root->right) << endl;
    return 0;
}
