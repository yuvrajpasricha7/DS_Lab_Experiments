#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

node *createnode(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

node* ins(node *root,int value)
{
    if(root==NULL)
    {
        root=createnode(value);
    }
    else if(value < root->data)
        root->left=ins(root->left,value);
    else if(value > root->data)
        root->right=ins(root->right,value);

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int findmin(node *root){
	if(root->left==NULL)
	   return root->data;
	else{
		int min=findmin(root->left);
		return min;
	}
}

node* del(node *root,int data1){
	if(root==NULL){
	return NULL;}
	if(root->data==data1){
		if(root->left==NULL)
		    return root->right;
		else if(root->right==NULL)
		    return root->left;
		else{
			int min=findmin(root->right);
		    root->data=min;
		    root->right=del(root->right,min);
		}
	}
	else{
		if(root->data>data1){
		    root->left=del(root->left,data1);
		}
		else{
			root->right=del(root->right,data1);
		}    	
	}
	return root;
}

int main()
{
    node *root = NULL;
    node *ptr;
    int x,n,ch;
    cout<<"Enter choice\n1.Insert\n2.Traverse\n3.Delete\n";
    cin>>ch;
    while(ch)
    {
        switch(ch)
        {
        case 1:
            cout<<"Enter the no of nodes: ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>x;
                root=ins(root,x);
            }
            break;

        case 2:
            ptr=root;
            cout<<"Inorder:  ";
            inorder(ptr);
            cout<<"\nPreorder:  ";
            preorder(ptr);
            cout<<"\nPostorder:  ";
            postorder(ptr);
            break;
            
        case 3:
            cout<<"\nEnter an element you want to delete: ";
            cin>>x;
            ptr=root;
            root=del(ptr,x);
            break;
            
        default:
        	exit(0);
        }
        cout<<"\nEnter choice: ";
        cin>>ch;
    }
    return 0;
}
