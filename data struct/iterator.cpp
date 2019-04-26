//
// Created by Miriam Lipkovich on 2019-04-24.
//
#include "iterator.h"
#include "binomial.h"
void input_iterator::push_all(node *input) {
    for(; input != nullptr; this->stack_.push(input), input = input->child);
}

iterator input_iterator::operator++(int n) {
    node* temp = this->stack_.top();
    this->stack_.pop();
    push_all(temp->sibling);
}

int input_iterator::operator*() const {
    return this->stack_.top()->data;
}

bool input_iterator::operator!=(const input_iterator& iterator_to_compare){
    return this->stack_.top()->data != iterator_to_compare.stack_.top()->data;
}

bool input_iterator::operator==(const input_iterator& iterator_to_compare){
    return this->stack_.top()->data == iterator_to_compare.stack_.top()->data;
}

void output_iterator::push_all(node *input) {
    for(; input != nullptr; this->stack_.push(input), input = input->sibling);
}

iterator output_iterator::operator++(int n) {
    node* temp = this->stack_.top();
    this->stack_.pop();
    push_all(temp->child);
}

int output_iterator::operator*() {
    return this->stack_.top()->data;
}

forward_iterator& forward_iterator::iterator_begin() {

}