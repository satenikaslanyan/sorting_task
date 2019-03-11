#include "selection_sort.hpp"
#include <sstream> 
#include <assert.h>

int main()
{
    int n = get_int(1);
    int* arr = new int [n];
    assert(arr);
    for (int i=0; i < n; ++i) { 
        arr[i] = get_int(2);  
    } 
    std::cout << "\nGiven array is: ";
    printArray(arr, n);
    selectionSort(arr, n, 1);
    std::cout << "\nSorted array in ascending order is: ";
    printArray(arr, n);
    selectionSort(arr, n, 2);
    std::cout << "\nSorted array in descending order is: ";
    printArray(arr, n);
    std::cout << std::endl;
    delete [] arr;
}

//This function checks the input is number or not
void is_number(std::string& s, bool& fl, int i)
{    
     for (; i < s.size(); ++i) { 
         if(s[i] < '0' || s[i] > '9') {
             std::cout << "Error, invalid input" << std::endl;
             fl = true;
             break;
         }
     }
}

//This function is for checking input
void check_input(std::string& s, bool& fl, const int& a)
{   
    if (s.size() == 0) {
        std::cout << "Error, invalid input" << std::endl;
        fl = true;
    } else {
        if (1 == a) {
            if (s == "0") {
                std::cout << "Error, invalid input" << std::endl;
                fl = true;
            } else {
                is_number(s, fl, 0);
            }  
        } else if (2 == a) {
            if (s[0] == '-' || s[0] < '0' || s[0] > '9') {
                if (s[0] == '-' && s.size() == 1) {
                    std::cout << "Error, invalid input" << std::endl;
                    fl = true;
                } else {
                    is_number(s, fl, 1);
                }
            }
        }
    }
}

//This function is for input
int get_int(const int& a) 
{
    bool fl = false;
    int result = 0;
    std::string s("");
    do {
        if (1 == a) {
            std::cout << "\nWhat size of array do you want? ";
        } else if (2 == a) {
            std::cout << "Input element ";
        } 
        getline(std::cin, s);
        fl = false;
        check_input(s, fl, a);
    } while(fl);
    std::stringstream str_int(s);
    str_int >> result;
    return result;
}


//Function that swaps two elements 
void swap(int& a, int& b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
} 

// Function that implements selection sort
// k --> the order that the array will be sorted (ascending or descending)  
void selectionSort(int arr[], const int& n, const int& k) 
{ 
    int min_max; 
    // One by one move boundary of unsorted sub-array 
    for (int i = 0; i < n-1; ++i) { 
        min_max = i; 
        for (int j = i+1; j < n; ++j) {
            if (1 == k) {
                if (arr[j] <= arr[min_max]) { 
                     min_max = j;
                }
            } else if (2 == k) {
                if (arr[j] >= arr[min_max]) {
                     min_max = j;
                }
            }
         }
        swap(arr[min_max], arr[i]); 
    } 
} 
  
// Function to print an array 
void printArray(int arr[], const int& size) 
{ 
    for (int i=0; i < size; ++i) { 
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} 
