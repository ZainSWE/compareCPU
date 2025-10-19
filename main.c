#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct CPU {
    char name[50];
    double clock;
    double l3cache;
    double price;
    int threads;
    int cores;
    int tdp;
} CPU;

void hashSeperator();

double calculateScore(CPU *ptr, double weight);

int main () {

    CPU cpu[1];
    CPU *ptr = &cpu[0];

    strcpy (cpu[0].name, "null");
    cpu[0].clock = 3.6;
    cpu[0].l3cache = 25.0;
    cpu[0].price = 573.52;
    cpu[0].threads = 20;
    cpu[0].cores = 12;
    cpu[0].tdp = 125;


    char line[255];
    double weight;
    double score;
    double value;
    double efficiency;

    do {
	printf("Enter L3 cache weight (ranging from 0.0 to 1.0): ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%lf", &weight);

	if (weight > 1.0 || weight < 0.0) {
	    hashSeperator();
	    printf("# Error: weight must range from 0.0 to 1.0 #\n");
	    hashSeperator();
	}

    } while (weight > 1.0 || weight < 0.0);

    score = calculateScore(ptr, weight);
    value = score / cpu[0].price;
    efficiency = score / cpu[0].tdp;

    hashSeperator();
    printf("score: %.2lf\n", score);
    printf("value: %.2lf\n", value);
    printf("efficiency: %.2lf\n", efficiency);
    hashSeperator();

    return 0;
}

double calculateScore(CPU *ptr, double weight) {

    double result = (ptr->clock * ptr->cores) + (ptr->l3cache * weight);

    return result;
}

void hashSeperator() {
    for (int i = 0; i < 44; i++) {
	printf("#");
    }
    printf("\n");
}
