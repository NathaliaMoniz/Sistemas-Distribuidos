//
// Created by natha on 14/02/2024.
//

#include <stdio.h>
#include <stdlib.h>

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
    long *num_array;
    int n = 0;
    num_array = (long *)malloc(argc * sizeof(long));

    for(i = 1; i < argc; i++){
        
        long numero = strtol(argv[i], &end, 10);
        if (*end != '\0') { 
            printf("Argumento %d = Error de conversion\n", i);   // error en la conversión 
        }
        else{
            num_array[n] = numero;
            n++;
            
        }
        
    }
    ObtenerMinMax(num_array, n);
    return 0;
}
