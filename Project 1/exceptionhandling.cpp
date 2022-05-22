#include <iostream>

void ProcessRecors(int count)
{
    int *pArray = (int*)malloc(count * sizeof(int));
    if(pArray == nullptr) return;
    for(int i = 0; i < count; ++i)
    {
        pArray[i] = i; 
    }
    free(pArray);
}

int main()
{
    ProcessRecors(std::numeric_limits<int>::max());
    return 0; 
}