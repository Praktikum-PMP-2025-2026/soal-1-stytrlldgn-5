/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*   Modul               : 4 - Dynamic Structures
*   Hari dan Tanggal    : selasa, 5 Mei 2026
*   Nama (NIM)          : I Ketut Satya Adnyana (13224076)
*   Nama File           : soal1.c
*   Deskripsi           : Periksa validitas string kurung dengan mengabaikan huruf kecil
*/

#include <stdio.h>
#include <string.h>
#define MAX 1000
typedef struct Node{
    char str;
    int stack;
    int top;
    struct Node* next;
} Node;

int main() {
    char str[MAX];
    int stack[MAX];
    int top = -1;
    if (fgets(str, MAX, stdin) == NULL) return 0;
    str[strcspn(str, "\n")] = 0;
    int n = strlen(str);
    // untuk ()
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            stack[++top] = i;
        } 
        else if (str[i] == ')') {
            if (top >= 0) {
                top--;
            } else {
                printf("INVALID");
            }
        }
    }
    //untuk {}
    for (int i = 0; i < n; i++) {
        if (str[i] == '{') {
            stack[++top] = i;
        } 
        else if (str[i] == '}') {
            if (top >= 0) {
                top--;
            } else {
                printf("INVALID");
            }
        }
    }
    //untuk []
    for (int i = 0; i < n; i++) {
        if (str[i] == '[') {
            stack[++top] = i;
        } 
        else if (str[i] == ']') {
            if (top >= 0) {
                top--;
            } else {
                printf("INVALID");
            }
        }
    }
    if (top >= 0){
        printf("INVALID");
    }
    else {
        printf("VALID");
    }
    return 0;
}
