#include<iostream>  
#include <bits/stdc++.h>
  
using namespace std;	 

struct Node { 
   char data; 
   struct Node *next; 
}; 
struct Node* head = NULL; 
struct Node* tail = NULL;
int alp[26];

void create(char in){
	struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
	temp->next = NULL;
	temp->data = in;
	if(tail == NULL){
		head = temp;
	}
	else{
		tail->next = temp;
	}
	
	tail = temp;
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
      i = 0; 
      j = 0; 
      k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
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

void MergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}

void store(){
	printf("%c %c\n",head->data,tail->data);
}


void print(){
	struct Node* temp = head;
	while(temp->next != NULL){
		alp[temp->data-'A']++; 
	}
	int i;
	while(alp[i] != 0 ){
		printf("%c %d",i+'A',alp[i]);
		i++;
	}
}

void ascend(){
	MergeSort(alp,0,25);
	int i;
	while(alp[i] != 0){
		printf("%c",i+'A');
		i++;
	}
}

void remove(int n){   
	int counter = 0;
	struct Node* temp = head;

	while(temp != NULL){
		if (temp->next == NULL)
		{
			printf("%c",temp->data );
		}
		if (temp->data != temp->next->data)
		{
			printf("%c", temp->data);
		}
		if (temp->data == temp->next->data)
		{	if (counter < n-1)
			{
				printf("%c",temp->data);
			}
			counter++;
		}
		else counter = 0;
		
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		
	}
}

int main() 
{ 
   char in = 'a';
   char fun[25];
   int n = 0;
   for (int i = 0; i < 26; ++i)
{
	alp[i] = 0;
}
   while(in != '\n'){
    scanf("%c",&in);
    if (in != '\n')
    {
    	create(in);
    }
   }
   
   cin >> fun;
   if (strcmp(fun,"Store") == 0)
   {
       store();
   }
   if (strcmp(fun,"Print") == 0)
   {
       print();
   }
   if (strcmp(fun,"Ascend") == 0 || strcmp(fun,"Sort") == 0)
   {
       ascend();
   }
   if (strcmp(fun,"Remove") == 0)
   {    
       scanf("%d",&n);
       remove(n);
   }
    return 0; 
} 
