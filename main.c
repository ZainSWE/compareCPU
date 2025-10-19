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
    cpu[0].clock = 3.6;
    cpu[0].cache = 25.0;
    cpu[0].price = 573.52;
    cpu[0].threads = 20;
    cpu[0].cores = 12;
    cpu[0].tdp = 125;


    double score = calculateScore(ptr);
    double value = score / cpu[0].price;
    double efficiency = score / cpu[0].tdp;

    printf("score: %.2lf\n", score);
    printf("value: %.2lf\n", value);
    printf("efficiency: %.2lf\n", efficiency);

    return 0;
}

double calculateScore(CPU *ptr) {

    double result = (ptr->clock * ptr->cores * 1.0) + (ptr->cache * 0.5) + (ptr->cache * 0.3);

    return result;
}
