#include<iostream>  
#include <bits/stdc++.h>
  
using namespace std;

struct Node { 
   int val; 
   struct Node *left;
   struct Node *right;
   struct Node* parent;
}; 
struct Node* root = NULL; 

struct Node* tree(Node* dot, int key , Node* parent) 
{ 
    
    if (dot == NULL){
    	struct Node *temp =  (struct Node*)malloc(sizeof(struct Node));
    	temp->parent = parent;
    	temp->val = key; 
    	temp->left = temp->right = NULL; 
   		return temp; 
    } 
    if (key < dot->val) 
        dot->left  = tree(dot->left, key,dot); 
    else dot->right = tree(dot->right, key,dot);    
    return dot; 
} 

struct Node* search(Node* root,int in){
	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	if (root == NULL || root->val == in) {
       return root; 
	}
 
    if (root->val < in){ 
       return search(root->right, in); 
    }
    return search(root->left, in); 
} 




void predecessor(Node* in){
	Node* temp;
	Node* par;
	if (in->left != NULL)
	{ 	temp = in->left;
		while(temp->right != NULL){
		temp = temp->right;
	}
	printf("%d ", temp->val);
	}
	else{
		par = in->parent;
		while(par != NULL && in == par->left){
			in = par;
			par = par->parent;
		}
		printf("%d",par );
	}
	
}

void successor(Node* in){
	Node* temp;
	Node* par;
	if (in->right != NULL)
	{ 	temp = in->right;
		while(temp->left != NULL){
		temp = temp->left;
	}
	printf("%d ", temp->val);
	}
	else{
		par = in->parent;
		while(par != NULL && in == par->right){
			in = par;
			par = par->parent;
		}
		printf("%d",par );
	}
}

void min_max(Node* in){ //done
	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp = in;
	if (temp->left == NULL)
	{
		printf("no left");
	}

	if (temp->right == NULL)
	{
		printf("no right");
	}
	while(temp->left != NULL){
		temp = temp->left;
	}
	printf("%d ", temp->val);
	temp = in;
	while(temp->right != NULL){
		temp = temp->right;
	}
	printf("%d", temp->val);
}

struct Node* anc(Node* root,int a ,int b){ 
	Node* temp1 = (struct Node*)malloc(sizeof(struct Node)); 

	temp1 = root;
	
	if(a < temp1->val && b < temp1->val){
		temp1 = temp1->left;
		return anc(temp1,a,b);
	}
	else if(a > temp1->val && b > temp1->val){
		temp1 = temp1->right;
		return anc(temp1,a,b);
	}
	else printf("%d",temp1->val );
	return temp1;
}


int main() 
{ 
	int in = 0;
	char p;
	scanf("%d",&in);
	root = tree(root,in,NULL);
	scanf("%c",&p);
  	while(p != '\n'){
  		scanf("%d",&in);
  		tree(root,in,NULL);
  		p = getchar();
  	}
  	scanf("%c",&p);
	  	if (p == 'M')
	  	{	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	  		int z =0;
	  		scanf("%d",&z);
	  		temp = search(root,z);
	  		min_max(temp);
	  	}
	  	if (p == 'C')
	  	{
	  		int z =0;
	  		int y = 0;
	  		scanf("%d",&z);
	  		scanf("%d",&y);
	  	    anc(root,z,y);
	  	}
	  	if (p == 'S')
	  	{
	  		Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	  		int z =0;
	  		scanf("%d",&z);
	  		temp = search(root,z);
	  		successor(temp);
	  	}
	  	if (p == 'P')
	  	{
	  		Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	  		int z =0;
	  		scanf("%d",&z);
	  		temp = search(root,z);
	  		predecessor(temp);
	  	}
    return 0; 
} 
