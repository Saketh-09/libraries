/*implementing a binary search tree
with three traversal types
Preorder
Postorder
Inorder
adapted from https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/*/
#include<bits/stdc++.h>
using namespace std;

class bst
{
    int node;
    bst *left, *right;
    public:
    bst(int value){
      node=value;
      left=NULL;
      right=NULL;
    } //constructor


        bst* insert(bst* root,int value) {
          if (root==NULL) {
            return new bst(value);
          }
          if(value > root->node) {
            root->right=insert(root->right,value);
          }
          else {
            root->left=insert(root->left,value);
          }
          return root;
        }
        bst()
        : node(0)
        , left(NULL)
        , right(NULL)
{
}
      void preorder(bst* root) {
           if(root)
           {
              cout<<root->node<<endl;    //prints root->node
               preorder(root->left);    //moves to left subtree
               preorder(root->right);     //moves to right subtree
           }
       }
       void postorder(bst* root)
       {
           if(root)
           {
               postorder(root->left);    //moves to left sub tree
               postorder(root->right);     //moves to right sub tree
               cout<<root->node<<endl;    //Prints root->node
           }
       }
       void inorder(bst* root)
        {
            if(root)
            {
                inorder(root->left);    //moves to left subtree
                cout<<root->node<<endl ;    //prints root->node
                inorder(root->right);     //moves to right subtree
            }
        }

};

int main()
{
    bst b, *root = NULL;
    root = b.insert(root, 5);
    b.insert(root, 3);
    b.insert(root, 2);
    b.insert(root, 4);
    b.insert(root, 7);
    b.insert(root, 6);
    b.insert(root, 8);
    cout<<"preorder traversal"<<endl
    b.preorder(root);
    cout<<"postorder traversal"<<endl
    b.postorder(root);
    cout<<"inorder traversal"<<endl
    b.inorder(root);

    return 0;
}
