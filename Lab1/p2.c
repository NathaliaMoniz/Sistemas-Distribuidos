//
// Created by natha on 14/02/2024.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i;
    char *end; 
    
    for(i = 1; i < argc; i++){
        
        long numero = strtol(argv[i], &end, 10);
        if (*end != '\0') { 
            printf("Argumento %d = Error de conversion\n", i);   // error en la conversión 
        }
        else{
            printf("Argumento %d = %ld\n", i, numero); 
        }
        
    }
    return 0;
}
