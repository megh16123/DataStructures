// Kuldeep Choudhary (3919)

#include<iostream>
using namespace std;
template <typename T>
int binarySearch(T arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int myarr[10];
  int num;
  int output;
  int size; 
  cout << "Enter the size of the array -:" << endl;
  cin>>size;
  cout<<"Enter the elements of the array -: \n";
  for (int i = 0; i < size; i++) {
    cin >> myarr[i];
  }
  cout << "Please enter an element to search" << endl;
  cin >> num;

  output = binarySearch(myarr, 0, size-1, num);

  if (output == -1) {
    cout << "No Match Found" << endl;
  } else {
    cout << "Match found at index : " << output << endl;
  }

  return 0;
}
