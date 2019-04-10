#include <iostream>
using namespace std;

struct node{
    int val;
    node*left;
    node* right;
    node *p;
    int child;
};
int odj(node*p)
{
    if(p==NULL)
            return 0;
    else
        return p->child;

}
void coutf(node*head)
{
    if(head!=NULL)
    {
        coutf( head->left);
        cout<<head->val<<" "<<head->child<<endl;
        coutf( head->right);
    }
}
node * findiel(node*root,int i)
{
    if(root->child<i)
        return NULL;

    while(root->child-odj(root->right) != i){
        if(root->child - odj(root->right)>i)
            root=root->left;
        else if(root->child - odj(root->right)<i){
            i=i-odj(root->left)-1;
            root=root->right;
        }
    }
    cout<<root->val;
    return root;
}

int finde(node *root,int v)
{
    int i=root->child-odj(root->right);
    while(root->val!=v and root!=NULL)
    {
        if(root->val<v){
            if(root->right==NULL)
                return 0;
            root=root->right;
            i=i+(root->child-odj(root->right));


        }
        else{
            if(root->left==NULL)
                return 0;
            root=root->left;
            i=i-odj(root->right)-1;

        }

    }

    return i;

}

void insertf(node *&root,int el, node *prev)//(t,val,NULL)
{
    if(root==NULL){
        root=new node;
        root->val=el;
        root->left=NULL;
        root->right=NULL;
        root->p=prev;
        root->child=1;
        return;
    }

    root->child++;

    if(el>root->val)
        insertf(root->right,el,root);
    else
        insertf(root->left,el,root);

}

int main()
{
    node *t;
    t=NULL;

    insertf(t,20,NULL);
    insertf(t,15,NULL);
    insertf(t,10,NULL);
    insertf(t,18,NULL);
    insertf(t,13,NULL);
    insertf(t,12,NULL);
    insertf(t,24,NULL);
    insertf(t,14,NULL);
    insertf(t,25,NULL);
    insertf(t,26,NULL);

    coutf(t);
    int a;
    cin>>a;
    findiel(t,a);
    cin>>a;
    cout<<finde(t,a);


}
