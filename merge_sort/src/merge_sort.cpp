#include "merge_sort.hpp"
#include <sstream> 

int main()
{
    int arr_size = get_int(1);
    int* arr = new int [arr_size];
    for (int i=0; i < arr_size; ++i) { 
        arr[i] = get_int(2);                                     
    } 
    std::cout << "\nGiven array is: ";
    print_array(arr, arr_size);
    merge_sort(arr, 0, arr_size - 1, 1);
    std::cout << "\nSorted array in ascending order is: ";
    print_array(arr, arr_size);
    merge_sort(arr, 0, arr_size - 1, 2);
    std::cout << "\nSorted array in descending order is : ";
    print_array(arr, arr_size);
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


// Merges two sub-arrays of arr[]. 
// First sub-array is arr[l..m] 
// Second sub-array is arr[m+1..r]
// q --> the order that the array will be sorted (descending or ascending)
void merge(int arr[], const int& l, const int& m, const int& r, const int& q) 
{ 
    int i = 0;
    int j = 0;
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    // create temp arrays 
    int L[n1], R[n2]; 
    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; ++i) { 
        L[i] = arr[l + i]; 
    }
    for (j = 0; j < n2; ++j) { 
        R[j] = arr[m + 1+ j]; 
    }
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first sub-array 
    j = 0; // Initial index of second sub-array 
    int k = l; // Initial index of merged sub-array 
    while (i < n1 && j < n2) { 
        if (1 == q) { 
            if (L[i] <= R[j]) { 
                arr[k] = L[i]; 
                i++; 
            } else { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } else if (2 == q) {
            if (L[i] >= R[j]) { 
                arr[k] = L[i];
                i++;
            } else { 
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    } 
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is for right index of the 
   sub-array of arr to be sorted */
void merge_sort(int arr[], const int& l, const int& r, const int& q) 
{ 
    if (l < r) { 
        // Avoids overflow for large l and r 
        int m = l+(r-l)/2; 
        merge_sort(arr, l, m, q); 
        merge_sort(arr, m+1, r, q); 
        merge(arr, l, m, r, q); 
    } 
} 
  
// Function to print an array 
void print_array(int arr[], int& size) 
{ 
    for (int i=0; i < size; ++i) { 
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
} 
