//
// Created by Miriam Lipkovich on 2019-03-27.
//

#ifndef JSD_HEAP_H
#define JSD_HEAP_H
#include <iostream>
#include <iterator>
namespace Binom{
    struct Tree {
        int value;
        Tree *child; //left, prev
        Tree *sibling;//right, next
        Tree *parent;//parent node
        int degree;//child node
        int key;//priority
        Tree* head;
    };

    Tree* Insert(int value, int key, Tree* h);
    Tree* GetMin(Tree* h);
    Tree* GetMax(Tree* h);
    Tree* Make();
    Tree* Merge(Tree* h1, Tree* h2);
    Tree* Delete(Tree* h);
    Tree* Union(Tree* h1, Tree* h2);
    Tree* Link(Tree *h1, Tree* h2);
    void Change(Tree* h, int newval, int oldval);
    Tree* Find(Tree* h, int val);
    void DecreaseKey (Tree* x);
    void DeleteHeap(Tree* h);
}

#endif //JSD_HEAP_H
