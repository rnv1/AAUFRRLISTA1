#include"red_black_tree.h"
#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>

#define N (100000)

/*  this file has functions to test a red-black tree of integers */

void IntDest(void* a) {
  free((int*)a);
}



int IntComp(const void* a,const void* b) {
  if( *(int*)a > *(int*)b) return(1);
  if( *(int*)a < *(int*)b) return(-1);
  return(0);
}

void IntPrint(const void* a) {
  printf("%i",*(int*)a);
}

void InfoPrint(void* a) {
  ;
}

void InfoDest(void *a){
  ;
}

int main() {
  stk_stack* enumResult;
  int option=0;
  int a, i;
  int newKey,newKey2;
  int* newInt;
  rb_red_blk_node* newNode;
  rb_red_blk_tree* tree;

  tree=RBTreeCreate(IntComp,IntDest,InfoDest,IntPrint,InfoPrint);
  
 
  
  for(a = 1; a < 30; a++){
    clock_t tic1 = clock();
    int arr[N];
    
    int j = 100000;
    for(i= 0; i<N; i++){
  arr[i] = j;
  j = j - 30;
  }
    
    for(i = 0; i < N; i++) {
         newInt=(int*) malloc(sizeof(int));
         
         /*arr[i] = rand() % 1000;*/
	  *newInt= arr[i];
	  RBTreeInsert(tree,newInt,0);
    }
    clock_t toc1 = clock();
    
   
    printf("\nElapsed to insert: %f seconds        ", (double)(toc1 - tic1) / (double)CLOCKS_PER_SEC);
     
      j = 100000;
          for(i= 0; i<N; i++){
              arr[i] = j;
      j = j-30;
      }
    
    clock_t tic2 = clock(); 

    for(i = 0; i < N; i++) {
        newKey = arr[i];
        if ( ( newNode=RBExactQuery(tree,&newKey ) ) ) RBDelete(tree,newNode);/*assignment*/
	  else printf("key not found in tree, no action taken\n");
    }

    clock_t toc2 = clock();
    
    printf("Elapsed top delete: %f seconds\n", (double)(toc2 - tic2) / (double)CLOCKS_PER_SEC);
    }
  
  
  
  
  
  
  
  
  
  
  
  while(option!=8) {
    printf("choose one of the following:\n");
    printf("(1) add to tree\n(2) delete from tree\n(3) query\n");
    printf("(4) find predecessor\n(5) find sucessor\n(6) enumerate\n");
    printf("(7) print tree\n(8) quit\n");
    do option=fgetc(stdin); while(-1 != option && isspace(option));
    option-='0';
    switch(option)
      {
      case 1:
	{
	  printf("type key for new node\n");
	  scanf("%i",&newKey);
	  newInt=(int*) malloc(sizeof(int));
	  *newInt=newKey;
	  RBTreeInsert(tree,newInt,0);
	}
	break;
	
      case 2:
	{
	  printf("type key of node to remove\n");
	  scanf("%i",&newKey);
	  if ( ( newNode=RBExactQuery(tree,&newKey ) ) ) RBDelete(tree,newNode);/*assignment*/
	  else printf("key not found in tree, no action taken\n");
	}
	break;

      case 3:
	{
	  printf("type key of node to query for\n");
	  scanf("%i",&newKey);
	  if ( ( newNode = RBExactQuery(tree,&newKey) ) ) {/*assignment*/
	    printf("data found in tree at location %i\n",(int)newNode);
	  } else {
	    printf("data not in tree\n");
	  }
	}
	break;
      case 4:
	{
	  printf("type key of node to find predecessor of\n");
	  scanf("%i",&newKey);
	  if ( ( newNode = RBExactQuery(tree,&newKey) ) ) {/*assignment*/
	    newNode=TreePredecessor(tree,newNode);
	    if(tree->nil == newNode) {
	      printf("there is no predecessor for that node (it is a minimum)\n");
	    } else {
	      printf("predecessor has key %i\n",*(int*)newNode->key);
	    }
	  } else {
	    printf("data not in tree\n");
	  }
	}
	break;
      case 5:
	{
	  printf("type key of node to find successor of\n");
	  scanf("%i",&newKey);
	  if ( (newNode = RBExactQuery(tree,&newKey) ) ) {
	    newNode=TreeSuccessor(tree,newNode);
	    if(tree->nil == newNode) {
	      printf("there is no successor for that node (it is a maximum)\n");
	    } else {
	      printf("successor has key %i\n",*(int*)newNode->key);
	    }
	  } else {
	    printf("data not in tree\n");
	  }
	}
	break;
      case 6:
	{
	  printf("type low and high keys to see all keys between them\n");
	  scanf("%i %i",&newKey,&newKey2);
	  enumResult=RBEnumerate(tree,&newKey,&newKey2);	  
	  while ( (newNode = StackPop(enumResult)) ) {
	    tree->PrintKey(newNode->key);
	    printf("\n");
	  }
	  free(enumResult);
	}
	break;
      case 7:
	{
	  RBTreePrint(tree);
	}
	break;
      case 8:
	{
	  RBTreeDestroy(tree);
	  return 0;
	}
	break;
      default:
	printf("Invalid input; Please try again.\n");
      }
  }
  return 0;
}



