
#include<iostream> 
using namespace std; 
  
void swap_ref (int& first, int& second) 
{ 
    int temp = first; 
    first = second; 
    second = temp; 
} 

void swap_val (int first, int second) 
{ 
    int temp = first; 
    first = second; 
    second = temp; 
} 
 
int main() 
{ 
    int a = 2, b = 3; 
    cout<<endl;
    swap_val( a, b ); 
    cout << "val" << endl;
    cout << a << " " << b; 

    cout<<endl;
    swap_ref( a, b ); 
    cout << "ref" << endl;
    cout << a << " " << b; 
    cout<<endl;

    return 0; 
} 

