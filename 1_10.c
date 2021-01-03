/**
 * <------Description------>
 * Given K sorted arrays arranged in a form of a matrix, your task is to merge them.
 * You need to complete mergeKArrays function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the no. of sorted arrays.
 * The function should return a pointer to the merged sorted arrays. There are multiple test cases.
 * For each test case, this method will be called individually.
 *
 * <------Input------>
 * The first line of input will denote the no of Test cases then T test cases will follow .
 * Each test cases will contain an integer N denoting the no of sorted arrays.
 * Then in the next line contains all the elements of the array separated by space.（1<=T<=50；1<=N<=10）
 *
 * <------Output------>
 * The output will be the sorted merged array.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int T = 0;
    scanf("%d", &T);
    getchar();
    while (T > 0) {
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