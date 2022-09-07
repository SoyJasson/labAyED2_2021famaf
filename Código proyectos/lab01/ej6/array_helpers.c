#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    FILE*archivo = fopen(filepath, "r");
    unsigned int largo = 0;
    if(!feof(archivo)){
        fscanf(archivo, "%u",&largo);
        assert(max_size >= largo);
        for(unsigned int i=0; i < largo && !feof(archivo); i++){
            fscanf(archivo, "%d", &array[i]);
        };
    };
    fclose(archivo);
    return largo;
}

void array_dump(int a[], unsigned int length) {
    if(length>0){
        printf("[");
        for(unsigned int i = 0; i < length-1; i++){
            printf(" %d,",a[i]);
        };
        printf(" %d]\n",a[length-1]);
    };
}

bool array_is_sorted(int a[], unsigned int length){
    bool res = true;
    for(unsigned int i = 0; i < length-1; i++){
        res = res && a[i] <= a[i+1];
    };
    return res;
}

void array_swap(int a[], unsigned int i, unsigned int j){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void invertir_array(int a[], unsigned int length){
    for(unsigned int i = 0; i < length/2; ++i){
        array_swap(a,i,length-1-i);
    };
}