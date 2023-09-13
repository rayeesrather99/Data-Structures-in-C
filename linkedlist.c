#include <stdio.h>
#include <malloc.h>

struct Node
{
    float data;
    struct Node *next;
};

struct Node* start = NULL;


void traverse();
void prependList(float);
void appendList(float);
void addAfterElement(float , float );

int main()
{
    prependList(30);
    prependList(40);
    prependList(50);
    appendList(500);
    addAfterElement(20,5000);
    traverse();

    return 1;
}

void prependList(float ele){
    struct Node* Newnode;
    Newnode = (struct Node*) malloc(sizeof(struct Node));

    Newnode->data = ele;
    Newnode->next = start;

    start = Newnode;

}

void traverse(){
    struct Node* handle;
    handle = start;

    while (handle != NULL)
    {
        printf("%f ", handle->data);
        handle = handle->next;
    }   
}

void appendList(float ele){
    struct Node* Newnode;
    Newnode = (struct Node*) malloc(sizeof(struct Node));

    Newnode->data = ele;
    Newnode->next = NULL;

    struct Node* handle;
    
    while (handle->next != NULL)
    {
        handle = handle->next;
    }

    handle->next = Newnode;
    

}

void addAfterElement(float whichElm, float afterWhichElm)
{
    struct Node* Newnode;
    Newnode = (struct Node*) malloc(sizeof(struct Node));

    if (Newnode == NULL)
    {
        printf("%d Memory allocation failed\n");
    }
    
    Newnode->data = whichElm;
    Newnode->next = NULL;

    struct Node* handle;
    handle = start;
    

    while (handle != NULL && handle->data != afterWhichElm)
    {
        handle = handle->next;
    }
    if (handle == NULL)
    {
        printf("%f doesn't exist in the linked list\n", afterWhichElm);
        free(Newnode);
        return;
    }
    
    Newnode->next = handle->next;
    handle->next = Newnode;
}