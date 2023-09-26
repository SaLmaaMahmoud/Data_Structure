#ifndef STACK_ARRAY_H
#Define STACK_ARRAY_H


typedef struct Stack
{
	/* Points to the array that allocated in the Heap */	
	void **Stack_Array ;	

	/* The actual number of elements in the Stack */	
	signed int ElementCount ; 

	/* The maximum number of elements in the Stack */	
	unsigned int StackMaxSize ;     
	
	/* The index of the top element in the Stack */
	signed int StackTop ;           
} Stack_t;


typedef enum StackStatus
{
	/* Stack operation is not performed successfully */
	STACK_NOK = 0 ,  			
	
	/* Stack operation is performed successfully  */
	STACK_OK,   

	/* Stack is Full */
	STACK_FULL,  

	/* Stack is Empty */	
	STACK_EMPTY,             

	/* NULL pointer passed to the Stack operations */	
	STACK_NULL_POINTER          
} StackStatus_t;



/******************** PUBPLIC FUNCTIONS ********************/
Stack_t* CreateStack (unsigned int MaxSize, StackStatus_t *RetStatus) ;
Stack_t* DestroyStack (Stack_t* StackObj, void* ItemPtr) ;
StackStatus_t PushStack (Stack_t* StackObj, void* ItemPtr) ;
void* PopStack (Stack_t* StackObj, StackStatus_t *RetStatus) ;
void* StackTop (Stack_t* StackObj, StackStatus_t *RetStatus) ;
StackStatus_t StackCount (Stack_t* StackObj, unsigned int *StackCounter) ;


#endif
