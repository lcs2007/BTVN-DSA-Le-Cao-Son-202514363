// Recursive Hanoi Tower implementation in C
#include <stdio.h>

void hanoiTower(int n, char source, char target, char temp) {
    if (n == 1) {
        printf("Move disk from %c to %c\n", source, target);
        return;
    }
    hanoiTower(n - 1, source, temp, target);
    printf("Move disk from %c to %c\n", source, target);
    hanoiTower(n - 1, temp, target, source);
}

int main() {
    int n; 
    printf("Hanoi Tower Problem with A as source, C as target, and B as temporary rod, solving using recursion.\n");
    printf("Enter the number of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of disks!\n");
        return 1;
    }
    hanoiTower(n, 'A', 'C', 'B'); 
    return 0;
}
