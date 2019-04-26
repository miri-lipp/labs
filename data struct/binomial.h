//
// Created by Miriam Lipkovich on 2019-04-04.
//

#ifndef STRUCT_BINOMINAL_H
#define STRUCT_BINOMINAL_H
#include <ctime>
#include <cstdlib>
#include <iostream>
struct node{
    int data;
    int degree;//number of children
    node* child;//left
    node* sibling;//right
    node* parent;
};
node* MakeHeap();
node* Insert(node*, node*);
node* CreateNode(int);
node* Union(node*, node*);
node* Merge(node*, node*);
void Link(node*, node*);
node* Search(node*, int);
int Revert(node*);
node* ExtractMinimum(node*);
void DecreaseKey(node*, int, int);
int Delete(node*, int);
void PrintNode(node*);
void PrintHeap(node*);

#endif //STRUCT_BINOMINAL_H
