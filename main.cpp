#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std ;


void buildArray(int myArray[], int arraySize)
{
    srand(time(NULL)) ;
    for(int i = 0; i < arraySize; i++)
    {
        myArray[i] = rand() % 50 + 1 ;
    }
}

void printArray(int myArray[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << setw(6) << myArray[i] ;
    }
}

void incSwapElements(int *num1, int *num2)
{
    if(*num1 > *num2)
    {
        int temp = *num1 ;
        *num1 = *num2 ;
        *num2 = temp ;
    }
}

void decSwapElements(int *num1, int *num2)
{
    if(*num1 < *num2)
    {
        int temp = *num1 ;
        *num1 = *num2 ;
        *num2 = temp ;
    }
}

void incExchangeElements(int myArray[], int arraySize)
{
    for(int i = 0; i < arraySize - 1; i++)
    {
        for(int j = i + 1; j < arraySize; j++)
        {
            if(myArray[i] > myArray[j])
            {
                incSwapElements(&myArray[i], &myArray[j]) ;
            }
        }
    }
}

void decExchangeElements(int myArray[], int arraySize)
{
    for(int i = 0; i < arraySize - 1; i++)
    {
        for(int j = i + 1; j < arraySize; j++)
        {
            if(myArray[i] < myArray[j])
            {
                decSwapElements(&myArray[i], &myArray[j]) ;
            }
        }
    }
}

int main()
{
    int arraySize = 0 ;
    string sortAnswer ;
    cout << "how many elements do you want in this array?" << endl ;
    cin >> arraySize ;
    int myArray[arraySize] ;
    buildArray(myArray, arraySize);
    cout << "Here is your array so far: " << endl ;
    printArray(myArray, arraySize);
    cout << endl << "Now how do you want to sort the array? ['inc' for increasing or 'dec' for decreasing]" << endl ;
    cin >> sortAnswer ; 
    cout << "Ok! Here is your array: " << endl ;
    
    if(sortAnswer == "inc")
    {
        incExchangeElements(myArray, arraySize);
        printArray(myArray, arraySize);
    }
    
    if(sortAnswer == "dec")
    {
        decExchangeElements(myArray, arraySize);
        printArray(myArray, arraySize);
    }
        
    
    return 0 ;
}
