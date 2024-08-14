#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};


struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertMiddle(struct Node** head_ref, char data) {
    struct Node* newNode = createNode(data);
    struct Node* slow = *head_ref;
    struct Node* fast = *head_ref;

   
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

   
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

 
    newNode->next = slow->next;
    slow->next = newNode;
}


void deleteMiddle(struct Node** head_ref) {
    
    if (*head_ref == NULL) {
        return;
    }

    struct Node* slow = *head_ref;
    struct Node* fast = *head_ref;
    struct Node* prev = NULL;

    
    if (slow->next == NULL) {
        free(slow);
        *head_ref = NULL;
        return;
    }

    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    
    if (prev != NULL) {
        prev->next = slow->next;
        free(slow);
    }
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf("%c, ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    struct Node* head = NULL;

    head = createNode('a');
    head->next = createNode('b');
    head->next->next = createNode('c');
    head->next->next->next = createNode('d');
    head->next->next->next->next = createNode('e');

    printf("Original List: ");
    printList(head);

   
    insertMiddle(&head,'f');
    printf("After Inserting letter 'f' in the Middle: ");
    printList(head);

    
    deleteMiddle(&head);
    printf("After Deleting Middle Node: ");
    printList(head);

   
    freeList(head);
    return 0;
}
