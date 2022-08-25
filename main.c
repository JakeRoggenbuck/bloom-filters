#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_PATH "./english-words/words_alpha.txt"
#define BUF_LEN 40
#define ARR_LEN 180000
#define WORD_LEN 40

void print_array(char arr[ARR_LEN][WORD_LEN], int n) {
    for (int i = 0; i < n; i++) {
        printf("A%sA\n", arr[i]);
    }
}

int linear_search_setup(char arr[ARR_LEN][WORD_LEN], int n) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i;

    fp = fopen(WORDS_PATH, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (i > n - 1) {
            return 0;
        }
        line[strlen(line) - 1] = '\0';
        strcpy(arr[i], line);
        i++;
    }

    free(line);
    exit(EXIT_SUCCESS);
}

int linear_search(char arr[ARR_LEN][WORD_LEN], int n, char *val) {
    // This does not scale well at O(n) on average
    // Best		Average		Worst	Space
    // O(1)		O(N)    	O(N)	O(1)
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], val) == 0) {
            return i;
        }
    }

    return -1;
}

int linear_search_test(char *val) {
    char arr[ARR_LEN][WORD_LEN];
    linear_search_setup(arr, ARR_LEN);
    print_array(arr, ARR_LEN);
    printf("Built.\n");

    clock_t begin = clock();
    linear_search(arr, ARR_LEN, val);
    clock_t end = clock();
    printf("Linear search time: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

int main() {
    linear_search_test("margin");
    return 0;
}
