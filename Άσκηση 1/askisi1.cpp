#include <iostream> 
#include <fstream> // To use ifstream 
#include <vector> 
using namespace std; 
int main() 
{ 
vector<int> numbers; 
int i; 
ifstream inputFile("input.txt"); // Input file 
stream object 
10
if (inputFile.good()) // Check if file exists 
and then open it. 
{ 
int current_number = 0; 
while (inputFile >> current_number) // 
reads data from file 
numbers.push_back(current_number); //and 
stores them in a vector 
inputFile.close(); // Close the file. 
// Display the numbers read: 
i=numbers.size(); 
int max_value, min_value = numbers[0], a,b; 
for (int count = 1; count < i; count++)
{ 
if (max_value<numbers[count]) 
{
max_value = numbers[count]; 
 a=count;
 }
else if (min_value>numbers[count])
{
 min_value = 
numbers[count]; 
 b=count;
 }
 } 
numbers[b]=numbers[0];
 numbers[a]=numbers[i-1];
 numbers[0] = min_value; 
 numbers[i - 1] = max_value; 
 cout << "The numbers are: "; 
for (int count = 0; count < i; count++)
{ 
cout << numbers[count] << " "; 
 } 
 cout << endl; 
}else { 
cout << "Error in reading file!"; 
 exit(0); 
 } 
// stores the numbers in txt file using output file stram 
object 
 ofstream outputfile; 
 outputfile.open ("output.txt"); 
 for (int count = 0; count < i; count++)
{ 
outputfile << numbers[count] << " "; 
 } 
outputfile.close(); //close output file 
 
return 0; 
} 
