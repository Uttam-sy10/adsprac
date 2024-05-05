#include<bits/stdc++.h>
using namespace std;
// recursive traversal
class tree{
    public:
    int value ;
    tree* left;
    tree* right;

    tree(int value){
        this-> value = value;
        left = right = nullptr;

    }


};
void inorder( tree* root){
    if( root == nullptr){
        return;

    }
    else{
        inorder(root -> left);
        cout<<root->value<<" ";
        inorder(root-> right);
    }
}

void preorder ( tree* root){
    if (root == nullptr){
        return;
    }
    else{
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right );
        
    }

}

void postorder ( tree* root){
    if (root == nullptr){
        return;
    }
    else{
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<" ";
    }

}

int main(){
    tree* t1;
    t1 = new tree(6);
    t1->left = new tree(3);
    t1->right = new tree(8);
    t1->left->left = new tree(1);
    cout<<"\nInorder:" ; 
    inorder(t1);
    cout<<"\nPreorder:" ; 
    preorder(t1);
    cout<<"\nPostorder:" ; 
    postorder(t1);

}
