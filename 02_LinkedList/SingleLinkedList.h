#ifndef SingleLinkedList_h
#define SingleLinkedList_h

typedef struct Node
{
	unsigned int NodeData;
	struct Node *NodeLink;
}node_t;


/******************** PUBPLIC FUNCTIONS ********************/
void Insert_Node_At_Beginning(node_t **List);
void Insert_Node_At_End(node_t **List);
void Insert_Node_After(node_t *List);
void Delete_Node_At_Beginning(node_t **List);
void Delete_Node(node_t *List);
void Display_All_Nodes(node_t *List);
unsigned int Get_Length(node_t *List);



#endif