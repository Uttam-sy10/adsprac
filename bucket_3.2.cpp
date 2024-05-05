#include<bits/stdc++.h>
using namespace std ;
class Node{
    public:
    Node *left,*right;
    int data;

    Node(int data ){
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};

int findMax(Node* root){
    if(root == NULL )
    return INT_MIN;
    int res =  root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if(lres>res)
    res=lres;
    if(rres>res)
    res=rres;
    return res;
}

int findMin(Node* root){
    if(root == NULL){
        return INT_MAX;

    }
    int res=root->data;
    int left = findMin(root->left);
    int right = findMin(root->right);
    if(left<res)
    {
        res = left;

    }
    if(right<res){
        res = right;

    }
    return res;
}

int main(){
    Node* NewRoot = NULL;
    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(11);
    root->right->right = new Node(9);
    root->right->right->left = new Node(4);
    cout<<"MAXIMUM ELEMENT IS "<<findMax(root)<<endl;
    cout<<"MINIMUM ELEMENT IS "<<findMin(root)<<endl;

    return 0;
}



