#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

struct node {
	int key;
	int degree;
	struct node* p;
	struct node* left;
	struct node* right;
	struct node* child;
	bool mark;
};

struct heap {
	struct node* min;
	int n;
};

struct heap* Make_Empty_Fib_Heap();
struct node* Make_New_Fib_Node(int k);
void Fib_Heap_Insert (struct heap* H, struct node* x);
struct node* Fib_Heap_Minimum (struct heap* H);
struct heap* Fib_Heap_Union(struct heap* H1, struct heap* H2);
struct node* Fib_Heap_Extract_Min (struct heap* H);
void Consolidate (struct heap* H);
void Fib_Heap_Link (struct heap* H, struct node* y, struct node* x);
void Fib_Heap_Decrease_Key (struct heap* H, struct node* x, int k);
void Cut (struct heap* H, struct node* x, struct node* y);
void Cascading_Cut (struct heap* H, struct node* y);
void Fib_Heap_Delete (struct heap* H, struct node* x);
void Print_Fib_Heap (struct heap* H, struct node* x);
