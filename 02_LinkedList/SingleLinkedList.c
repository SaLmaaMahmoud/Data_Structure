#include <stdio.h>
#include <stdlib.h>

#include "SingleLinkedList.h"

node_t *ListHead = NULL ;

void Insert_Node_At_Beginning(node_t **List)
{
	node_t *TempNode = NULL ;
	
	TempNode = (node_t *) malloc(sizeof(node_t)) ;
	
	if (NULL != TempNode)
	{
		printf("Enter The Node Data : ") ;
		scanf("%i", &TempNode->NodeData) ;
		
		/* Check if Linked List is Empty */
		if (NULL != *List)
		{
			/* Linked List is Empty */
			
			TempNode->NodeLink = NULL ;
			*List = TempNode ;
		}
		else
		{
			/* Linked List is not Empty */
			
			TempNode->NodeLink = *List ;
			*List = TempNode ;
		}
	}
	else
	{
		/* Do Nothing */
	}
}


void Insert_Node_At_End(node_t **List)
{
	node_t *TempNode = NULL ;
	node_t *LastNode = NULL ;
	
	TempNode = (node_t *) malloc(sizeof(node_t)) ;
	
	if (NULL != TempNode)
	{
		printf("Enter The Node Data : ") ;
		scanf("%i", &TempNode->NodeData) ;
		
		TempNode->NodeLink = NULL ;
		
		/* Check if Linked List is Empty */
		if (NULL != *List)
		{
			/* Linked List is Empty */
			
			*List = TempNode ;
		}
		else
		{
			/* Linked List is not Empty */
			LastNode = *List;
			
			/* Traverse Nodes */
			while (LastNode->NodeLink != NULL)
			{
				LastNode = LastNode->NodeLink ;
			}
			
			LastNode->NodeLink = TempNode ;
		}
	}
	else
	{
		/* Do Nothing */
	}
}


void Insert_Node_After(node_t *List)
{
	node_t *TempNode = NULL ;
	node_t *NodeListCounter = NULL ;
	
	unsigned int NodePosition = 0 ;
	unsigned int ListLength = 0 ;
	
	/* Points to the First Node of the List */
	unsigned int NodeCounter = 0 ;
	
	printf("Enter the Node position (First Node position is 1 ) : ") ;
	scanf("%i", &NodePosition) ;
	
	ListLength = Get_Length(List) ;
	
	if (NodePosition > ListLength)
	{
		printf("Invalid Node Position. Please, Try again!!\n") ;
	}
	else
	{
		NodeListCounter = List ;
		
		while (NodeCounter < NodePosition)
		{
			NodeCounter++ ;
			NodeListCounter = NodeListCounter->NodeLink ;
		}
		
		TempNode = (node_t *) malloc(sizeof(node_t)) ;
		
		if (NULL != TempNode)
		{
			printf("Enter The Node Data : ") ;
			scanf("%i", &TempNode->NodeData) ;
			
			TempNode->NodeLink = NodeListCounter->NodeLink ; ;
			
			NodeListCounter->NodeLink = TempNode ;
		}
		else
		{
			/* Do Nothing */
		}
	}
}


void Delete_Node_At_Beginning(node_t **List)
{
	node_t *TempNode = *List ;
	unsigned int ListLength = 0 ;
	
	ListLength = Get_Length(*List) ;
	
	if (ListLength == 0)
	{
		printf("Nothing to be deleted, The List is already Empty!!\n") ;
	}
	else
	{
		*List = TempNode->NodeLink ;
		TempNode->NodeLink =NULL ;
		free(TempNode) ;
	}
}


void Delete_Node(node_t *List)
{
	node_t *NodeListCounter = List ;
	node_t *NextNode = List ;
	
	unsigned int NodePosition = 0 ;
	unsigned int ListLength = 0 ;
	
	/* Points to the First Node of the List */
	unsigned int NodeCounter = 1;
	
	printf("Enter the Node position (First Node position is 1 ) : ") ;
	scanf("%i", &NodePosition) ;
	
	ListLength = Get_Length(List) ;
	
	if ((NodePosition > ListLength) || (ListLength == 1))
	{
		printf("Use Delete_Node_At_Beginning !!\n");
	}
	else
	{
		while (NodeCounter < (NodePosition - 1))
		{
			NodeCounter++ ;
			NodeListCounter = NodeListCounter->NodeLink ;
		}
		
		NextNode = NodeListCounter->NodeLink ;
		NodeListCounter->NodeLink = NextNode->NodeLink ;
		
		free(NextNode) ;
	}
}


void Display_All_Nodes(node_t *List)
{
	node_t *TempNode = List ;
	
	if (NULL == TempNode)
	{
		printf("List is Empty!!! \n") ;
	}
	else
	{
		printf("The List Nodes are : ") ;
		
		while (TempNode != NULL)
		{
			printf("%i -> ", TempNode->NodeData) ;
			TempNode = TempNode->NodeLink ;
		}
		
		if (NULL == TempNode)
		{
			printf("NULL \n") ;
		}
	}
}


unsigned int Get_Length(node_t *List)
{
	node_t *TempNode = List ;
	
	unsigned int NodeCounter = 0 ;
	
	while (TempNode != NULL)
	{
		NodeCounter++ ;
		TempNode = TempNode->NodeLink ;
	}
	
	return NodeCounter ;
}
