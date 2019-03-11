#include "quick_sort.hpp"
#include <sstream>

int main()
{
    int n = get_int(1);
    int* arr = new int [n];
    for (int i=0; i < n; ++i) { 
        arr[i] = get_int(2);       
    } 
    std::cout << "\nGiven array is : ";
    print_array(arr, n);
    quick_sort(arr, 0, n-1, 1);
    std::cout << "\nSorted array in ascending order: ";
    print_array(arr, n);
    quick_sort(arr, 0, n-1, 2);
    std::cout << "\nSorted array in descending order: ";
    print_array(arr, n);
    std::cout << std::endl;
    delete [] arr;
}

//This function is for checking input
void check_input(std::string& s, bool& fl)
{
    if (s.size() == 0) {
        std::cout << "Error, invalid input" << std::endl;
        fl = true;
    } else {
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] < '0' || s[i] > '9') {
                std::cout << "Error, invalid input" << std::endl;
                fl = true;
                break;
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
        check_input(s, fl);
    } while(fl);
    std::stringstream str_int(s);
    str_int >> result;
    return result;
}


// Function to swap two elements 
void swap(int& a, int& b) 
{ 
    int t = a; 
    a = b; 
    b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
   array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
// k --> the order that the array will be sorted (descending or ascending)
int partition (int arr[], const int& low, const int& high, const int& k) 
{ 
    int pivot = arr[high];  
    int i = (low - 1);  // Index of smaller element 
    for (int j = low; j <= high - 1; ++j) { 
        if (1 == k) {
            if (arr[j] <= pivot) { 
                i++;    
                swap(arr[i], arr[j]); 
            } 
        } else if (2 == k) {
            if (arr[j] >= pivot) { 
                i++;    
                swap(arr[i], arr[j]); 
            }
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements quick_sort 
   arr[] --> Array to be sorted, 
   low  --> Starting index, 
   high  --> Ending index */
void quick_sort(int arr[], const int& low, const int& high, const int& k) 
{ 
    if (low < high) { 
        // Avoids overflow for large low and high 
        int p = partition(arr, low, high, k); 
        // Separately sort elements before 
        // partition and after partition 
        quick_sort(arr, low, p - 1, k); 
        quick_sort(arr, p + 1, high, k); 
    } 
} 
  
// Function to print an array 
void print_array(int arr[], const int& size) 
{ 
    for (int i=0; i < size; ++i) { 
        std::cout <<  arr[i] << " ";
    } 
    std::cout << std::endl; 
} 
