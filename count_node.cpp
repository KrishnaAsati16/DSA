#include<iostream>
using namespace std;

struct BST{
    int data;
    BST *left, *right,*p;

};
BST*root,*temp, *ttemp;
void init ()
{
    root=temp=ttemp=NULL;
}
void create_root(int x){
    root=new BST;
    root->data=x;
    root->left=root->right=NULL;
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

int countN=0;
void count_Nodes (BST *p){
    if(p!=NULL){
        countN++;
        count_Nodes(p->left);
        count_Nodes(p->right);
    }
}

int main ()
{
    init();
    create_root(50);
   add_Nodes(10);
  add_Nodes(2);
  add_Nodes(85);
  add_Nodes(90);
  add_Nodes(15);

countN = 0;
    count_Nodes(root);

    cout << "Total number of nodes in BST = " << countN << endl;

}

