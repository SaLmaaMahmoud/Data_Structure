#include <stdio.h>
#include <stdlib.h>

#include "StackArray.h"


/******************** PRIVATE FUNCTIONS ********************/
static unsigned char StackIsEmpty (Stack_t* StackObj) ;
static unsigned char StackIsFull (Stack_t* StackObj) ;
/***********************************************************/


Stack_t* CreateStack (unsigned int MaxSize, StackStatus_t *RetStatus)
{
	Stack_t *MyStack = NULL ;
	
	if (NULL == RetStatus)
	{
		*RetStatus = STACK_NULL_POINTER ;
		MyStack = NULL ;
	}
	else
	{
		/* Allocate the Stack in the Heap */
		MyStack = (Stack_t *) malloc(sizeof(Stack_t)) ;
		
		if (!MyStack)
		{
			/* Stack is not created successfully */
			*RetStatus = STACK_NOK ;
			MyStack = NULL ;
		}
		else 
		{
			MyStack->StackTop = -1 ;
			MyStack->ElementCount = 0 ;
			MyStack->StackMaxSize = MaxSize ;
			MyStack->StackArray = (void **) calloc(MyStack->StackMaxSize, sizeof(Void *)) ;
			
			if (!MyStack->StackArray)
			{
				/* Free the Stack Object */
				free(MyStack) ;
				
				/* Array is not created successfully */
				MyStack = NULL ;
				*RetStatus = STACK_NOK ;
			}
			else
			{
				/* Stack is created successfully */
				*RetStatus = STACK_OK ;
			}
		}
	}
	
	return MyStack ;
}


Stack_t* DestroyStack (Stack_t* StackObj, void* ItemPtr)
{
	if ((NULL == RetStatus) || (NULL == StackObj))
	{
		*RetStatus = STACK_NULL_POINTER ;
	}
	else
	{
		/* Release the Array object */
		free (StackObj->StackArray) ;
		
		/* Release the stack object */
		free (StackObj) ;
		
		*RetStatus = STACK_OK ;
	}
	
	return NULL ;
}


StackStatus_t PushStack (Stack_t* StackObj, void* ItemPtr)
{
	StackStatus_t StackStatus = STACK_NOK ;
	
	if ((NULL == StackObj) || (NULL == ItemPtr))
	{
		StacktStatus = STACK_NULL_POINTER ;
	}
	else
	{
		if (StackIsFull(StackObj))
		{
			/* Stack is full, prevent Stack Overflow */
			StackStatus = STACK_FULL ;
		}
		else
		{
			/* Points to the next element in the Stack */
			(StackObj->StackTop)++ ;
			StackObj->StackArray[StackObj->StackTop] = ItemPtr ;
			
			/* Increment the number of elements in the Stack */
			(StackObj->ElementCount)++ ;
			StackStatus = STACK_OK ;
			
		}		
	}
	
	return StackStatus ;
}


void* PopStack (Stack_t* StackObj, StackStatus_t *RetStatus)
{
	void *DataPtrOut = NULL ;
	
	if ((NULL == StackObj) || (NULL == ItemPtr))
	{
		StacktStatus = STACK_NULL_POINTER ;
		DataPtrOut = NULL ;
	}
	else
	{
		if (StackIsEmpty(StackObj))
		{
			/* Stack is Empry, prevent Stack Underflow */
			*RetStatus = STACK_EMPTY ;
			
			DataPtrOut = NULL ;
			}
		else
		{
			DataPtrOut = StackObj->StackArray[StackObj->StackTop] ;
			
			/* Points to the next element in the Stack */
			(StackObj->StackTop)-- ;
			
			/* Decrement the number of elements in the Stack */
			(StackObj->ElementCount)-- ;
			*RetStatus = STACK_OK ;
			
		}		
	}
	
	return DataPtrOut ;
}


void* StackTop (Stack_t* StackObj, StackStatus_t *RetStatus)
{
	void *DataPtrOut = NULL ;
	
	if ((NULL == StackObj) || (NULL == ItemPtr))
	{
		StacktStatus = STACK_NULL_POINTER ;
		DataPtrOut = NULL ;
	}
	else
	{
		if (StackIsEmpty(StackObj))
		{
			/* Stack is Empry, prevent Stack Underflow */
			*RetStatus = STACK_EMPTY ;
			
			DataPtrOut = NULL ;
			}
		else
		{
			/* Copy the top element to the user */
			DataPtrOut = StackObj->StackArray[StackObj->StackTop] ;
			
			*RetStatus = STACK_OK ;
			
		}		
	}
	
	return DataPtrOut ;
}


StackStatus_t StackCount (Stack_t* StackObj, unsigned int *StackCounter)
{
	StackStatus_t StackStatus = STACK_NOK ;
	
	if ((NULL == StackObj) || (NULL == ItemPtr))
	{
		StacktStatus = STACK_NULL_POINTER ;
	}
	else
	{
		*StackCounter = StackObj->ElementCount ;
		StackStatus = STACK_OK ;
	}
	return StackStatus ;
}


static unsigned char StackIsEmpty (Stack_t* StackObj)
{
	return (StackObj->ElementCount == 0) ;
}


static unsigned char StackIsFull (Stack_t* StackObj)
{
	return (StackObj->ElementCount == StackObj->StackMaxSize) ;
}
