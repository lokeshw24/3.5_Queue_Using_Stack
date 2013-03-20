#include"stack.h"

int main(){
	queue q;
	init(&q);

	enqueue(&q, 1 );
	enqueue(&q, 3 );
	enqueue(&q, -6 );

	print(q);
	printf(">%d \n", dequeue(&q) );
	print(q);
	printf(">%d \n", dequeue(&q) );
	print(q);
	enqueue(&q, 33 );
	enqueue(&q, -25 );

	printf(">%d \n", dequeue(&q) );
	printf(">%d \n", dequeue(&q) );
	printf(">%d \n", dequeue(&q) );
	printf(">%d \n", dequeue(&q) );
	enqueue(&q, 25 );
	enqueue(&q, -2 );
	enqueue(&q, -5 );
	print(q);
	printf(">%d \n", dequeue(&q) );
	printf(">%d \n", dequeue(&q) );
	printf(">%d \n", dequeue(&q) );
	printf(">%d \n", dequeue(&q) );
	printf(">%d \n", dequeue(&q) );

	print(q);
return 0 ;

}
