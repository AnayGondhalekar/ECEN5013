#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * prev;
    struct node * next;
};

struct info
{
	uint32 data;
	struct node NodeData;
};

struct info * Insert_at_end(struct info * head, int data_to_add)
{
    struct info * modInfo = (struct info *)malloc(sizeof(struct info));
    modInfo -> data = data_to_add;
    modInfo -> NodeData.next = NULL;
    if(head == NULL) 
    {
 	head = modInfo;
 	return head;
    }
    else
    {
    while(temp_head-> NodeData.next != NULL)
    {
        temp_head = temp_head -> NodeData.next;
    }
	
	modInfo -> NodeData.next = NULL;
	modInfo -> NodeData.prev = temp_head;
	temp_head -> NodeData.next = modInfo;
	return head;
    }
}

struct info * Insert_at_beginning(struct info * head, int data_to_add)
{
    struct info * modInfo = (struct info *) malloc(sizeof(struct info));
    modInfo -> data = data_to_add;
    modInfo -> NodeData.prev = NULL;
    modInfo -> NodeData.next = NULL;
    if(head == NULL) 
    {
	head = modInfo;
	return head;
    }
    else
    {
	modInfo -> NodeData.next = head;
	head = modInfo;
    }
	return head;
}

struct info * Insert_at_position(struct info * head, int data, int position)
{
    int i;
    struct info * modNode, * temp_head;
    modNode = (struct node*)malloc(sizeof(struct node));
    if(position == 1)
    {
        Insert_at_Head(head, data);
    }
     else
    {
        modNode -> data = data; 
        modNode -> NodeData.next = NULL;
        temp_head = head;

        for(i=1; i< position-1; i++)
        {
         temp_head = temp_head -> NodeData.next;
         if(temp_head == NULL)
         break;
        }

    }
    return head;
}

struct info * Delete_at_beginning(struct info * head)
{
    if(head == NULL)
    {
        printf("No node to delete");
    }
    else
    {
        struct info * temp_head;
        temp_head = head;
        head = head -> NodeData.next;
        head -> NodeData.prev = NULL;
        free(temp_head);
    }
    return head;
}

struct info * Delete_from_end(struct info * head)
{
    struct info * temp_head = head;
    struct info * modInfo = (struct info *)malloc(sizeof(struct info));
    if(head == NULL) 
    {
       head = modInfo;
       printf("");
       return;
    }
    while(temp_head -> NodeData.next != NULL)
    {
       temp_head = temp_head -> NodeData.next;
    }
	modInfo = temp_head-> NodeData.prev;
	modInfo -> NodeData.next = NULL;
	free(temp_head);
	return head;
}

struct info * Delete_from_position(struct info * head, int position)
{
    int i;
    struct info * modNode, * temp_head;
    modNode = (struct node*)malloc(sizeof(struct node));
    if(modNode == NULL)
    {
        printf("Not found to delete");
    }
    else
    {
        temp_head = head;
        modNode = head;
        
        if(position == 1)
        {
            head = head -> NodeData.next;
            free(temp_head);
        }
        else
        {
            for(i=1; i <= position; i++)
            {
                temp_head = temp_head -> NodeData.next;
            }
            
            for(i=1; i < position-1; i++)
            {
                modNode = modNode -> NodeData.next;
            }
            
            modNode -> NodeData.next = temp;
            temp_head-> NodeData.prev = modNode;
        }
    }
    return head;
}
int size(struct info * head)
{
    struct info * temp_head = head;
    int size;
    if(temp_head == NULL)
    {
     size = 0;
    }
    
    while(temp_head != NULL)
    {
        temp_head = temp_head -> NodeData.next;
        size++;
    }
    return size;
}


