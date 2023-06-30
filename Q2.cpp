#include <iostream>
#include <string>
using namespace std;

template<typename T>
T Biggest(T *array, int size)
{
    T max = array[0];
    for (int i = 0; i < size; ++i)
        if (max < array[i])
            max = array[i];
    return max;
}
template<typename T>
void Print(const T *array, int size)
{
    for (int i = 0; i < size; ++i)
        cout << array[i];
    cout << endl;
}

class Product
{
private:
    int m_id;
    string m_Name;

public:
    Product() = default;
    Product(int id, string name): m_id(id), m_Name(name) {}
    bool operator<(const Product& other) const{return m_Name < other.m_Name;}
    friend ostream& operator<<(ostream &out,const Product& product);
};

ostream& operator<<(ostream &out,const Product& product)
{
    out << "(" << product.m_Name << "," << product.m_id << ")" << endl;
    return out;
}

int main()
{
    const int size = 3;
    double *ArrayDouble = new double[size];
    Product *ArrayProduct = new Product[size];
    Product *pa = new Product(12345, "Milk");
    Product *pb = new Product(45643, "Fruit");
    Product *pc = new Product(45878, "Vegetable");
    ArrayProduct[0] = *pa;
    ArrayProduct[1] = *pb;
    ArrayProduct[2] = *pc;
    for (int i = 0; i < size; i++)
        ArrayDouble[i] = i * 0.8;
    double max = Biggest(ArrayDouble, size);
    Print(ArrayDouble, size);
    Product Pmax = Biggest(ArrayProduct, size);
    Print(ArrayProduct, size);
    delete[] ArrayDouble;
    delete[] ArrayProduct;
}