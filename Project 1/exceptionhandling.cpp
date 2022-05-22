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
    try
    {
        ProcessRecors(std::numeric_limits<int>::max());
    }
    catch(std::runtime_error &ex)
    {
        std::cout << ex.what() << '\n';
    }
    
    
    return 0; 
}