#include "binomial.h"
int main() {
    int l, m;
    node *k, *p;
    k = MakeHeap();
    char ch;
    while (1) {
        std::cout << "1)Insert Element in the heap" << std::endl;
        std::cout << "2)Extract Minimum key node" << std::endl;
        std::cout << "3)Decrease key of a node" << std::endl;
        std::cout << "4)Delete a node" << std::endl;
//        std::cout << "5)Display Heap" << std::endl;
        std::cout << "6)Exit" << std::endl;
        std::cout << "Enter Your Choice: ";
        std::cin >> l;
        switch(l)
        {
            case 1:
                std::cout<<"Enter the element to be inserted: ";
                std::cin>>m;
                p = CreateNode(m);

                k = Insert(k, p);
                break;
            case 2:
                p = ExtractMinimum(k);
                if (p != nullptr)
                    std::cout<<"The node with minimum key: "<<p->data<<std::endl;
                else
                    std::cout<<"Heap is empty"<<std::endl;
                break;
            case 3:
                std::cout<<"Enter the key to be decreased: ";
                std::cin>>m;
                std::cout<<"Enter new key value: ";
                std::cin>>l;
                DecreaseKey(k, l, m);
                break;
            case 4:
                std::cout<<"Enter the key to be deleted: ";
                std::cin>>m;
                Delete(k, m);
                break;
//            case 5:
//                std::cout<<"The Heap is: "<<std::endl;
//                PrintHeap(k);
//                break;
            case 6:
                return 0;
            default:
                std::cout<<"Wrong Choice\n";
        }
    }
        return 0;
}