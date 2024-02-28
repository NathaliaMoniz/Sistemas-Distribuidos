#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS	2
#define ITER 		10

pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_mutex_t mutex_turno;
pthread_cond_t cond_turno;
int copiado = 0;
int turno = 0;

void funcion(int *id) {
	int j;
	int s;
	double k; 
    int next_id;
    pthread_mutex_lock(&mutex);
	int mid = *id;  // cada thread recibe un número (0 o 1)
    copiado = 1;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);

    if (mid == 0){
        next_id = 1;
    }else{
        next_id = 0;
    }
	for(j=0 ; j < ITER; j++) {
        pthread_mutex_lock(&mutex_turno);
        while (turno = next_id){
            pthread_cond_wait(&cond_turno, &mutex_turno);
        }
        turno = mid; 
        pthread_mutex_unlock(&mutex_turno);
		k = (double) rand_r((unsigned int *) &s) / RAND_MAX;	
		usleep((int) (k * 100000)); // duerme entre 0 y 100 ms
		printf("Ejecuta el thread %d iteracion %d \n", mid, j );
	}

	pthread_exit(NULL);

}

int main(int argc, char *argv[])
{
	int j;
	pthread_attr_t attr;
	pthread_t thid[NUM_THREADS];
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	struct timeval t;

	gettimeofday(&t, NULL);
	srand(t.tv_sec);	// se inicializa la semilla de nª pseudoaleatorios

	pthread_attr_init(&attr);

	for (j = 0; j < NUM_THREADS; j++){ 
		if (pthread_create(&thid[j], NULL, (void *) funcion, &j) == -1){
			printf("Error al crear los threads\n");
			exit(0);
		}

		pthread_mutex_lock(&mutex);
		while(copiado == 0){
			pthread_cond_wait(&cond, &mutex);
		}
		copiado = 0;
		pthread_mutex_unlock(&mutex);
	} 
	for (j = 0; j < NUM_THREADS; j++){ 
		pthread_join(thid[j], NULL);
	}
	exit(0);

}
	

	

