#include <stdio.h> 

struct node_type {
	char data[21];
	struct node_type *next;
};
typedef struct node_type list;

void showList();
list *sortInsert();
list *createNode();
list *find();

main()
{
	list *newnode, *start = NULL; //start will point to first node of the list
	char c = 'y';
	char word[21];

	while(c != 'n' && c != 'N')
	{
		printf("\nEnter the word: ");
		scanf("%s",word); fflush(stdin);
		newnode = createNode();
		strcpy(newnode->data, word);
		newnode->next = NULL;
		if(!find(start,newnode->data)) 
			start = sortInsert(start,newnode);
		printf("\nTHE LIST SO FAR: "); showList(start); printf("\n\n");

		printf("\nDo you want to add new data in the list? (y/n): ");
		scanf("%c",&c); getchar(); fflush(stdin);
	}
	printf("\nTHE SORTED LIST IS: "); showList(start); printf("\n\n");
}


/* Function to create a Node. Allocates memory for a new node. */
list *createNode()
{
	list *new; 
	new = (list *)malloc(sizeof(list));
	return(new);
}

list *sortInsert(list *start, list *newnode)
{ 
	list *prev,*curr;

	if(start==NULL)
	{
		//List is empty. Insert first node
		return(newnode);
	}

	//The code below will be executed when list is not empty
	curr = start;
	prev = curr;

	if(strcmp(newnode->data,curr->data)<0)
	{
		//new node < first node. Insert at the beginning.
		start = newnode;
		newnode->next = curr;
		return(start);
	}

	//The code below will be executed when new node is to
	//be inserted anywhere in the middle or at the end
	while(curr!=NULL)
	{
		curr = curr->next;
		if(curr==NULL)
		{
			//We have reached the end. Attach node to the end.
			prev->next = newnode;
			newnode->next = curr;
			return(start);
		}
		else
		{
			if(strcmp(newnode->data,curr->data)<0)
			{
				prev->next = newnode;
				newnode->next = curr;
				return(start);
			}
			prev = prev->next;
		}
	}

	return(start);
}

/*
 Function to search a data item in the list and return the node address
 that matches data. In case no match found, returns NULL
*/
list *find(list *st, int dt)
{
	while(st)
		if(strcmp(st->data,dt) == 0)
			return (st);
		else
			st = st->next;
	return(st);
}

void showList(list *temp) 
{
	while(temp)
	{
		printf("%s ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}