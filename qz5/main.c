#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node_t;

node_t* allocate_node(int data) {
    node_t* newnode = malloc(sizeof(node_t));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void show_list(node_t* list) {
    node_t* tmp = list;
    while(tmp != NULL) {
        printf("[%d]->", tmp->data);
        tmp = tmp->next;
    }
    printf("null\n");
}

node_t* append_node(node_t* list, int new_data) {
    node_t* newnode = allocate_node(new_data);
    newnode->data = new_data;
    newnode->next = NULL;
    if(list == NULL) {
         list = newnode;
    } else {
        node_t* lastnode = list;
        while(lastnode->next != NULL) {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
    }
    return list;
}

void free_all_node(node_t* list) {
     while (list != NULL){ 
        node_t* temp = list; 
        list = list -> next;
        printf("free([%d])->",temp->data);
        free(temp);
    }
    printf("null");
}

int main() {
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 11);
    show_list(head);
    head = append_node(head, 222);
    show_list(head);
    head = append_node(head, 3333);
    show_list(head);
    free_all_node(head);
}
