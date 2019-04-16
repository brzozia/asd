#include <iostream>
using namespace std;

struct node{
    int val;
    node*left;
    node* right;
    node *p;

};

void coutf(node*head)
{
    if(head!=NULL)
    {
        coutf( head->left);
        cout<<head->val<<endl;
        coutf( head->right);
    }
}

void insertf(node *&root,int el, node *prev)//(t,val,NULL)
{
    if(root==NULL){
        root=new node;
        root->val=el;
        root->left=NULL;
        root->right=NULL;
        root->p=prev;
        return;
    }

    if(el>root->val)
        insertf(root->right,el,root);
    else
        insertf(root->left,el,root);

}


void findmin(node*root,int &tmp,int &mini){
    if(root->left==root->right){
        if(tmp<mini)
            mini=tmp;
        return;
    }
    else{
        tmp++;
        if(root->left!=NULL)
            findmin(root->left,tmp,mini);
        if(root->right!=NULL)
            findmin(root->right,tmp,mini);

        tmp--;
    }
}
void findmax(node*root,int &tmp,int &maxi){
    if(root->left==root->right){
        if(tmp>maxi)
            maxi=tmp;
        return;
    }
    else{
        tmp++;
        if(root->left!=NULL)
            findmax(root->left,tmp,maxi);
        if(root->right!=NULL)
            findmax(root->right,tmp,maxi);

        tmp--;
    }
}

void can_col(node*root,bool &fl){

    if(root==NULL)return;
    if(fl==false) return;
    int maxh=0;
    int minh=100;
    int tmp=1;
    findmax(root,tmp,maxh);

    if(root->left==NULL and root->right!=NULL)
        minh=1;
    if(root->right==NULL and root->left!=NULL)
        minh=1;

    if(minh!=1)
        findmin(root,tmp,minh);
    cout<<maxh<<" "<<minh<<endl;

    if(minh*2<maxh){
       fl=false;
       return;
    }
    else{
        if(root->left!=NULL)
             can_col(root->left,fl);

        if(root->right!=NULL)
             can_col(root->right,fl);
    }

}

int main()
{
    node *t;
    t=NULL;

 /*   insertf(t,20,NULL);
    insertf(t,15,NULL);
    insertf(t,10,NULL);
    insertf(t,18,NULL);
    insertf(t,13,NULL);
    insertf(t,12,NULL);
    insertf(t,24,NULL);
    insertf(t,14,NULL);
    insertf(t,25,NULL);
    //insertf(t,26,NULL);
    insertf(t,19,NULL);
   // insertf(t,29,NULL);
    insertf(t,7,NULL);
    insertf(t,30,NULL);
*/
    insertf(t,20,NULL);
    insertf(t,13,NULL);
    insertf(t,23,NULL);
    insertf(t,5,NULL);
    insertf(t,17,NULL);
    insertf(t,15,NULL);
    insertf(t,14,NULL);
    insertf(t,16,NULL);
    insertf(t,19,NULL);
    insertf(t,25,NULL);
    insertf(t,32,NULL);
    insertf(t,29,NULL);
    insertf(t,28,NULL);
    insertf(t,30,NULL);
    insertf(t,40,NULL);
    insertf(t,2254,NULL);


    coutf(t);
    bool bol=true;
    can_col(t,bol);
    if(bol==true)
        cout<<"tak";
    else
        cout<<"nie";
}
