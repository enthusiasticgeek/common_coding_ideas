/*
 * A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. We can capture external variables from enclosing scope by three ways :
      Capture by reference
      Capture by value
      Capture by both (mixed capture)

Syntax used for capturing variables :
      [&] : capture all external variable by reference
      [=] : capture all external variable by value
      [a, &b] : capture a by value and b by reference
*/
//https://www.geeksforgeeks.org/lambda-expression-in-c/

// C++ program to demonstrate lambda expression in C++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {3, 1, 7, 9};
    vector<int> v2 = {10, 2, 7, 16, 9};

    //  access v1 and v2 by reference
      /*
      By capturing v1 and v2 by reference, the lambda function pushinto can modify these vectors directly. 
      Any changes made to v1 and v2 inside the lambda function will affect the original vectors defined in the enclosing scope.
            */
    auto pushinto = [&] (int m)
    {
        v1.push_back(m);
        v2.push_back(m);
    };

    // it pushes 20 in both v1 and v2
    pushinto(20);

    // access v1 by copy
    [v1]()
    {
        for (auto p = v1.begin(); p != v1.end(); p++)
        {
            cout << *p << " ";
        }
    };

    int N = 5;

    // below snippet find first number greater than N
    // [N]  denotes,   can access only N by value
    vector<int>:: iterator p = find_if(v1.begin(), v1.end(), [N](int i) -> bool
    {
        return i > N;
    });

    cout << "First number greater than 5 is : " << *p << endl;

    // function to count numbers greater than or equal to N
    // [=] denotes,   can access all variable
    int count_N = count_if(v1.begin(), v1.end(), [=](int a)
    {
        return (a >= N);
    });

    cout << "The number of elements greater than or equal to 5 is : "
         << count_N << endl;
}

