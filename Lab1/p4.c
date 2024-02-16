//
// Created by natha on 14/02/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void ObtenerMinMax(long numbers[], int n){
    int max = 0;
    int min = 1000;

    for (int i = 0; i < n; i++){
        if (numbers[i] < min){
            min = numbers[i];
        }
        if (numbers[i] > max){
            max = numbers[i];
        }
    }
    printf("Máximo = %d\n", max);
    printf("Mínimo = %d\n", min);

}
int main(int argc, char *argv[]){
    int i;
    char *end; 
    long *num_array = (long *)malloc(argc * sizeof(long));
    char **string_array = (char**)malloc(argc * sizeof(char*));
    int n = 0;
    int cadenas = 0; 

    for(i = 1; i < argc; i++){
        
        
        long numero = strtol(argv[i], &end, 10);
        if (*end != '\0') { 
            string_array[cadenas] = (char*)malloc(strlen(argv[i] + 1));
            strcpy(string_array[cadenas], argv[i]);  //copia el contenido de argv[i] a string_array[cadenas]
            printf("Cadena #%d = %s\n", (cadenas + 1), string_array[cadenas]);
            cadenas ++;    
        }
        else{
            num_array[n] = numero;
            n++;
            
        }
        
    }
    ObtenerMinMax(num_array, n);
    for (i = 0; i < cadenas; i++) {
        free(string_array[i]);
    }
    free(num_array);
    free(string_array);
    return 0;
}
