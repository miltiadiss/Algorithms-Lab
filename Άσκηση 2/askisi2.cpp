#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> MergeSortedVectors(vector<int>& v1, 
vector<int>& v2)
{
vector<int> v3;
int i, j, n, m;
i = j = 0;
n = v1.size();
m = v2.size();
while (i < n && j < m)
 {
if (v1[i] <= v2[j])
{
v3.push_back(v1[i]);
++i;
}
else
{
v3.push_back(v2[j]);
++j;
}
}
while (i < n) {
v3.push_back(v1[i]);
++i;
}
while (j < m) {
v3.push_back(v2[j]);
++j;
}
return v3;
}
int binarySearch(vector<int> &arr, int low, int high, int 
toSearch)
 {
 if (high >= low) {
 int mid = (high + low) / 2;
 if (arr[mid] == toSearch) return 1;
 else if (arr[mid] > toSearch) return 
binarySearch(arr, low, mid - 1, toSearch);
 else return binarySearch(arr, mid + 1, high, 
toSearch);
 }
 return 0;
 }
int main()
{
vector<int> array_1, array_2;
vector<int> mergedarray;
int current_number_1, current_number_2 = 0;
int m, n, temp;
 ifstream input_file_1("Array1.txt");
 ifstream input_file_2("Array2.txt");
 if (input_file_1.good())
 {
 while (input_file_1 >> current_number_1) 
array_1.push_back(current_number_1);
 input_file_1.close();
 // Display the numbers read:
 cout << "The numbers of the 1st array are: ";
 for (int count = 0; count < array_1.size(); 
count++){
 cout << array_1[count] << " ";
 }
 cout << endl;
 }else {
 cout << "Error in reading file!";
 exit(0);
 }
 if (input_file_2.good())
 {
 while (input_file_2 >> current_number_2) 
array_2.push_back(current_number_2);
 input_file_2.close();
 for(n = 0; n < array_2.size(); n++)
 {
 for(m = n + 1; m < array_2.size(); m++)
 {
 if(array_2[n] > array_2[m])
 {
 temp = array_2[n];
 array_2[n] = array_2[m];
 array_2[m] = temp;
 }
 }
 }
 // Display the numbers read:
 cout << "\nThe numbers of the 2nd array are: ";
 for (int count = 0; count < array_2.size(); 
count++) cout << array_2[count]<< " ";
 cout << endl;
 }else {
 cout << "Error in reading file!";
 exit(0);
 }
 mergedarray = MergeSortedVectors(array_1, array_2);
 // Display the numbers read:
 cout << "\nThe numbers of the merged array are: ";
 for (int count = 0; count < mergedarray.size(); 
count++) cout << mergedarray[count]<< " ";
 cout << endl;
 int num;
 cout << "\n\nEnter the integer of the merged array 
you want to search for : ";
 cin >> num;
 int low = 0;
 int high = array_1.size() + array_2.size() - 1;
 int result = binarySearch(mergedarray, low, high, 
num);
 if (result == 1) cout << "\nElement is found";
 else cout << "\nElement is not found";
}
