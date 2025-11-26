// #include <iostream>
// #include<vector>
// using namespace std;

// struct BST
// {
//     int data;
//     BST *left, *right , *p, ;
// } ;

// BST *root , *temp , *ttemp, *p;

// void init (){
// root = temp = ttemp = NULL;
// }

// void create_root(int x)
// {
//     root = new BST;
//     root -> data = x;
//     root-> left =root -> right = NULL; 
// } 

// void add_Nodes (int x){
//     temp = root;
//     while (temp!= NULL){
//        ttemp = temp;

//        if (temp->data>x)
//         temp = temp->left ;
       
//        else 
//         temp = temp-> right; 
//     }

//      p=new BST;

//      p->data=x;

//      p->left = p->right = NULL;

//      if (temp-> data>x){

//         temp -> left = p ;
//      }
//      else{
//         ttemp ->right=p;
//      }

//       // traversal code 

//               void Inorder(BST *p)
//          { 
//            if (p != NULL) {
//         Inorder(p->left);
//         cout << p->data << " ";
//         Inorder(p->right);
//     }
// }

//                   //2. PREORDER
                  
//                   void Preorder(BST *p){
//                     if (p!= NULL){
//                          cout<<p-> data;
//                           Inorder(p->left);
//                            Inorder(p->right);
//                   }
//         }

//         // //3. POSTORDER 
        
//         void Postordre (BST *p){
//             if (p!= NULL){
//                           Inorder(p->left);
//                            Inorder(p->right);
//                             cout<<p-> data;
//                   }
//         }

// }

// int main()
// {
//     create_root(50);
//     add_Nodes(30);
//      add_Nodes(70);
//       add_Nodes(90);
//        add_Nodes(20); 
//         add_Nodes(10);
//          add_Nodes(100);
//           add_Nodes(60);
//            add_Nodes(80);
//             add_Nodes(55);
//              add_Nodes(85);
//               add_Nodes(35);
//                add_Nodes(24);
//                add_Nodes(25);
//                  add_Nodes(15);
//                    add_Nodes(45);
//                      add_Nodes(50);
                       
//                       cout << "Inorder Traversal: ";
//     Inorder(root);
//     cout << endl;

//     cout << "Preorder Traversal: ";
//     Preorder(root);
//     cout << endl;

//     cout << "Postorder Traversal: ";
//     Postorder(root);
//     cout << endl;

//     return 0;

// }


#include <iostream>
using namespace std;

struct BST {
    int data;
    BST *left, *right;
};

BST *root = NULL, *temp, *ttemp;

void create_root(int x) {
    root = new BST;
    root->data = x;
    root->left = root->right = NULL;
}

void add_Nodes(int x) {
    temp = root;
    while (temp != NULL) {
        ttemp = temp;
        if (x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    BST *p = new BST;
    p->data = x;
    p->left = p->right = NULL;

    if (x < ttemp->data)
        ttemp->left = p;
    else
        ttemp->right = p;
}

// ------------ Traversals -----------------

void Inorder(BST *p) {
    if (p != NULL) {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}

void Preorder(BST *p) {
    if (p != NULL) {
        cout << p->data << " ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

void Postorder(BST *p) {
    if (p != NULL) {
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }
}

// ---------------- Main --------------------

int main() {

    create_root(50);

    add_Nodes(30);
    add_Nodes(70);
    add_Nodes(90);
    add_Nodes(20);
    add_Nodes(10);
    add_Nodes(100);
    add_Nodes(60);
    add_Nodes(80);
    add_Nodes(55);
    add_Nodes(85);
    add_Nodes(35);
    add_Nodes(24);
    add_Nodes(25);
    add_Nodes(15);
    add_Nodes(45);
    add_Nodes(50);

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);
    cout << endl;

    return 0;
}



