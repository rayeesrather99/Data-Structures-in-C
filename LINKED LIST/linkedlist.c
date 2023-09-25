// Creation and traversal in linked list ||

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;

/**
 * Inserts a new node with the given data element at the beginning of the linked list.
 *
 * @param element The data element to be inserted.
 */
void prependElements(int element)
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));
    if (Newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    Newnode->data = element;
    Newnode->next = start;
    start = Newnode;
}

/**
 * Inserts a new node with the given data element at the beginning of the linked list.
 *
 * @param element The data element to be inserted.
 */
void insertAtBeginning(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = element;
    newNode->next = start;
    start = newNode;
}

/**
 * Inserts a new node with the given data element at the end of the linked list.
 *
 * @param element The data element to be inserted.
 */
void insertAtEnd(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = start;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->data = element;
    newNode->next = NULL;
}

/**
 * Inserts a new node with the given data element at the specified index in the linked list.
 *
 * @param element The data element to be inserted.
 * @param index The index at which to insert the new node (0-based).
 *
 * If the given index is out of range, prints an error message and returns without modifying the list.
 */
void insertInBetween(int element, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = start;

    int i = 0;
    while (i != index - 1 && current != NULL)
    {
        current = current->next;
        i++;
    }
    if (current == NULL)
    {
        printf("\n");
        printf("ERROR 404! You have entered wrong Index in InsertBetween function that is out of range!\n");
        return;
    }

    newNode->data = element;
    newNode->next = current->next;
    current->next = newNode;
}

/**
 * Inserts a new node with the given data element after the specified node in the linked list.
 *
 * @param prevNode The data element after which the new node is to be inserted.
 * @param element The data element to be inserted.
 *
 * If the specified node does not exist, prints an error message and returns without modifying the list.
 */
void insertAfterNode(int prevNode, int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = start;

    while (current != NULL && current->data != prevNode)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("\n");
        printf("------ERROR------\n");
        printf("The element you entered doesn't exist\n");
        printf("\n");
        return;
    }
    newNode->data = element;
    newNode->next = current->next;
    current->next = newNode;
} 

/**
 * Deletes the first node of the linked list.
 */
void deleteAtBeginning()
{
    struct Node *current = start;
    start = start->next;
    free(current);
}

/**
 * Deletes the last node of the linked list.
 */
void deleteAtEnd()
{
    struct Node *current = start;
    struct Node *previous = start;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
}

/**
 * Deletes the node after the specified node in the linked list.
 *
 * @param prevNode The data element after which the node is to be deleted.
 *
 * If the specified node does not exist or there is no node after it, prints an error message and returns without modifying the list.
 */
void deleteAfterNode(int prevNode)
{
    struct Node *previous = start;
    struct Node *current = start;

    if (previous->data == prevNode)
    {
        printf("There is no node after the first node to remove\n");
        return;
    }

    while (current != NULL && previous->data != prevNode)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("\n");
        printf("----------ERROR-----\n");
        printf("The element you want to delete doesn't exist\n");
        printf("\n");
        return;
    }
    
    previous->next = current->next;
    free(current);
}

/**
 * Traverses the linked list and prints the data elements of each node.
 */
void traverseList()
{
    struct Node *current = start;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // Prepend elements to the linked list
    printf("The items in list are: \n");
    prependElements(30);
    prependElements(40);
    prependElements(50);
    prependElements(60);
    prependElements(70);
    traverseList();

    printf("\n");

    // Insert element at the beginning of the linked list
    printf("----------------------------------INSERTION AT BEGINNIG----------------------\n");
    int n;
    printf("Enter the no to be inserted at beginning of list: ");
    scanf("%d", &n);
    insertAtBeginning(n);
    printf("\n");

    // Insert element at the end of the linked list
    printf("-----------------------------------INSERTION AT END----------------------\n");
    int insertElmAtEnd;
    printf("Enter the no to be inserted at the end of list: ");
    scanf("%d", &insertElmAtEnd);
    insertAtEnd(insertElmAtEnd);

    // Print the modified linked list
    printf("\n");
    printf("The modified Linked List after inserting element at first and end: \n");
    traverseList();
    printf("\n");

    // Insert element at a specific index in the linked list
    printf("-----------------------------------INSERTION IN BETWEEN----------------------\n");
    int insertElmAtInBetween,indexOfInsertElmAtInBetween;
    printf("Enter the no to be inserted at a specific index in the list: ");
    scanf("%d", &insertElmAtInBetween);

    printf("Enter the index at which you want to insert the element: ");
    scanf("%d", &indexOfInsertElmAtInBetween);
    insertInBetween(insertElmAtInBetween, indexOfInsertElmAtInBetween);
    printf("\n");

    // Print the modified linked list
    printf("\n");
    printf("The modified Linked List after inserting element at first, end and in between: \n");
    traverseList();
    printf("\n");


    // Insert element after a specific node in the linked list
    printf("-----------------------INSERTION AFTER A SPECIFIC NODE--------------------\n");
    int insertElmAfterNode, insertElmAfterNodeIndex;
    printf("Enter the no to be inserted after a specific node in the list: ");
    scanf("%d", &insertElmAfterNode);

    printf("Enter the node after which you want to insert the element: ");
    scanf("%d", &insertElmAfterNodeIndex);
    insertAfterNode(insertElmAfterNodeIndex, insertElmAfterNode);
    printf("\n");

    // Print the modified linked list
    printf("The modified Linked List after inserting element at first, end, in between and after a specific node: \n");
    traverseList();
    printf("\n");

    
    //Delete element at the beginning of the linked list
    printf("-----------------------------------DELETION AT BEGINNING----------------------\n");
    printf("The modified Linked List after deleting element at beginning: \n");
    deleteAtBeginning();
    traverseList();
    printf("\n");

    //Delete element at the end of the linked list
    printf("-----------------------------------DELETION AT END----------------------\n");
    printf("The modified Linked List after deleting element at end: \n");
    deleteAtEnd();
    traverseList();
    printf("\n");

    // Delete element after a specific node in the linked list
    printf("--------------------------DELETION AFTER A SPECIFIC NODE--------------------\n");
    int deleteElmAfterNode;
    printf("Enter the no to be deleted after a specific node in the list: ");
    scanf("%d", &deleteElmAfterNode);
    deleteAfterNode(deleteElmAfterNode);
    traverseList();
    printf("\n");

    // Print the modified linked list
    printf("-----------------------------------FULL MODIFIED LIST----------------------\n");
    printf("The FULL modified Linked List is: ");
    traverseList();
    printf("----------------------------------------------------------------------------------------\n");
    return 0;
}