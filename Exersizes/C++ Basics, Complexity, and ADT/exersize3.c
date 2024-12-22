#include <stdio.h>
#include <time.h> // For measuring time

int one(int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum++;

    return sum;
}
/*
The estimated worst-case time complexity of this program is O(n).
This is because of the single loop structure, which iterates n times.

When comparing the analysis with the actual running time, we observe a close alignment. 
As expected, the running time increases linearly with the value of n. 
More specifically, we notice that for every additional zero added to n, 
the execution time increases roughly by a factor of 10. This observation confirms 
the expected linear relationship between n and the program's execution time.
*/

int two(int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum++;

    return sum;
}
/*
The estimated worst-case time complexity of this program is O(n^2).
This is due to the nested loop structure, where the outer loop runs n times, 
and for each iteration of the outer loop, the inner loop also runs n times. 
Thus, the total number of iterations is n * n, which gives O(n^2) time complexity.

When comparing the analysis with the actual running time, we observe a close alignment.
As expected, the running time increases quadratically with the value of n.
For each additional zero added to n, the execution time increases roughly by a factor of 100, 
confirming the expected quadratic relationship between n and the program's execution time.
*/

int three(int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n * n; j++) 
            sum++;

    return sum;
}
/*
The estimated worst-case time complexity of this program is O(n^3).
This is due to the nested loop structure, where the outer loop runs n times, 
and the inner loop runs n * n times for each iteration of the outer loop. 
Thus, the total number of iterations is n * (n * n), which gives O(n^3) time complexity.


When comparing the analysis with the actual running time, we observe a close alignment.
As expected, the running time increases cubically with the value of n.
For each additional zero added to n, the execution time increases roughly by a factor of 1000, 
confirming the expected cubic relationship between n and the program's execution time.
*/

int four(int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) 
            sum++;

    return sum;
}
/*
The estimated worst-case time complexity of this program is O(n^2).
This is due to the nested loop structure, where the outer loop runs n times, 
and the inner loop runs i times for each iteration of the outer loop. 
The number of iterations of the inner loop depends on the value of i, which increases 
with each iteration of the outer loop, leading to a total of (n-1 + n-2 + ... + 1) 
iterations, which is approximately n^2/2. Thus, the overall time complexity is O(n^2).


When comparing the analysis with the actual running time, we observe a close alignment.
As expected, the running time increases quadratically with the value of n.
For each additional zero added to n, the execution time increases roughly by a factor of 100, 
confirming the expected quadratic relationship between n and the program's execution time.
*/

/*
Compiling with the -O optimization flag improves the actual runtime of the program 
by making it more efficient, but it does not change the Big-O time complexity. 
If the time complexity is O(n), it remains O(n), though the program will likely run 
faster due to optimizations.
*/


int main()
{
    int test_values[] = {100, 1000, 10000, 100000, 10000000, 100000000, 1000000000};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]); // Calculates array size 
 
    for (int i = 0; i < num_tests; i++) 
    {
        int n = test_values[i];
        clock_t start = clock(); // Start the timer

        int result = four(n); // Change this to see the time of a specific program fragment 

        clock_t end = clock(); // End the timer
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("N = %d, Result = %d, Time taken = %.6f seconds\n", n, result, time_taken);
    }

    return 0;
}