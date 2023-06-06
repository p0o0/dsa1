#include <iostream>
using namespace std;
class node
{
	int data;
	node *left;
	node *right;
	int ht;
	public:
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
		ht=0;
	}
	friend class AVL;
};
class AVL
{
	node *root;
	public:
	AVL()
	{
		root=NULL;
	}
	node* getRoot()
	{
		return root;
	}
	node* insert(node*,int);
	int BF(node*);
	int height(node*);
	node *RR(node*);
	node *LL(node*);
	node *LR(node*);
	node *RL(node*);
	node *rotateleft(node*);
	node *rotateright(node*);
	void inorder(node*);
};
void AVL::inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		cout<<"\n"<<T->data;
		inorder(T->right);
	}
}
node *AVL::insert(node* root,int x)
{
	if(root==NULL)
		root=new node(x);
	else if(x > root->data)         // insert in right subtree
	{
		root->right=insert(root->right,x);
		if(BF(root)==-2)
			if(x > root->right->data)
				root=RR(root);
			else
				root=RL(root);
	}
	else if(x < root->data)
	{
		root->left=insert(root->left,x);
		if(BF(root)==2)
			if(x < root->left->data)
				root=LL(root);
			else
				root=LR(root);
	}
	root->ht=height(root);
	return(root);
}

int AVL::BF(node *T)
{
	int lh,rh;
	if(T==NULL)
	return(0);
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	return(lh-rh);
}

int AVL::height(node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	if(lh>rh)
		return(lh);
     else
	return(rh);
}
node * AVL::RR(node *T)
{
	cout<<"\nSingle Rotation";
	T=rotateleft(T);
	return(T);
}

node * AVL::RL(node *T)
{
	cout<<"\nDouble Rotation";
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}

node * AVL::LL(node *T)
{
	cout<<"\nSingle Rotation";
	T=rotateright(T);
	return(T);
}

node * AVL::LR(node *T)
{
	cout<<"\nDouble Rotation";
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}

node * AVL::rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

node * AVL::rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

int main()
{
	AVL tree;
	node *t=tree.getRoot();
	int n,x;
	cout<<"\nEnter no of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		 cout<<"\nEnter element:";
		 cin>>x;
		 t=tree.insert(t,x);
	}
	tree.inorder(t);
	return 0;
}
