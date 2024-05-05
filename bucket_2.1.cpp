#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    char value;
    Tree* left;
    Tree* right;

    Tree(){
        left=right=nullptr;

    }


};
char* insert(Tree**node,char*ch){
    if(*ch=='\0'){
        return ch;
    }
    while (1){
        char* q = nullptr;
        if(*node == nullptr){
            Tree* nn = new Tree ;
            nn-> value = *ch;
            nn->left = nullptr;
            nn->right = nullptr;
            *node = nn;

        }
        else{
            if(*ch>='a' && *ch <='z'){
                return ch;
            }

            q=insert(&(*node)->left,ch+1);
            q=insert(&(*node)->right,q+1);
            return q;
            
        }
    }

}

void inorder ( Tree *c){
    if(c==nullptr){
        return;

    }
    else {
        inorder(c->left);
        cout<<c->value<<" ";
        inorder(c->right);

    }
}

int main(){
    Tree* node = nullptr;
    char ch[] = "+*a+bcd";
    insert(&node,ch);
    inorder(node);


}