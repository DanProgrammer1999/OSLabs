#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char IndexOutOfBoundException[] = "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                                        "!! Exception: index is out of bounds !!\n"
                                        "!! Returned value is -1.             !!\n"
                                        "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";

typedef struct Node {
    struct Node *next;
    int value;
} Node;

typedef struct List {
    struct Node *head;
    int size;
} List;


/**
 * Insert a value into the list.
 *
 * @param value Integer to be inserted.
 */
void insert(List *list, int value, int index) {

    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = 0;

    if (index > list->size || index < 0) {
        printf("%s", IndexOutOfBoundException);
    }

    if (list->size == 0) {
        list->head = newNode;
    } else {
        Node *curr = list->head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        if(index == 0){
            newNode->next = list->head;
            list->head = newNode;
        }
        else {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    list->size++;
}

/**
 * Remove an element at the specified index.
 *
 * @param index A position in list of the element to be removed.
 * @return      A value stored on that position.
 */
int removeElement(List *list, int index) {
    if (index < 0 || list->size <= index) {
        printf("%s", IndexOutOfBoundException);
        return -1;
    }

    Node *curr = list->head;

    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }

    int res;
    Node *toFree;
    if(index == 0){
        res = curr->value;
        toFree = list->head;
        list->head = curr;
    }
    else{
        res = curr->next->value;
        toFree = curr->next;
        curr->next = curr->next->next;
    }

    free(toFree);
    list->size--;

    return res;
}

/**
 *  Print out every element in the list.
 */
void printList(List *list) {
    Node *curr = list->head;

    printf("{");

    while (curr != 0) {
        printf("%d", curr->value);

        if (curr->next != 0) {
            printf(", ");
        }
        curr = curr->next;
    }

    printf("}\n");
}

void init(List *l) {
    l->head = 0;
    l->size = 0;
}

int main() {
    List l;
    List *lp = &l;
    init(lp);

    insert(lp, 10, 0);
    printList(lp);
    insert(lp, 5, 0);
    printList(lp);
    insert(lp, 9, 1);
    printList(lp);
    printf("%i\n", removeElement(lp, 1));
    printList(lp);
    removeElement(lp, 1);
    printList(lp);
    removeElement(lp, 5);
    printList(lp);
}