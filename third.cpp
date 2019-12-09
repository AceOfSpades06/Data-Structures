#include<iostream>  
#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	int v2;
	int w;
	struct Node* next;
};

struct Node* head[1000];


void Create(int a,int b, int c){

	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 

	temp->v2 = b;
	temp->w = c;
	temp->next = head[a];
	head[a] = temp;
}

void neighbors(int in){ //done
	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp = head[in];
	while(temp != NULL){
	printf("%d ", temp->v2);
	temp = temp->next;
	}
}

void vertices(){ //done
	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	for (int i = 0; i < 1000; ++i)
	{	temp = head[i];
		if (head[i] != NULL)
		{	
			printf("%d ",i );
			while(temp != NULL){
				if (head[temp->v2]==NULL)
				{
					printf("%d ",temp->v2 );
				}

				temp = temp->next;
			}
		}
	}
}

int edgeWeight(int a, int b){ //done
	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp = head[a];
	while(temp->v2 != b){
		temp = temp->next;
	}
	printf("%d",temp->w );
	return temp->w;
}

void containsVertex(int v1){ //done
	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	int t = 0;
	if (head[v1] != NULL)
	{
		printf("yes it does\n");
	}
	else{
		for (int i = 0; i < 1000; ++i)
		{	temp = head[i];
			if (head[i] != NULL)
			{	
				while(temp != NULL){
					if (temp->v2 == v1)
					{
						printf("yes it does\n");
						t = 5;
						break;
					}

					temp = temp->next;
				}
				if (t == 5)
				{
					break;
				}
			}
		}
		if (t != 5)
		{
			printf("nope!!\n");
		}
	}

}

void containsEdge(int a, int b){ // done
	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp = head[a];
	int t = 0;
	while(temp != NULL){
		if (temp->v2 == b)
		{
			printf("yes it does\n");
			t = 3;
		}
		temp = temp->next;
	}
	if (t != 3)
	{
		printf("nope!!!\n");
	}
}



int main(){
	char fun[100];
	int in;
	int ino;
	 for (int i = 0; i < 1000; i++)
        head[i] = NULL;
	char e = 'a';
	int v1;
	int v2;
	int w;
	char line;
	int ecount = 0;
	while(e != '\n'){
		scanf("%c",&e);
		if (e == 'E')
		{
			cin >> v1;
			cin >> v2;
			cin >> w;
			Create(v1,v2,w);
			ecount++;
			scanf("%c",&line);
		}
	}
cin >> fun;
if (strcmp(fun,"neighbors") == 0)
   {
       scanf("%d",&in);
       neighbors(in);
   }
if (strcmp(fun,"vertices") == 0)
   {
       vertices();
   }
if (strcmp(fun,"edgeWeight") == 0)
   {
       scanf("%d",&in);
       scanf("%d",&ino);
       edgeWeight(in,ino);
   }
if (strcmp(fun,"containsVertex") == 0)
   {
       scanf("%d",&in);
       containsVertex(in);
   }
if (strcmp(fun,"containsEdge") == 0)
   {
      scanf("%d",&in);
       scanf("%d",&ino);
       containsEdge(in ,ino);
   }
}