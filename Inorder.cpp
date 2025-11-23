// #include<iostream>
// #include <vector>

// using namespace std;
                                      //// kyu ni chal rahacode
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

//  int idx = -1;
// Node* buildTree (vector<int>preorder){
//     idx++;
//     if (preorder[idx]==-1){
//         return NULL ;
//     }
// Node* root = new Node(preorder[idx]);
// root->left = buildTree(preorder); // left
// root->right = buildTree(preorder); // right

// return root;
// }

// void inorder(Node*  root){
//  if(root== NULL);{
//     return;
//  }   
//  inorder(root -> left);
//  cout << root -> data<< "";
//  inorder (root ->right); 
// }

// int main (){
//     vector <int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

//     Node* root = buildTree (preorder);
//     inorder(root);
//     cout <<endl;
//     return 0;
// }


                                          /// CGPT upper wale or yeh same hai fir  bhi


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

int index = -1;
Node* buildTree(const vector<int>& preorder) 
{
    index++;

    if (preorder[index] == -1) return NULL;

    Node* root = new Node(preorder[index]); 
    root->left = buildTree(preorder);// left
    root->right = buildTree(preorder);// right
    return root;
}

void inorder(Node* root){
            if(root == NULL)
    {
                     return;
    }

             inorder(root->left);
              cout << root->data << " ";
             inorder(root->right);
}

int main ()
{

    vector <int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);
    inorder(root);
    cout << endl;
    return 0;
}
