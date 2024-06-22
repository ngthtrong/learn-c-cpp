#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100 

typedef int ElementType;
 
typedef struct Nodetag{
 	ElementType data;
	struct Nodetag *next;
 }Node;
  
typedef Node *List;

// Khoi tao danh sach rong
void makeNULL(List *L){
	L = NULL;
}

// Tao node moi 
Node* makeNode(ElementType x){
	Node *List = (Node*)malloc(sizeof(Node));
	List->data = x;
	List->next = NULL;
	return List; 
} 

// Do dai danh sach
int len(List L){
	int count = 0;
	List temp = L; 
	while(temp != NULL){
		count++;
		temp = temp->next; 
	}
	return count; 
}

// Check danh sach rong
int empty(List L){
	if(L != NULL) return 0;
	return 1;  
} 

// Check danh sach full
int fullList(List L){
	if(len(L)<MAX_SIZE) return 0;
	else return 1; 
}

// Duyet cac phan tu cua danh sach 
void print(List L){
	List temp = L;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next; 
	}	
} 

// in ra phan tu tai vi tri p
ElementType getAt(int p, List L){
	int count = 0; 
	while(count != p){
		count++;
		L = L->next; 
	}
	return L->data; 
}

// Cap nhat gia tri tai p bang x 
void setAt(int p, ElementType x, List *L){
	int count = 0;
	List temp = *L;  
	while(count != p && temp != NULL){
		count++;
		temp = temp->next; 
	}
	if(temp != NULL) temp->data = x;
	else printf("p nam ngoai pham vi danh sach\n");   
} 

// Them phan tu vao dau danh sach 
void pushFront(List *L, ElementType x){
	List newNode = makeNode(x);
	newNode->next = *L;
	*L = newNode;  
}  

// Them phan tu vao cuoi danh sach 
void append(ElementType x, List *L) {
    Node *newNode = makeNode(x);
    if (*L == NULL) {
        *L = newNode;
        return;
    } 
        List temp = *L;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
}


//Insert x at position p
void insertAt(int p, ElementType x, List *L){
	int count = 1;
	List temp = *L; 
	List before = NULL;
	List newNode = makeNode(x);
	if(p == 1) 
	//pushFront(L, x);
	{
		newNode->next = temp;
		*L = newNode;  
		return;
	}
	
	while(count != p && temp != NULL){
		count++;
		before = temp;
		temp = temp->next;
	}
	
	if(count != p) append(x, L);
	else{
		before->next = newNode;
		newNode->next = temp;
	}
}

//Remove and return the last element
Node *popLast(List *L){
	List temp = *L;
	List before = NULL; 
	while(temp->next != NULL){
		before = temp; 
		temp = temp->next; 
	}
	before->next = NULL;
	return temp; 
} 

//Remove and return the first element
Node *popFirst(List *L){
	List temp = *L;
	*L = temp->next;
	return *L; 
}

//Remove and return the element at position p
Node *popAt(int p, List *L){
	int count = 0;
	List temp = *L; 
	List before = NULL;
	
	if(p == 0) popFirst(&temp);
	
	while(count != p && temp != NULL){
		count++;
		before = temp;
		temp = temp->next;
	}
	if(count != p) popLast(&temp);
	else{
		before->next = temp->next;
		return temp; 
	} 
} 
 
//Return the position of the first appearance of x in the list
int locate(ElementType x, List L){
	int count;
	while(L->data != x){
		count++;
		L = L->next; 
	} 
	if(L != NULL) return count++;
	if(L = NULL) printf("eror"); 
} 

// Return the pointer referring to the previous position of p in L
Node *previous(int p, List L){
	if(p>1){
		int j = 0;
		List temp = L;
		while(j<p-1-1 && temp != NULL){
			temp = temp->next;
			j++;
		}
		return temp;
	}
	else{
		Node *newnode = makeNode(0);
		printf("not found");
		return newnode;
	}
}


 
