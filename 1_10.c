#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int T = 0;
    scanf("%d", &T);
    getchar();
    while (T > 0) {
        int N = 0;
        char *buffer;
        size_t bsize = 10000;
        buffer = (char *) malloc(bsize * sizeof(char));
        getline(&buffer, &bsize, stdin);
        free(buffer);
        buffer = (char *) malloc(bsize * sizeof(char));
        getline(&buffer, &bsize, stdin);
        printf("%s\n", buffer);
        free(buffer);
        T--;
    }
}