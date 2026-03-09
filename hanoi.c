#include <stdio.h>
#include<math.h>

void tower_hanoi(int n, char src, char dest, char temp)
{
    if (n == 1)
    {
        printf("\nMove disk %d from peg %c to peg %c", n, src, dest);
        return;
    }
    tower_hanoi(n - 1, src, temp, dest);
    printf("\nMove disk %d from peg %c to peg %c", n, src, dest);  
    tower_hanoi(n - 1, temp, dest, src);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower_hanoi(n, 'A', 'B', 'C');
    int total_moves = pow(2, n) - 1;
    printf("\nTotal number of moves = %d\n", total_moves);
    return 0;
}
