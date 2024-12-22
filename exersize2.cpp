#include <cmath>

int myMethod(int N)
{
    int x = 0;
    int y = 0;
    for(int i = 0; i <N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N * sqrt(N); k++)
                x++;
    for(int i = 0; i < N * N; i++)
        y++;

    return x + y;
}

/*
The estimated worst-case time complexity of this program is O(N^3.5).
This is because of the first nested loop structure, which iterates over
three variables: i, j and k. The outer two loops iterate N times each,
while the innermost loop iterates N * N sqared times. Therefore, the overall
complexity for the first set of loops is O(N^2 * N * N squared) = O(N^3.5).
The second loop runs N^2 times, but its contribution is negligable compared to
the dominant term O(N^3.5).
*/