#include "matrix.h"

int main() {
    Display();
    int size1, size2;
    switch(Menu()){
        case 1:
        {
            std::cout<<"Firs Matrix:\n";
            std::cout<<"Input number of columns:";
            std::cin>>size1;
            std::cout<<"Input number of rows:";
            std::cin>>size2;
            Matrix mat1(size2, size1);
            std::cout<<mat1;
            std::cout<<"Second Matrix:\n";
            std::cout<<"Input number of columns:";
            std::cin>>size1;
            std::cout<<"Input number of rows:";
            std::cin>>size2;
            Matrix mat2(size2, size1);
            std::cout<<mat2;
            Matrix mat3(0,0);
            mat3 = mat1 + mat2;
            std::cout<<"Sum:\n";
            std::cout<<mat3;
            break;

        }
        case 2:
        {
            std::cout<<"Firs Matrix:\n";
            std::cout<<"Input number of columns:";
            std::cin>>size1;
            std::cout<<"Input number of rows:";
            std::cin>>size2;
            Matrix mat1(size2, size1);
            std::cout<<mat1;
            std::cout<<"Second Matrix:\n";
            std::cout<<"Input number of columns:";
            std::cin>>size1;
            std::cout<<"Input number of rows:";
            std::cin>>size2;
            Matrix mat2(size2, size1);
            std::cout<<mat2;
            Matrix mat3(0,0);
            std::cout<<"Multiplication\n";
            mat3 = mat1 * mat2;
            std::cout<<mat3;
            break;
        }
        case 4:
        {
          double n = 0;
          std::cout<<"Input number:";
          std::cin>>n;
          std::cout<<"Input number of columns:";
          std::cin>>size1;
          std::cout<<"Input number of rows:";
          std::cin>>size2;
          Matrix mat1(size2, size1);
          std::cout<<mat1;
          Matrix mat3(0,0);
          std::cout<<"Multiplication\n";
          mat3 = mat1 * n;
          std::cout<<mat3;
          break;
        }
        case 3:{
            std::cout<<"Firs Matrix:\n";
            std::cout<<"Input number of columns:";
            std::cin>>size1;
            std::cout<<"Input number of rows:";
            std::cin>>size2;
            Matrix mat1(size2, size1);
            std::cout<<mat1;
            std::cout<<"Second Matrix:\n";
            std::cout<<"Input number of columns:";
            std::cin>>size1;
            std::cout<<"Input number of rows:";
            std::cin>>size2;
            Matrix mat2(size2, size1);
            std::cout<<mat2;
            Matrix mat3(0,0);
            mat3 = mat1 - mat2;
            std::cout<<"Sub:\n";
            std::cout<<mat3;
            break;
        }
        default:
            break;

    }
    return 0;
}

int Menu(){
    char c = getchar();
    return (c - '0');
}

void Display(){
    std::cout<<"Press 1 to get sum\n";
    std::cout<<"Press 2 to get multiplication\n";
    std::cout<<"Press 3 to get subtraction\n";
    std::cout<<"Press 4 to get the result of multiplication of Matrix and number\n";
}

std::ostream &operator<< (std::ostream& out, const Matrix &b){
    for(int i = 0; i < b.size1; i++){
        for(int j = 0; j < b.size2; j++){
            out<<std::setw(5)<<b.array[i][j];
        }
        std::cout<<"\n";
    }
    return out;
}