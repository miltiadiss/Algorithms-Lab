#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;
void heapify_down(vector <int> &v, int i)
{
 int left;
 int right;
 int j;
 if(2*i>v.size() - 1)
 {
 return;
 }
 else if(2*i<v.size() - 1)
 {
 left=2*i;
 right=2*i+1;
 if(v[left]<v[right])
 {
 j=left;
 }
 else
 {
 j=right;
 }
 }
 else if(2*i==v.size() - 1)
 {
 j=2*i;
 }
 if(v[j]<v[i])
 {
 swap(v[j],v[i]);
 heapify_down(v,j);
 }
}
int main()
{
 vector <int> heap;
 int i;
 ifstream inputFile("Heap.txt"); // Input file 
stream object
 if (inputFile.good()) // Check if file exists and 
then open it.
 {
 heap.insert(heap.begin(), 0);
 int current_number = 0;
 while (inputFile >> current_number) //Reads 
data from file
 heap.push_back(current_number); //Stores them in 
a vector
 inputFile.close(); //Close the file.
 //Display the numbers read
 i=heap.size();
 cout << "The numbers are: ";
 for (int count = 0; count < i; count++){
 cout << heap[count] << " ";
 }
 cout << endl;
 }else {
 cout << "Error in reading file!";
 exit(0);
 }
 // Finds the minimum element of the heap and prints 
it
 cout << "the minimum element is: " << 
*min_element(heap.begin()+1, heap.end());
 cout<<endl;
 //Move the last element into first place and first 
element into last place
 iter_swap(heap.begin()+1, heap.end()-1);
 for (int j = 1; j < heap.size(); j++)
 {
 cout << heap[j] << " ";
 }
 cout<<endl;
 //Erases the last element from the heap
 heap.pop_back();
 for (int j = 1; j < heap.size(); j++)
 {
 cout << heap[j] << " ";
 }
 cout<<endl;
 vector <int> h=heap;
 int toSearch = heap[1];
 heapify_down(h, 1);
 cout<<"Min Heap\n";
 for (i = 1; i <= h.size()-1; i++)
 {
 cout<<h[i]<<endl;
 }
 for (i = 1; i <= h.size()-1; i++)
 {
 if (h[i] == toSearch)
 {
 cout << "Element " << toSearch << " is found 
in position : " << i << endl;
 }
 }
 return 0;
}
