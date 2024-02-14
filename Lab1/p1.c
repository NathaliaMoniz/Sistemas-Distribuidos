//
// Created by natha on 14/02/2024.
//

#include <stdio.h>

int main(int argc, char *argv[]){
    int i;

    for(i = 1; i < argc; i++){
        printf("Argumento %d = %s\n", i, argv[i]);
    }
    return 0;
}
