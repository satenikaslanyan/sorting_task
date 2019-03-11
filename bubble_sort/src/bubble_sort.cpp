#include "bubble_sort.hpp"
#include <sstream>

int main()
{
     int n = get_int(1);
     int* arr = new int [n];
     for (int i=0; i < n; ++i) { 
         arr[i] = get_int(2);  
     } 
     std::cout << "\nGiven array is: ";
     print_array(arr, n);
     bubble_sort(arr, n, 1);
     std::cout << "\nSorted array in ascending order is: ";
     print_array(arr, n);
     bubble_sort(arr, n, 2);
     std::cout << "\nSorted array in descending order is: ";
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


// A function to implement bubble sort 
void bubble_sort(int arr[], const int& n, const int& k) 
{ 
    for (int i = 0; i < n-1; ++i) {       
        for (int j = 0; j < n-i-1; ++j) {  
            if (1 == k) {
                if (arr[j] >= arr[j+1]) { 
                    swap(arr[j], arr[j+1]); 
                }
            } else if (2 == k) {
                if (arr[j] <= arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
} 

// Function to print an array
void print_array(int arr[], const int& size)
{
    for (int i=0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

