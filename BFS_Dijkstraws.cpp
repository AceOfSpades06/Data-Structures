#include<iostream>  
#include <bits/stdc++.h>
  
using namespace std;


struct Node{
	int v2;
	int w;
	struct Node* next;
};

struct Node* head[1000];
struct Node* headDir[1000];
char col[1000];
int arr[1000];
int dis[1000];

void enq(int in){
	for (int i = 0; i < 1000; ++i)
	{
		if (arr[i] == -1)
		{
			arr[i] = in;
			break;
		}
	}
}

int deq(){
	int out = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (arr[i] != -2)
		{
			out = arr[i];
			arr[i] = -2;
			break;
		}
	}
	return out;
}

void CreateUnd(int a,int b, int c){ //directed graph

	Node* temp1 = (struct Node*)malloc(sizeof(struct Node)); 
	Node* temp2 = (struct Node*)malloc(sizeof(struct Node)); 
	temp1->v2 = b;
	temp1->w = c;
	temp2->w = c;
	temp2->v2 = a;
	temp1->next = head[a];
	temp2->next = head[b];
	head[a] = temp1;
	head[b] = temp2;
}

void CreateDir(int a,int b, int c){

	Node* temp = (struct Node*)malloc(sizeof(struct Node)); 

	temp->v2 = b;
	temp->w = c;
	temp->next = headDir[a];
	headDir[a] = temp;
}


void Find(){ //BFS
	Node* s ; 
	Node* temp ; 
	int test = 1;
	int components = 0;
	int u = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (head[i] != NULL && col[i]=='w')
		{	s = head[i];
			col[i] = 'g';
			enq(i);
			while(test == 1){
				u = deq();
				temp = head[u];
				while(temp != NULL){ 
					if (col[temp->v2] == 'w')
					{
						col[temp->v2] = 'g';
						enq(temp->v2);
					}
					temp = temp->next;
				}
				col[u] = 'b';
				printf("%d ",u );

				for (int i = 0; i < 1000; ++i)
				{
					if (arr[i]>0)
					{
						test = 1;
						break;
					}
					else test = 0;
				}
			}
			test = 1;
			for (int i = 0; i < 1000; i++)
			{    
       		 arr[i] = -1;
    		}
    		printf("\n");
    		components++;
		}

	}
	printf("We have %d components only!!\n", components);
}


int extractmin(int inp[]){
	int temp = 1000000;
	int r = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (temp > inp[i] && inp[i] != -1)
		{
			temp = inp[i];
			r = i;
		}
	}
	return r;
}

void SP(int in){
	dis[in] = 0;
	int u =0;
	int test = 1;
	while(test ==1){
		u = extractmin(dis);
		printf("%d %d\n",u, dis[u] );
		Node* temp = headDir[u];
		while(temp != NULL)
		{
			if (dis[u] + temp->w < dis[temp->v2])
			{
				dis[temp->v2] = dis[u] + temp->w;
			}
			temp = temp->next;
		}
		dis[u] = -1;
		for (int i = 0; i < 1000; ++i)
		{
			if (dis[i] !=-1 && dis[i] != 1000000)
			{
				test = 1;
				break;
			}
			else{
				test = 0;
			}
		}
	}
}


int main(){
	char fun[100];
	int in;
	for (int i = 0; i < 1000; i++){
        col[i] = 'w';
        head[i] = NULL;
        arr[i] = -1;
        dis[i] = 1000000;
    }
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
			CreateUnd(v1,v2,w);
			CreateDir(v1,v2,w);
			ecount++;
			scanf("%c",&line); // for scaning newline
		}
	}
cin >> fun;
if (strcmp(fun,"Find") == 0)
   {
       Find();
   }
if (strcmp(fun,"SP") == 0)
   {	
   		scanf("%d",&in);
    	SP(in);
   }
}






