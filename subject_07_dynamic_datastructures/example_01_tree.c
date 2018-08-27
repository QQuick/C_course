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

/*
This program features recursion (functions calling themselves).

Don't use recursion if you don't need to,
but with tree-like data structurs it's truly indispensable.

Look up the concept of local variables and stack frames.
Use a pen and paper to draw the contents of memory at any point.
PLEASE DO SO INDEED!!
You'll learn a lot from it...

Tree-like datastructures are at the core of databases, OS'es and compilers.
The C compiler you're using rightnow stores your program as a tree.
It uses recursion all over the place, walking that tree to generate machine code.
*/

// ======== Define facilities that constitute a binary tree

typedef struct Node {
    char const *payload;
    struct Node *left, *right;
} Node;

Node *create (char const *payload) {
    printf ("Creating %s\n", payload);   
    Node *node = (Node *) malloc (sizeof (Node));
    node->payload = payload;
    node->left = node->right = 0;
    return node;
}

/*
Traditionally called "walk", although "climb" would be a better word,
the function below performs a "left to right, depth first" treewalk.

- WHAT exactly is meant by "left to right, depth first"?
- Draw the tree that's built up in this program (PLEASE DO INDEED) and the path followed through it.

Most treewalks use this order of traversal, including the ones performed by compilers.
*/    
void walk (Node *node, int indentLevel) {
    if (node) {
        for (int indentIndex = 0; indentIndex < indentLevel; indentIndex++) {
            printf ("    ");
        }
        printf ("Walking %s\n", node->payload);
        walk (node->left, indentLevel + 1);     // Recursive call
        walk (node->right, indentLevel + 1);    // Recursive call
    }
}

void destroy (Node *node) {
    if (node) {
        destroy (node->left);                   // Recursive call
        destroy (node->right);                  // Recursive call
        printf ("Destroying %s\n", node->payload);
        free (node);
    }
}

// ====== Now lets get to the cradle-to-cradle foresting business

int main () {
    printf ("\n");
    
    // ======== Grow tree
    
    Node *tree = create ("root");
    
    tree->left = create ("left branch");
    tree->left->left = create ("left left leaf");
    tree->left->right = create ("left right leaf");
    
    tree->right = create ("right branch");
    tree->right->left = create ("right left leaf");
    tree->right->right = create ("right right leaf");    
    
    // ======== Show tree
    
    printf ("\nIT folks like their trees upside down,\nlike a weeping willow hanging off a cliff:\n\n");
    walk (tree, 0);
    printf ("\n");
    
    // ======== Recycle its resources
    
    destroy (tree);
    
    printf ("\n");
    return 0;
}
