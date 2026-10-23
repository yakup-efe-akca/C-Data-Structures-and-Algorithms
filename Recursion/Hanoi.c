#include <stdio.h>

int count = 0;

void hanoi(int n, char source, char middle, char target) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        count++;
        return;
    }
    hanoi(n - 1, source, target, middle);
    printf("Move disk %d from %c to %c\n", n, source, target);
    count++;
    hanoi(n - 1, middle, source, target);
}

int main(void) {
    int num = 0;
    printf("Enter a number for Hanoi: ");
    scanf("%d", &num);

    hanoi(num, 'A', 'B', 'C');

    printf("\nTotal Move Times: %d\n", count);
}