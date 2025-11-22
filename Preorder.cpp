#include<iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//static int indexPtr = -1;   // FIX: "==" replaced with "=" and valid variable name

static int idx = -1;
Node* buildTree (vector<int>preorder){
    idx++;
    if (preorder[idx]==-1){
        return NULL ;
    }
Node* root = new Node(preorder[idx]);
root->left = buildTree(preorder); // left
root->right = buildTree(preorder); // right

return root;
}
int main (){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root  = buildTree(preorder);
    cout << root->data << endl;
     cout << root-> left->data << endl;
      cout << root->right->data << endl;
    return 0; 

}