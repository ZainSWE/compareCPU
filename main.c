#include <stdio.h>
#include <string.h>

typedef struct CPU {
    char name[50];
    double clock;
    double cache;
    double price;
    int threads;
    int cores;
    int tdp;
} CPU;

double calculateScore(CPU *ptr);

int main () {

    CPU cpu[1];
    CPU *ptr = &cpu[0];

    strcpy (cpu[0].name, "null");
    cpu[0].clock = 3.5;
    cpu[0].cache = 0.0;
    cpu[0].price = 0.0;
    cpu[0].threads = 0;
    cpu[0].cores = 6;
    cpu[0].tdp = 0;


    double score = calculateScore(ptr);
    double value = score / cpu[0].price;
    double efficiency = score / cpu[0].tdp;

    printf("score: %.1lf\n", score);

    return 0;
}

double calculateScore(CPU *ptr) {

    double result = ptr->clock * ptr->cores;

    return result;
}
