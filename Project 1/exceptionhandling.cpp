#include <iostream>

void ProcessRecors(int count)
{
    int *pArray = (int*)malloc(count * sizeof(int));
    if(pArray == nullptr)    // return not good user doesnt know what happend
    {
        throw std::runtime_error("Failed to allocate memory");
    }
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