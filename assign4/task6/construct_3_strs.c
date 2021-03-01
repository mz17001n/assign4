#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {
  struct node *x;
  struct node *y;
  struct node *z;

  x = (struct node *) malloc( sizeof(struct node) ); 
  y = (struct node *) malloc( sizeof(struct node) ); 
  z = (struct node *) malloc( sizeof(struct node) ); 

  x->value=(char*) malloc(6*sizeof(char));
  x->value = "CS232";
  y->value=(char*) malloc(3*sizeof(char));
  y->value="is";
  z->value=(char*) malloc(8*sizeof(char));
  z->value="awesome";

  x->next = y;
  y->next = z;
  z->next = x;    
    
    return x;//just to pass compiler, please edit as needed.
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
    	printf("failed");
      free(x);
      free(y);
      free(z);
	    return -1;
    } else {
      free(x);
      free(y);
      free(z);
      return 0;
    }
}
