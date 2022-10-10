#include "iostream"

int main()
{
    // 2D Array on stack
    int data2DStack[2][3] = {
        1,2,3,
        4,5,6
    };

    // Allocating on heap 

    int *p1 = new int[3];   // First row
    int *p2 = new int[3];   // Second row

    int **pData = new int *[2]; // Pointer to pointers
    pData[0] = p1;
    pData[1] = p2;

    pData[0][1] = 2; // First row second column
    
    // Dealloc
    delete []p1;
    delete []p2;
    delete []pData;
}