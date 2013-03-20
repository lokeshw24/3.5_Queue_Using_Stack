#include"stack.h"


static void init_stack( node **s ){
	*s=NULL ;
}

/****************************************************/
void init( queue *q ){
	init_stack( &(q->first ));
	init_stack( &(q->second ));

	q->top_first=NULL;
	q->top_second=NULL;

}
/****************************************************/
static node * create_node( int val ){
	node *temp=(node*)malloc( sizeof(node) );
	temp->val=val;
	temp->next=NULL;
	temp->previous=NULL;

return temp;
}
/****************************************************/
static node *push( node **s , int val){
	if( *s==NULL ){
		*s=create_node(val);
		return *s;
	}
	else{
		/*travel till end and then append the value */
		node *temp=*s;
		//node *before=NULL;

		while( temp->next ){
		//	before=temp;
			temp=temp->next;
		}

		temp->next=create_node(val);	
		temp->next->previous=temp;
		return temp->next ;

	}



}
/****************************************************/
void enqueue( queue *q , int val ){
	q->top_first=push( &(q->first) , val );

}
/****************************************************/
static void print_stack( node *s ){
	node *temp=s;
	while(temp){
		printf("%d ", temp->val );
		temp=temp->next;
	}
	printf("\n");

}
/****************************************************/
void print( queue q ){
	/*will print the 2 stacks and not the actual queue,
	 * mainly needed for debugging purpose
	 */
	printf("***************************\n" );
	print_stack( q.first );
	print_stack( q.second );
	printf("***************************\n" );

}
/****************************************************/
static int pop( node **s , node **top ){
	if( (*top)->previous == NULL ){
		/*so this is last node to be popped */
		*s=NULL;
		int popped_val=(*top)->val;
		free( *top );
		*top=NULL;
		return popped_val ;
	}

	int popped_val=(*top)->val;
	*top=(*top)->previous;
	free( (*top)->next );
	(*top)->next = NULL;

return popped_val ;

}
/****************************************************/
int dequeue( queue *q ){

	if( q->second == NULL ){
		if( q->first==NULL ) return ;
		/*so basically queue is empty */

		/*now put all values from first stack to second stack */
		while( q->top_first != q->first ){
			q->top_second=push( &(q->second) , q->top_first->val );
			(q->top_first)=q->top_first->previous;
			free(q->top_first->next );
			q->top_first->next=NULL;
		}
		q->first = NULL;
		return q->top_first->val;

	}
	else{
		return pop( &(q->second) , &(q->top_second) );

	}

}
/****************************************************/

