#include<stdio.h>
#include<stdlib.h>


typedef struct abc{
	int val;
	struct abc *next;
	struct abc *previous;

}node;


typedef struct pqr{
	node *first;
	node *top_first;

	node *second ;
	node *top_second;
}queue;

/*********************************************/
void init( queue *q );
void enqueue( queue *q , int val );
int dequeue( queue *q );
void print( queue q );
