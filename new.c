#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

void tampilan() {
    if (top == -1) {
        printf("Stack tidak ada\n");
        return;
    }
    printf("Isi stack saat ini adalah: \n");
    for (int i = top; i >= 0; i--) {
        printf("%c \n", stack[i]);
    }
}

int new() {
    int pilihan;
    char data;

    while (1) {
        printf("\nMENU STACK using ARRAY:\n");
        printf("1. Mengisi Stack (PUSH)\n");
        printf("2. Mengambil isi Stack (POP)\n");
        printf("3. Menampilkan isi Stack -> LIFO\n");
        printf("4. Keluar\n");
        printf("\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan data Anda: ");
                scanf(" %c", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != '\0') {
                    printf("Item yang Anda ambil adalah %c \n", data);
                }
                break;
            case 3:
                tampilan();
                break;
            case 4:
                exit(0);
            default:
                printf("Pilihan salah\n");
        }
    }
}