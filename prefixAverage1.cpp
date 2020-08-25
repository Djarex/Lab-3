/******************************************************************************
 * AUTHOR		: Jared Blueweiss & Lina Kang
 * STUDENT ID	: 
 * LAB 			: 3
 * CLASS		: CS1D
 * SECTION		: MW: 2:30PM
 * DUE DATE		: 8/26/2020 
 ****************************************************************************/

/******************************************************************************
 * Lab 3
 * ----------------------------------------------------------------------------
 * Create prefix1 algorithm and compare it to prefix2 algorithm
 * ----------------------------------------------------------------------------
 * INPUT:random generated numbers into a vecotor of varying sizes
 *
 * OUTPUT: prefix average of the vector list
 *
 *****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;



vector<int> prefixAverage1(vector<int> X)
{
    vector<int> A(10);
    int a;


    for(int i = 0; i < A.size(); i++)
    {
        a = 0;
        for(int j = 0; j < i; j++)
        {
            a = a + X[j];
        }
        A[i] = (a/(i + 1));
    }


return A;
}

int main()
{
    const int TEST_SIZE = 10;

    vector<int> X;
    srand (time(NULL));

    for(int i = 0; i < TEST_SIZE; i++)
    {
        //generate random numebrs from 1-999 
        X.push_back(rand() % 999 + 1);
    }
    
     sort(X.begin (), X.end ());

    /*
    cout << "BEFORE" << endl << endl;
    for (const auto & i:X)
    {
      cout << i << ' ' << endl << endl;
    }
    */

    X = prefixAverage1(X);

    /*
    cout << "AFTER" << endl << endl;
    for (const auto & i:X)
    {
      cout << i << ' ' << endl << endl;
    }
    */

system("PAUSE");
return 0;    
}