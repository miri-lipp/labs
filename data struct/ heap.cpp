#include "heap.h"
using namespace Binom;

int main() {

    return 0;
}

Tree* Make() {
    Tree *temp = new Tree;
    temp->degree = 0;
    temp->sibling = temp->child = temp->parent = nullptr;
    temp->head = nullptr;
    return temp;
}

Tree* Merge(Binom::Tree *h1, Binom::Tree *h2) {
    Tree* h3 = nullptr;
    if (h1 == nullptr)
        return h2;
    if(h2 == nullptr)
        return h1;
    else if(h1->degree <= h2->degree)
        h3 = h1;
    if(h1->degree > h2->degree)
        h3 = h2;
    while(h1 != nullptr && h2 != nullptr){
        if(h1->degree < h2->degree)
            h1 = h1->sibling;
        else if(h1->degree == h2->degree){
            Tree* sib = h1->sibling;
            h1->sibling = h2;
            h1 = sib;
        }
        else if(h1->degree > h2->degree){
            Tree* sib = h2->sibling;
            h2->sibling = h1;
            h2 = sib;
        }
    }
    return h3;
}

Tree* GetMin(Binom::Tree *h) {
    Tree* x = h, *min;
    min->key = x->key;
    while(x != nullptr){
        if(x->key < min->key)
            min = x;
        x = x->sibling;
    }
    return min;
}

Tree* Insert(int value, int key, Tree* h) {
    Tree* x;
    x->key = key;
    x->value = value;
    x->parent = nullptr;
    x->sibling = nullptr;
    x->child = nullptr;
    x->degree = 0;
    return Union(h, x);
}

Tree* Union(Tree* h1, Tree* h2){
    Tree* next, *prev = nullptr, *x;
    Tree *h = Make();
    h->head = Merge(h1, h2);//free h1 and h2
    if(h->head == nullptr)
        return h;
    x = h;
    next = x->sibling;
    while(next != nullptr){
        if(x->degree != next->degree){
            prev = x;
            x = next;
            next = x->sibling;
        }
        else if(x->degree == next->degree && x->degree == next->sibling->degree && next->degree == next->sibling->degree){
            prev = x;
            x = next;
            next = x->sibling;
        }
        else if(x->degree == next->degree && next->degree != next->sibling->degree && x->key <= next->key){
            x->sibling = next->sibling;
            Link(next, x);
            next = x->sibling;
        }
        else if(x->degree == next->degree && next->degree != next->sibling->degree && x->key > next->key){
            prev->sibling = next;
            Link(x, next);
            x = next;
            next = x->sibling;
        }
    }
    return h;
}

Tree* Link(Binom::Tree *h1, Binom::Tree *h2){
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree = h2->degree + 1;
}

Tree* GetMax(Binom::Tree *h){
    Tree* x = h, *max;
    max->key = 0;
    while(x != nullptr){
        if(x->key > max->key)
            max = x;
        x = x->sibling;
    }
    return max;
}

void Change(Binom::Tree *h, int newval, int oldval){
    Tree* x = Find(h, oldval);
    if (x == nullptr)
        throw std::logic_error("error");
    x->value = newval;
    Tree* p = x->parent;
    int m;
    while(p != nullptr && x->value < p->value){
        m = x->value;
        x->value = p->value;
        p->value = m;
        x = p;
        p = p->parent;
    }
}

Tree* Find(Binom::Tree *h, int val){
    if (h == nullptr)
        return nullptr;
    if (h->value == val)
        return h;
    Tree* rec = Find(h->child, val);
    if(rec != nullptr)
        return rec;
    return Find(h->sibling, val);
}

Tree* Delete(Binom::Tree *h){
    Tree* x = h, *prev = nullptr, *prevmin, *xmin;
    Tree *z, *y;
    while(x != nullptr){
        xmin = GetMin(h);
        prevmin = prev;
        prev = x;
        x = x->sibling;
    }
    if(prevmin != nullptr)
        prevmin->sibling = xmin->sibling;
    else
        h = xmin->sibling;
    z->child = xmin->child;
    prev = nullptr;
    while(z != nullptr){
        y = z->sibling;
        z->sibling = prev;
        prev = z;
        z = y;
    }
    return Union(h, prev);
}

void DecreaseKey(Binom::Tree *x){
    if(x->key < 0)
        throw std::out_of_range("error");
    x->key = x->key - 1;
    Tree* y = x;
    Tree* z = y->parent;
    int temp;
    while(z != nullptr && y->key < z->key){
        temp = y->key;
        y->key = z->key;
        z->key = temp;
        y = z;
        z = y->parent;
    }
}

void DeleteHeap(Binom::Tree *h){
    while(h != nullptr){
       DecreaseKey(h);
       Delete(h);
    }

}