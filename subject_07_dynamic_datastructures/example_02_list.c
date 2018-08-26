/*
Copyright 2018 Jacques de Hooge, GEATEC engineering, www.geatec.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdlib.h>
#include <stdio.h>

// ======== Define facilities that constitute a singly linked list

typedef struct Node {
    char const *payload;
    struct Node *next;
} Node;

/*
--------------------------------------------------------------------------------
If you wish the above syntax were simply

    struct Node {
        char const *payload;
        Node *next;
    };

you're actually looking for C++ structs.
--------------------------------------------------------------------------------
*/

void append (Node ***tail, char const *payload) {
    **tail = (Node *) malloc (sizeof (Node));
    (**tail) ->payload = payload;
    (**tail) ->next = 0;
    *tail = & ((**tail) ->next);
}

/*
--------------------------------------------------------------------------------
If you wish that in the code above there were less **,
you're actually looking to for C++ references.

If you think that 

    **tail = new Node (payload);

is much simpler than

    **tail = (Node *) malloc (sizeof (Node));
    (**tail) ->payload = payload;
    (**tail) ->next = 0;
    
you're acually looking for C++ constructors.
--------------------------------------------------------------------------------
*/

void dispose (Node ***head) {
    Node *next = (**head) ->next;
    free (**head);
    *head = &next;
}

/*
--------------------------------------------------------------------------------
If you wish that the append and dispose functions were somehow part of Node,
you're actually looking for C++ classes.
--------------------------------------------------------------------------------
*/

// ======== Und jetzt kommen die kamele mit den groszen fueszen...
// (And now come the camels with the big feet...)

int main () {
    Node *list = 0;
    
    // ======== Build up singly linked list
    
    Node **tail = &list;
    append (&tail, "Learning");
    append (&tail, "C");
    append (&tail, "is");
    append (&tail, "very");
    append (&tail, "useful,");
    append (&tail, "especially");
    append (&tail, "as");
    append (&tail, "a");
    append (&tail, "stepping");
    append (&tail, "stone");
    append (&tail, "to");
    append (&tail, "learning");
    append (&tail, "C++!");
    
    // ======== Use list
    
    printf ("\n");
    for (Node *current = list; current; current = current->next) {
        printf ("%s ", current->payload);
    }
    printf ("\n\n");
    
    // ======== Tear down list, freeing its memory for subsequent use by the program
    
    for (Node **head = &list; (*head) ->next; dispose (&head)) {
    }
    
    return 0;
}

/*
--------------------------------------------------------------------------------
If you think C is faster than C++, you've been Internapped,
C and C++ generate exactly the same machine code in comparable cases.

If you think the Arduino IDE uses C, you've been Internapped,
the Arduino environment has exclusively supported C++ for many years.

If you think everything that people say on the Internet is true,
stay awake tonight, because little green men may come from Mars to abduct you...
--------------------------------------------------------------------------------
*/
