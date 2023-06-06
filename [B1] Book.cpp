/*                                              Assignment 1 group B
A book consists of chapters,chapters consists of section and sections consists of subsection.Construct a tree and print the nos.*/


#include <iostream>
using namespace std;
class Book;
class node
{
        char data;
        node *left;
        node *right;
        public:
        friend class Book;
        node(char x)
        {
                data=x;
                left=right=NULL;
        }
};
class Book
{
        node* root;
        public:
        Book()
        {
                root=NULL;
        }
        node* create();
        void inorder(node*);
        void preorder(node*);
        void postorder(node*);
};
node* Book::create()
{
        char val;
        cout<<"\nEnter data(enter # for no data): ";
        cin>>val;
        if(val=='#')
                return NULL;
        node *p=new node(val);
        if(root==NULL)
        {
                root=p;
        }
        cout<<"Enter Left child for "<<val;
        p->left=create();
        cout<<"Enter Right child for "<<val;
        p->right=create();
        return(p);
}
void Book::inorder(node*t)
{
        if(root==NULL)
        {
                cout<<"Tree is empty";
                return ;
        }
        if(t!= NULL)
        {
                inorder(t->left);
                cout<<t->data<<' ';
                inorder(t->right);
        }
}
void Book::preorder(node*t)
{
        if(root==NULL)
        {
                cout<<"Tree is empty";
                return ;
        }
        if(t!= NULL)
        {
                cout<<t->data<<' ';
                preorder(t->left);
                preorder(t->right);
        }
}
void Book::postorder(node*t)
{
        if(root==NULL)
        {
                cout<<"Tree is empty";
                return ;
        }
        if(t!= NULL)
        {
                postorder(t->left);
                postorder(t->right);
                cout<<t->data<<' ';
        }
}
int main()
{
        cout<<"Hello";
        node *p;
        Book b1;
        p=b1.create();
        cout<<"Inorder transversal is \n";
        b1.inorder(p);
        cout<<"\nPreorder transversal is \n";
        b1.preorder(p);
        cout<<"\nPostorder transversal is \n";
        b1.postorder(p);
        return (0);
}
