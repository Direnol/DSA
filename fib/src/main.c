#include "fib.h"

int main()
{
	int k;
	struct node* x = NULL;
	struct heap* H = Make_Empty_Fib_Heap();

    printf("USE:P(print)\tM(minimum)\tE(extract)\tI(insert)\tC(clear)\\tQ(quit)\n");
	while(1) {
        int key = 1;
		switch (getchar()) {
			case 'I':{ //INSERT
                printf("INSERT:\n");
				scanf("%d", &k);
				x = Make_New_Fib_Node(k);
				Fib_Heap_Insert(H,x);
				printf("INSERT:\n%d is successfully inserted\n\n", x->key);
				break;
			}
			case 'M' :{ //MINIMUM
				printf("MINIMUM:\n");
				x = Fib_Heap_Minimum(H);
				if (x) printf("%d is minimum\n\n", x->key);
				else printf("Can't MIN -> heap is empty\n\n");
				break;
			}
			case 'E' :{//EXTRACT
				printf("EXTRACT_MIN:\n");
				x = Fib_Heap_Extract_Min(H);
				if (x) {
					printf("%d is successfully extractred\n", x->key);
					struct node* y = NULL;
					y = Fib_Heap_Minimum(H);
					if (y) printf("%d is new minimum\n\n", y->key);
					else printf("new heap is empty\n\n");
				}
				else printf("Can't EXTRACT -> heap is empty\n\n");
				break;
			}
			case 'P' :{//PRINT
				printf("PRINT:\n");
				if (H->min == NULL) printf("EMPTY HEAP\n\n");
				Print_Fib_Heap (H, H->min);
				break;
			}
            case 'C' : {
                system("clear");
                break;
            }
            case 'Q' : {
                key = 0;
                break;
            }
		}
        if (!key) break;
	}

	free(H);
	return 0;
}
