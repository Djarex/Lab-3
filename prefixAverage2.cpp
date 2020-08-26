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
#include <chrono>
#include <unistd.h>

using namespace std;

const int TEST_SIZE = 1000000;

vector<int> prefixAverage2(vector<int> X)
{
    vector<int> A(TEST_SIZE);
    int s = 0;

    for(int i = 0; i < A.size(); i++)
    {
        s = s + X[i];
        A[i] = s / (i + 1);
    }

    return A;
}

int main()
{
    vector<int> X;

    srand (time(NULL));

    for(int i = 0; i < TEST_SIZE; i++)
    {
        //generate random numebrs from 1-999
        X.push_back(rand() % 999 + 1);
    }

    //sort(X.begin (), X.end ());

  cout << "**PREFIX AVERAGE 2 (LINEAR)** with test size of: " << TEST_SIZE << endl << endl << endl;

    cout << "First 4 in Vector List" << endl << endl;
    for (int i = 0; i < 4; i++)
    {
      cout << X[i] << ' ' << endl << endl;
    }

	auto start = chrono::steady_clock::now();

	X = prefixAverage2(X);

	auto end = chrono::steady_clock::now();

    cout << "First 4 Prefix Averages" << endl << endl;
    for (int i = 0; i < 4; i++)
    {
      cout << X[i] << ' ' << endl << endl;
    }

    cout << "Time elapsed: " <<
    		chrono::duration_cast<chrono::microseconds>(end-start).count() << " microseconds" << endl;

return 0;
}
