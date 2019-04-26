//
// Created by Miriam Lipkovich on 2019-04-24.
//

#ifndef STRUCT_ITERATOR_H
#define STRUCT_ITERATOR_H
#include "binomial.h"
#include <iterator>
#include <assert.h>
#include <stack>
class iterator{
protected:
    std::stack <node*> stack_;
public:
    virtual ~iterator() = default;
    virtual bool operator !=(const iterator&) = 0;
    virtual bool operator ==(const iterator&) = 0;
    virtual int operator*() = 0;
    virtual iterator& operator++() = 0;
};

class input_iterator: public iterator{
    void push_all(node* input);
public:
    iterator operator++(int);
    virtual int operator*() const;
    virtual bool operator==(const input_iterator&);
    virtual bool operator!=(const input_iterator&);
};

class output_iterator: public iterator{
    void push_all(node* input);
public:
    virtual int operator*();
    iterator operator++(int);
};

class forward_iterator: public output_iterator, input_iterator{
    forward_iterator() = default;
public:
    forward_iterator& iterator_begin();
    forward_iterator& iterator_end();
};

#endif //STRUCT_ITERATOR_H
