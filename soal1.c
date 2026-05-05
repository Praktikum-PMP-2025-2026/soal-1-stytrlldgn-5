/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*   Modul               : 4 - Dynamic Structures
*   Hari dan Tanggal    : selasa, 5 Mei 2026
*   Nama (NIM)          : I Ketut Satya Adnyana (13224076)
*   Nama File           : soal1.c
*   Deskripsi           : 
*/
//code biasa dengan data manipulasi
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000
int main() {
    char str[MAX];
    bool hapus[MAX] = {false}; 
    int stack[MAX];
    int top = -1;
    if (fgets(str, MAX, stdin) == NULL) return 0;
    str[strcspn(str, "\n")] = 0;

    int n = strlen(str);

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
        hapus[stack[top--]] = true;
        printf("INVALID");
    }
    else {
        printf("VALID");
    }
    
    return 0;
}
