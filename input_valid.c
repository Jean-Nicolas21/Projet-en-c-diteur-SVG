#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




void clear_buffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

int ask_for_int(const char* message) {
    int temp;
    int scan_result;
    do {
        printf("%s ", message);
        scan_result = scanf("%d", &temp);
        if (scan_result == 1) {
            clear_buffer(); 
            return temp;
        } else {
            fprintf(stderr, "Wrong input. Please try to press a valid number.\n");
            clear_buffer();
        }
    } while (true); 
}