#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Kích thước tối đa của stack

// Khai báo cấu trúc một tác vụ cần thực hiện
typedef struct {
    int n;          // Số lượng đĩa
    char from;      // Cọc nguồn
    char to;        // Cọc đích
    char aux;       // Cọc trung gian
} Task;

// Khai báo cấu trúc Stack
typedef struct {
    Task data[MAX];
    int top;
} Stack;

// Khởi tạo stack rỗng
void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1; // Kiểm tra stack rỗng
}

void push(Stack *s, Task task) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = task; // Đẩy phần tử vào stack
    }
}

Task pop(Stack *s) {
    return s->data[(s->top)--]; // Lấy phần tử khỏi stack
}

void hanoiTowerNonRecursive(int n, char source, char target, char temp) {
    Stack s;
    initStack(&s);

    // Đẩy bài toán ban đầu vào stack
    Task initialTask = {n, source, target, temp};
    push(&s, initialTask);

    while (s.top != -1) {
        Task current = pop(&s);

        // Trường hợp cơ sở: chỉ cần chuyển 1 đĩa
        if (current.n == 1) {
            printf("Move disk from %c to %c\n", current.from, current.to);
        } else {
            // Theo nguyên lý LIFO (vào sau ra trước), ta đẩy các bước theo thứ tự ngược lại:
            
            // Bước 3: Chuyển (n-1) đĩa từ cọc trung gian sang cọc đích
            Task task3 = {current.n - 1, current.aux, current.to, current.from};
            push(&s, task3);

            // Bước 2: Chuyển đĩa thứ n từ cọc nguồn sang cọc đích
            Task task2 = {1, current.from, current.to, current.aux};
            push(&s, task2);

            // Bước 1: Chuyển (n-1) đĩa từ cọc nguồn sang cọc trung gian
            Task task1 = {current.n - 1, current.from, current.aux, current.to};
            push(&s, task1);
        }
    }
}

int main() {
    int n;
    printf("Hanoi Tower Problem with A as source, C as target, and B as temporary rod, solving using stack.\n");
    printf("Enter the number of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of disks!\n");
        return 1;
    }

    hanoiTowerNonRecursive(n, 'A', 'C', 'B');

    return 0;
}