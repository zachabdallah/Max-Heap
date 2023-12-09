// Max-Heap data structure in C++
// Heap implementation taken from "https://www.programiz.com/dsa/heap-data-structure"
// ^I'm writing the function to test if it's a max heap

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include <string>

class Person{
public:
    Person(){
        this->age = -1;
        this->name = "not set";
    }
    Person(int x, string y){
        this->age = x;
        this->name = y;
    }
    string getName(){
        return this->name;
    }
    int getAge(){
        return this->age;
    }
    Person operator>(Person B){
        Person A;
        if (A.getName() > B.getName()){
            return A;
        }
        else{
            return B;
        }
    }
    Person operator<(Person B){
        Person A;
        if (A.getName() < B.getName()){
            return A;
        }
        else{
            return B;
        }
    }
    int operator==(Person B){
        Person A;
        if (A.getName() == B.getName()){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    void printAttributes(){
        cout << "name: " << name << " age: " << age << endl;
    }
private:
    int age;
    string name;
};
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;
    
    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}
void insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, i);
        }
    }
}
void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);
    
    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}
void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

void isMaxHeap(vector<int> &heap, int x){
    cout << endl;
    //what this function does is it recursively creates a new vector that only holds 3 elements, which I will call a triangle because it holds a subroot node and 2 of it's children if they exist. Then, it will do an arithmetic comparison on that triangle-like tree, and will simply return if the parent node isn't bigger than or equal to both of its children.
    //The integer being passed to the function (which starts at 0) will be used as an iterator for creating new vectors, becuase we will increment it every time our function is recursed and use it to reference elements in the original vector that we'll copy to a new left/right subtree vector.
    cout << "x = " << x  << endl;
    if (x == 0){
        //test on the first triangle tree only once
        if (heap[0] < heap[1] || heap[0] < heap[2]){
            cout << "This is not a max heap. (tested on root)" <<endl;
            return;
        }
    }
    //recursive creation of left triangle tree
    if (x <= heap.size()){
        vector<int> leftTree;
        int i = 2*x+1;
            if (i < heap.size()){
                insert(leftTree, heap[i]);
            }
        int j = 2*i+1;
            if (j < heap.size()){
                insert(leftTree, heap[j]);
                if (heap[j] > heap[i]){
                    cout << "This is not a max heap. (tested on left triangle)" << endl;
                    return;
                }
            }
            if (j+1 < heap.size()){
                insert(leftTree, heap[j+1]);
                if (heap[j+1] > heap[i]){
                    cout << "This is not a max heap. (tested on left triangle)" << endl;
                    return;
                }
            }
        cout << "left subtree triangle: " << endl;
        printArray(leftTree);
    }
    //recursive creation of right triangle tree
    if (x <= heap.size()){
        vector<int> rightTree;
        int i = 2*x+2;
        if (i < heap.size()){
            insert(rightTree, heap[i]);
        }
        int j = 2*i+1;
        if (j < heap.size()){
            insert(rightTree, heap[j]);
            if (heap[j] > heap[i]){
                cout << "This is not a max heap. (tested on right triangle)" << endl;
                return;
            }
        }
        if (j+1 < heap.size()){
            insert(rightTree, heap[j+1]);
            if (heap[j+1] > heap[i]){
                cout << "This is not a max heap. (tested on right triangle)" << endl;
                return;
            }
        }
        cout << "right subtree triangle: " << endl;
        printArray(rightTree);
    }
    ++x;
    cout << endl;
    if (x < log2(heap.size())-1){
        isMaxHeap(heap, x);
    }
    if (x == int(log2(heap.size()))-1){
        cout << "yes, this is a max heap." << endl << endl;
    }
}

int main()
{
    vector<int> heapTree;
    
    insert(heapTree, 13);
    insert(heapTree, 3123123);
    insert(heapTree, 950);
    insert(heapTree, 5);
    insert(heapTree, 222);
    insert(heapTree, 4);
    insert(heapTree, 3);
    insert(heapTree, 0123);
    insert(heapTree, 99);
    
    cout << "Max-Heap array: ";
    printArray(heapTree);
    
    isMaxHeap(heapTree, 0);
    
    Person zach(22, "Zach");
    Person daBaby(1, "daBaby");
    Person figgly(23, "Figgly");
    Person shmiggly(63, "Shmiggly");
    Person ziggly(12, "Ziggle");
    Person thomas(422, "Thomas");
    
    
}
