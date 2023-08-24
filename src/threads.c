#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "funct.c"

int main() {
	pthread_t threads[4];

	pthread_create(&threads[0], NULL, funct, NULL);
	pthread_create(&threads[1], NULL, funct, NULL);
	pthread_create(&threads[2], NULL, funct, NULL);
	pthread_create(&threads[3], NULL, funct, NULL);

	for (int i = 0; i < 4; i++)
		pthread_join(threads[i], NULL);
}
