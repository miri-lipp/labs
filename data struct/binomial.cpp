#include "binomial.h"
#include "iterator.h"

node* root;

node* MakeHeap(){
    node* h = nullptr;
    return h;
}

void Link(node* h1, node* h2){
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree = h2->degree + 1;
}

node* Merge(node* h1, node* h2){
    if(h1 == nullptr)
        return h2;
    if(h2 == nullptr)
        return h1;
    node* h3 = MakeHeap();
    if(h1->degree <= h2->degree)
        h3 = h1;
    else
        h3 = h2;
    while(h1 != nullptr && h2 != nullptr){
        if(h1->degree < h2->degree)
            h1 = h1->sibling;
        else if(h1->degree == h2->degree){
            node* s = h1->sibling;
            h1->sibling = h2;
            h1 = s;
        }
        else if(h1->degree > h2->degree){
            node* s = h2->sibling;
            h2->sibling = h1;
            h2 = s;
        }
    }
    return h3;
}

node* Union(node* h1, node* h2){
    node* h = MakeHeap();
    h = Merge(h1, h2);
    if(h == nullptr)
        return h;
    node* prev, *next, *cur;
    prev = nullptr;
    cur = h;
    next = cur->sibling;
    while(next != nullptr){
        if((cur->degree != next->degree) || (next->sibling != nullptr && next->sibling->degree == cur->degree)){
            prev = cur;
            cur = next;
        }
        else if(cur->degree <= next->degree){
            cur->sibling = next->sibling;
            Link(next, cur);
            if(prev == nullptr)
                h = next;
            else
                prev->sibling = next;
            Link(cur, next);
            cur = next;
        }
        next = cur->sibling;
    }
    return h;
}

node* Insert(node* h, node* x){
    node* h1 = MakeHeap();
    x->parent = nullptr;
    x->child = nullptr;
    x->sibling = nullptr;
    x->degree = 0;
    h1 = x;
    h = Union(h, h1);
    return h;
}

node* CreateNode(int n){
    node* new_node = new node;
    new_node->degree = 0;
    new_node->parent = nullptr;
    new_node->child = nullptr;
    new_node->sibling = nullptr;
    new_node->data = n;
    return new_node;
}

int Revert(node* h){
    if(h->sibling != nullptr){
        Revert(h->sibling);
        h->sibling->sibling = h;
    }
    else
        root = h;
}

node* ExtractMinimum(node* h){
    node* H;
    if(h == nullptr)
        return nullptr;
    root = nullptr;
    node* min_prev = nullptr;
    node* _min = h;
    int min = h->data;
    node* cur = h;
    while(cur->sibling != nullptr){
        if(cur->sibling->data < min){
            min = cur->sibling->data;
            min_prev = cur;
            _min = cur->sibling;
        }
        cur = cur->sibling;
    }
    if(min_prev == nullptr && _min->sibling == nullptr)
        h = nullptr;
    else if(min_prev == nullptr)
        h = _min->sibling;
    else if(min_prev->sibling == nullptr)
        min_prev = nullptr;
    else
        min_prev->sibling = _min->sibling;
    if(_min->child != nullptr){
        Revert(_min->child);
        _min->child->sibling = nullptr;
    }
    H = Union(h, root);
    return _min;
}

node* Search(node* h, int n){
    if(h == nullptr)
        return nullptr;
    node* x = h;
    node* p = nullptr;
    if(x->data == n) {
        p = x;
        return p;
    }
    if(x->child != nullptr && p == nullptr)
        p = Search(h->child, n);
    if(x->sibling != nullptr && p == nullptr)
        p = Search(h->sibling, n);
    return p;
}

void DecreaseKey(node* h, int new_val, int old_val){
    node* res = Search(h, old_val);
    if(res == nullptr)
        return;
    if(new_val > res->data)
        return;
    res->data = new_val;
    node* parent = res->parent;
    while(parent != nullptr && res->data < parent->data){
        const int temp = res->data;
        res->data = parent->data;
        parent->data = temp;
        res = parent;
        parent = parent->parent;
    }
}

int Delete(node* h, int x){
    node* c;
    if(h == nullptr)
        return 0;
    DecreaseKey(h, INT_MIN, x);
    c = ExtractMinimum(h);
}

void PrintNode(node* h){
    while(h){
        std::cout<<h->data<<" ";
        PrintNode(h->child);
        h = h->sibling;
    }
}

//void PrintHeap(node* h){
//    forward_iterator it;
//
//}
