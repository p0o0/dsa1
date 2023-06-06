/*
Beginning with an empty binary search tree,construct binary search tree while inserting the values in the order given.After constructing a binary tree
1. Insert new node.
2.Find number of nodes in longest paath from root.
3.minimum data value found in the tree.
4.Change a tree so that the roles of left and right pointers are swapped at every node.
5.Search a value.
*/

#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node*left;
		node*right;

};
class bst
{
	node *root;
	public:
		bst()
		{
			root=NULL;
		}
		node* create();
		void insert(node*,node*);
		void inorder(node*);
		void smallest_value();
		void largest_value();
		void search(node*,int);
		void swap(node*);
		int longest_path(node*);

};
node* bst::create()
{
	int n,value;
	cout<<"Enter no. of nodes for bst";
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cout<<"Enter value for node";
		cin>>value;
		node *p = new node;
		p->data = value;
		p->left = NULL;
		p->right = NULL;
		insert(root, p);
	}
	return root;
}
void bst::insert(node*x,node*p)
{
	if(root==NULL)
	{
		root=p;
		cout<<"root is added";
	}
	else
	{
		if(x->data < p->data)
		{
			if(x->right==NULL)
			{
				x->right=p;
			}
			else
			{
				insert(x->right,p);
			}
		}
		else
			if(x->left==NULL)
			{
				x->left=p;
			}
			else
			{
				insert(x->left,p);
			}
	}
};
void bst::inorder(node *p)
{
	if(p!=NULL)
	{
	inorder(p->left);
	cout<<p->data<<" ";
	inorder(p->right);
	}
};

void bst::smallest_value()
{
	if(root==NULL)
	{
		cout<<"Tree is empty..";
	}
	else
	{
		node*temp=root;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		cout<<"Smallest value is "<<temp->data;
	}
};
void bst::largest_value()
{
	if(root==NULL)
	{
		cout<<"Tree is empty..";
	}
	else
	{
		node*temp=root;
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		cout<<"Largest value is "<<temp->data;
	}
};
void bst::search(node *x,int key)
{
	if(x==NULL)
	{
		cout<<"KEY NOT FOUND...";
	}
	else
	{
		if(key<x->data)
		{
			search(x->left,key);
		}
		else
		{
			if(key>x->data)
			{
				search(x->right,key);
			}
			else
			{
				 cout<<"KEY FOUND....";
			}
		}
	}
}
void bst::swap(node *x)
{
	if(x!=NULL)
	{
		node*p=x->left;
		x->left=x->right;
		x->right=p;
		swap(x->left);
		swap(x->right);
	}
}
int bst::longest_path(node *x)
{
	int height_left,height_right;
	if(x==NULL)
	{
		return(0);
	}
	if(x->left==NULL && x->right==NULL)
	{
		return(1);
	}
	height_left=longest_path(x->left);
	height_right=longest_path(x->right);
	if(height_left>height_right)
	{
		return (height_left+1);
	}
	else
	{
		return(height_right+1);
	}
}
int main()
{
	bst b1;
	int choice;
	int height;
	node *x;
	cout<<"Hello World";
	do
	{
		cout<<"\n1.Create BST.";
		cout<<"\n2.Traverse BST using INORDER.";
		cout<<"\n3.Largest data value found in the tree.";
		cout<<"\n4.Minimum data value found in the tree.";
		cout<<"\n5.Find number of nodes in longest path from root.";
		cout<<"\n6.Swapping left and right value.";
		cout<<"\n7.Search a value.";
		cout<<"\n8.Exit the program.";
		cout<<"\nEnter the choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			       x=b1.create();
				break;
			case 2:
				b1.inorder(x);
				break;
			case 3:
				b1.largest_value();
				break;
			case 4:
				b1.smallest_value();
				break;
			case 5:
				height=b1.longest_path(x);
				cout<<"Longest path is "<<height;
				break;

			case 6:
				b1.swap(x);
				b1.inorder(x);
				break;

			case 7:
				int key;
				cout<<"ENTER VALUE TO BE SEARCHED ";
				cin>>key;
				b1.search(x,key);
				break;
			case 8:
				cout<<"\nEnd of program";
				break;
		}
	}
	while(choice != 8);
	return 0;
}

