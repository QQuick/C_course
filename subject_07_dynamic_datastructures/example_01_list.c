#include <stdio.h>

// ======== Define facilities that constitute a linked list

// If you'd wish that the append and remove functions were somehow part of Node,
// you're actually wishing to learn C++... Respect!!

typedef struct {
    char *payload;
    Node *next;
} Node;

void append (Node **tail, char *payload) {
    *tail = malloc (sizeof (Node));
    *tail->payload = payload;
    *tail->next = 0;
    *tail = *tail->next;
}

void remove (Node **head) {
    Node *next = *head->next;
    free (*head);
}

// ======== Und jetzt kommen die kamele mit den groszen fueszen...
// (And now come the camels with the big feet...)

int main () {
    Node *list = 0;
    
    // ======== Build up singly linked list
    
    Node **tail = &list;
    append (tail, "Time");
    append (tail, "Flies");
    append (tail, "Like");
    append (tail, "An");
    append (tail, "Arrow");
    append (tail, "")
    append (tail, "Fruit");
    append (tail, "Flies");
    append (tail, "Like");
    append (tail, "A");
    append (tail, "Banana");
    
    // ======== Use list
    
    for (Node *current = list; current; current = current->next) {
        printf ("%s\n", current->payload);
    }
    
    // ======== Tear down list, freeing its memory for subsequent use by the program
    
    for (Node **head = &list; *head->next; remove (head) {
    }
    
    return 0;
}