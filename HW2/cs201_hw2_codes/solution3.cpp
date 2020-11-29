

int main()
{
    double duration;
    clock_t startTime = clock();
    int n = 10;
    int const k = 1000;
    int inputArray[n];
    int outputArray[k];
    int inputArray2[n];

    for(int i = 0; i < n; i++)
    {
        inputArray[i] = rand();
        cout << inputArray[i] << endl;

    }

    solution1(inputArray, n, k, outputArray);
    //solution2(inputArray, n, k, outputArray);
    //solution3(inputArray, n, k, outputArray);

    duration = 1000 * double( clock() - startTime);
    cout << "Execution took " << duration << " milliseconds." << endl;

    return 0;
}
