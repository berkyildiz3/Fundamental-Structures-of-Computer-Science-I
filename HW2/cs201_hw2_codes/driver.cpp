

int main()
{
    double duration;
    clock_t startTime = clock();
    int n = 10;
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
