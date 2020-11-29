#include <math.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;


static void swap( int& n1, int& n2 ) {

    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void solution1( int input[], const int n, const int k, int output[] ) {

    int maxIndex, maxValue;
    for ( int i = 0; i < k; i++ ) {
        maxIndex = i;
        maxValue = input[i];
        for ( int j = i+1; j < n; j++ ) {
            if ( input[j] >= maxValue ) {
                maxIndex = j;
                maxValue = input[ j ];
            }
        }
        swap( input[i], input[maxIndex] );
        output[i] = input[i];
    }
}




int main()
{
    double duration;
    clock_t startTime = clock();
    int n = 100000;
    int k = 1000;
    int inputArray[n];
    int outputArray[k];

    for(int i = 0; i < n; i++)
    {
        inputArray[i] = rand();

    }

    solution1(inputArray, n, k, outputArray);
    //solution2(inputArray, n, k, outputArray);
    //solution3(inputArray, n, k, outputArray);

    duration = 1000 * double( clock() - startTime);
    cout << "Execution took " << duration << " milliseconds." << endl;

    return 0;
}





