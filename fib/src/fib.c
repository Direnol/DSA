#include "fib.h"

struct heap* Make_Empty_Fib_Heap(){ //O(1)
	struct heap* H = (struct heap* )malloc(sizeof(struct heap));
	H->min = NULL;
	H->n = 0;
	return H;
}

struct node* Make_New_Fib_Node (int k){ //O(1)
	struct node* x = (struct node* )malloc(sizeof(struct node));
	x->key = k;
	x->degree = 0;
	x->p = NULL;
	x->child = NULL;
	x->mark = false;
	return x;
}

void Fib_Heap_Insert (struct heap* H, struct node* x){ //O(1)
	if(H->min){
	 	H->min->right->left = x;
	 	x->left = H->min;
	 	x->right = H->min->right;
		H->min->right = x;
		if (x->key < H->min->key){
			H->min = x;
		}
	 } else {
	 	x->left = x;
		x->right = x;
	 	H->min = x;
	 }
	 H->n++;
}

struct node* Fib_Heap_Minimum (struct heap* H){ //O(1)
	return H->min;;
}

struct heap* Fib_Heap_Union (struct heap* H1, struct heap* H2){ //O(1)
	struct heap* H = Make_Empty_Fib_Heap();
	if (H1->min&&H2->min){
		H->min = H1->min;
		H->min->left->right = H2->min->right; //4 ñòðîêè - îáúåäèíåíèå ñïèñêîâ
		H2->min->right->left = H->min->left;
		H->min->left = H2->min;
		H2->min->right = H->min;
		if ((H1->min == NULL) || ((H2->min) && (H2->min->key <= H1->min->key))) {
		   H->min = H2->min;
		   }
	} else if (H1->min) {
		H->min = H1->min;
	} else if (H2->min) {
		H->min = H2->min;
	}
	H->n = H1->n + H2->n;
	return H;
}

struct node* Fib_Heap_Extract_Min (struct heap* H){ //O(log n)
	struct node* z = H->min;
	if (z) {
		if (z == z->right) { // z - åäèíñòâåííûé â ñïèñêå êîðíåé
				H->min = z->child; //ïîìå÷àåì óêàçàòåëü íà íîëü èëè ðåáåíêà
				Consolidate(H);
		} else {
			if (z->child == NULL){
				z->left->right = z->right; //óäàëÿåì z èç ñïèñêà êîðíåé
				z->right->left = z->left;
				H->min = z->right;
				Consolidate(H);
			} else {
				z->left->right = z->child; //óäàëÿåì z èç ñïèñêà êîðíåé
				z->right->left = z->child->left;
				z->child->left->right = z->right;
				z->child->left = z->left;
				H->min = z->right;
				Consolidate(H);
			}
		}
		H->n--;
	}
	return z;
}

void Consolidate (struct heap* H){ //O(log n)
	int Dn = (int)floor(log10(H->n - 1)/log10(2));
	int i;
	struct node** A = (struct node**)malloc(Dn*sizeof(struct node*));
	for (i=0; i<=Dn; i++){
		A[i] = NULL;
	}
	struct node* w = H->min;
	struct node* tmp = NULL;
	struct node* x = NULL;
	struct node* y = NULL;
	struct node* buf = NULL;
	int d, num = 0, k = 0;
	if (H->min){
		num++;
		while (w != H->min->left){
			num++;
			buf = w->right;
			w = buf;
		}
	}
	w = H->min;
	for (; k < num; k++){
		x = w;
		d = x->degree;
		while (A[d]){
			y = A[d];
			if (x->key > y->key){
				buf = x;
				x = y;
				y = buf;
			}
			Fib_Heap_Link(H, y, x);
			A[d] = NULL;
			d++;
		}
		A[d] = x;
		tmp = x->right;
		w = tmp;
	}
	H->min = NULL;
	for (i=0; i<=Dn; i++){
		if (A[i]){
			if ((H->min == NULL) || (A[i]->key < H->min->key)) {
				H->min = A[i];
				//H->min->left->right = A[i]; //êàæåòñÿ, è áåç ýòîãî ðàáîòàåò
				//A[i]->left = H->min->left;
				//A[i]->right = H->min;
				//H->min->left = A[i];
			}
		}
	}
}

void Fib_Heap_Link(struct heap* H, struct node* y, struct node* x){ //O(1)
	y->left->right = y->right;
	y->right->left = y->left;
	y->p = x;
	y->right = y;
	y->left = y;
	if (x->child){
		y->right = x->child->right;
		y->left = x->child;
		x->child->right->left = y;
		x->child->right = y;
	}
	x->child = y;
	x->degree++;
	y->mark = false;
}

void Fib_Heap_Decrease_Key (struct heap* H, struct node* x, int k){
	if (k > x->key) {
		printf ("Error! New key is bigger than current\n");
	} else {
		x->key = k;
		struct node* y = x->p;
		if (y && (x->key < y->key)){
			Cut(H, x, y);
			Cascading_Cut(H,y);
		}
		if(x->key < H->min->key){
			H->min = x;
		}
	}
}

void Cut (struct heap* H, struct node* x, struct node* y){
	if (x == x->right){
		y->child = NULL; ////óäàëåíèå x èç ñïèñêà äî÷åðíèõ óçëîâ y
	} else {
		x->left->right = x->right; //óäàëåíèå x èç ñïèñêà äî÷åðíèõ óçëîâ y
		x->right->left = x->left;
	}
	y->degree--; //óìåíüøåíèå ñòåïåíè (êîëè÷åñòâà äî÷åðíèõ óçëîâ) y
	H->min->right->left = x; //äîáàâëåíèå x â ñïèñîê êîðíåé H
	x->right = H->min->right;
	x->left = H->min;
	H->min->right = x;
	x->p = NULL;
	x->mark = false;
}

void Cascading_Cut (struct heap* H, struct node* y){
	struct node* z = y->p;
	if (z){
		if (y->mark == false){
			y->mark = true;
		} else {
			Cut (H, y, z);
			Cascading_Cut(H,z);
		}
	}
}

void Fib_Heap_Delete (struct heap* H, struct node* x){
	Fib_Heap_Decrease_Key(H, x, -2147483647);
	struct node* y = Fib_Heap_Extract_Min(H);
}

void Print_Fib_Heap (struct heap* H, struct node* x){
	struct node* y = x;
	struct node* buf = NULL;
	while (buf != y){
		printf("node %d \n", x->key);
		if (x->child){
			printf("start %d child list\n", x->key);
			Print_Fib_Heap(H, x->child);
			printf("end %d child list\n", x->key);
		}
		buf = x->right; //äâèæåíèå ïî ñïèñêó êîðíåé âïðàâî
		x = buf;
	}
}
