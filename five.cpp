#include<iostream>  
#include <bits/stdc++.h>
  
using namespace std;

struct meta;
struct chain;

struct Node{
	int v1;
	int v2;
	int w;
};
int components = 0;
struct meta
{
	struct chain* head;
	struct chain* tail;
};

struct chain
{
	int val;
	struct chain* next;
	struct meta* link;
};

struct chain* allchain[1000];
struct meta* allmeta[1000];
struct Node edge[1000];
///////////////////////
struct test{
	int v2;
	int w;
	struct test* next;
};
struct test* head[1000];
char col[1000];
int arr[1000];
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

	test* temp1 = (struct test*)malloc(sizeof(struct test)); 
	test* temp2 = (struct test*)malloc(sizeof(struct test)); 
	temp1->v2 = b;
	temp1->w = c;
	temp2->w = c;
	temp2->v2 = a;
	temp1->next = head[a];
	temp2->next = head[b];
	head[a] = temp1;
	head[b] = temp2;
}
void Find(){ //BFS
	test* s ; 
	test* temp ; 
	int test = 1;
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
		//		printf("%d ",u );

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
    	//	printf("\n");
    		components++;
		}

	}
	//printf("We have %d components only!!\n", components);
}

//////////////////////////
void makeset(int in){ //check for return statement 
	chain* nope = (struct chain*)(malloc(sizeof(struct chain)));
	meta* temp = (struct meta*)(malloc(sizeof(struct meta)));
	nope->val = in;
	nope->next = NULL;
	nope->link = temp;
	temp->head = nope;
	temp->tail = nope;
	allchain[in] = nope;
	allmeta[in] = temp;
}

struct chain* findset(int in){
	chain* nope = (struct chain*)(malloc(sizeof(struct chain)));;
	int p = 0;
	for (int i = 0; i < 1000; ++i)
	{	nope = allchain[i];
		if (allchain[i] != NULL)
		{
			while(nope != NULL){
				if (nope->val == in)
				{	p = 3;
					return allchain[i];
					break;
				}
				nope = nope->next;
			}
		}
		if (p == 3)
		{
			break;
		}
	}
	return NULL;
}

void unionset(int a,int b){
	chain* nope = (struct chain*)(malloc(sizeof(struct chain)));;
	allchain[a]->link->tail->next = allchain[b];
	nope = allchain[b];
	allchain[a]->link->tail = allchain[b]->link->tail;
	while(nope != NULL){
	nope->link = allchain[a]->link;
	nope = nope->next;
	}
}

void merge(Node arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    Node L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
      i = 0; 
      j = 0; 
      k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i].w <= R[j].w) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void MergeSort(Node arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}

void spanningtree(){
	MergeSort(edge,0,999);
	int i=0;
	while(edge[i].w != 1000000){
		if (findset(edge[i].v1) != findset(edge[i].v2))
		{
			unionset(edge[i].v1,edge[i].v2);
			printf("%d  %d\n",edge[i].v1,edge[i].v2);
		}
		i++;
	}

}

int main(){
	for (int i = 0; i < 1000; i++)
    {   
    	edge[i].v1 = 0;
    	edge[i].v2 = 0;
    	edge[i].w = 1000000;
    	col[i] = 'w';
        head[i] = NULL;
        arr[i] = -1;
	}
	char e = 'a';
	int vt1;
	int vt2;
	int wt;
	char line;
	int ecount = 0;
	while(e != '\n'){
		scanf("%c",&e);
		if (e == 'E')
		{
			cin >> vt1;
			cin >> vt2;
			makeset(vt1);
			makeset(vt2);
			cin >> wt;
			CreateUnd(vt1,vt2,wt);
			ecount++;
			edge[ecount].v1 = vt1;
			edge[ecount].v2 = vt2;
			edge[ecount].w = wt;
			scanf("%c",&line);
		}
	}
	Find();
	if (components > 1)
	{
		printf("wrong input as it has more than one connected component");
	}
	else{
	spanningtree();
	}
}
