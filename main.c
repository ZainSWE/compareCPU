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

void hashSeperator(int size);
double calculateScore(CPU *cpu, double weight);

int main () {

    CPU cpu[2];
    CPU *cpu1 = &cpu[0];
    CPU *cpu2 = &cpu[1];


    strcpy (cpu[0].name, "null");
    cpu[0].clock = 0.0;
    cpu[0].l3cache = 0.0;
    cpu[0].price = 0.0;
    cpu[0].threads = 0;
    cpu[0].cores = 0;
    cpu[0].tdp = 0;

    strcpy (cpu[1].name, "null");
    cpu[1].clock = 0.0;
    cpu[1].l3cache = 0.0;
    cpu[1].price = 0.0;
    cpu[1].threads = 0;
    cpu[1].cores = 0;
    cpu[1].tdp = 0;

    int size = 44;
    char line[255];
    double weight;
    double scoreCPU1, scoreCPU2;
    double valueCPU1, valueCPU2;
    double efficiencyCPU1, efficiencyCPU2;

    // CPU 1

    printf("Enter CPU 1 name: ");
    fgets(cpu[0].name, sizeof(cpu[0].name), stdin);
    cpu[0].name[strcspn(cpu[0].name, "\n")] = '\0';

    printf("Enter clock speed (Ghz): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &cpu[0].clock);

    printf("Enter L3 cache (MB): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &cpu[0].l3cache);

    printf("Enter price: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &cpu[0].price);

    printf("Enter threads: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &cpu[0].threads);

    printf("Enter cores: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &cpu[0].cores);

    printf("Enter tdp/power (W): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &cpu[0].tdp);

    do {
        printf("Enter L3 cache weight (ranging from 0.0 to 1.0): ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%lf", &weight);

	if (weight > 1.0 || weight < 0.0) {
	    hashSeperator(size);
	    printf("# Error: weight must range from 0.0 to 1.0 #\n");
	    hashSeperator(size);
	}

    } while (weight > 1.0 || weight < 0.0);

    hashSeperator(size);

    // CPU 2

    printf("Enter CPU 2 name: ");
    fgets(cpu[1].name, sizeof(cpu[1].name), stdin);
    cpu[1].name[strcspn(cpu[1].name, "\n")] = '\0';

    printf("Enter clock speed (Ghz): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &cpu[1].clock);

    printf("Enter L3 cache (MB): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &cpu[1].l3cache);

    printf("Enter price: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &cpu[1].price);

    printf("Enter threads: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &cpu[1].threads);

    printf("Enter cores: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &cpu[1].cores);

    printf("Enter tdp/power (W): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &cpu[1].tdp);

    do {
	printf("Enter L3 cache weight (ranging from 0.0 to 1.0): ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%lf", &weight);

	if (weight > 1.0 || weight < 0.0) {
	    hashSeperator(size);
	    printf("# Error: weight must range from 0.0 to 1.0 #\n");
	    hashSeperator(size);
	}

    } while (weight > 1.0 || weight < 0.0);

    scoreCPU1 = calculateScore(cpu1, weight);
    valueCPU1 = scoreCPU1 / cpu[0].price;
    efficiencyCPU1 = scoreCPU1 / cpu[0].tdp;

    scoreCPU2 = calculateScore(cpu2, weight);
    valueCPU2 = scoreCPU2 / cpu[1].price;
    efficiencyCPU2 = scoreCPU2 / cpu[1].tdp;

    hashSeperator(size);
    printf("CPU: %s\n", cpu[0].name);
    printf("score: %.2lf\n", scoreCPU1);
    printf("value: %.2lf\n", valueCPU1);
    printf("efficiency: %.2lf\n", efficiencyCPU1);
    hashSeperator(size);
    printf("CPU: %s\n", cpu[1].name);
    printf("score: %.2lf\n", scoreCPU2);
    printf("value: %.2lf\n", valueCPU2);
    printf("efficiency: %.2lf\n", efficiencyCPU2);
    hashSeperator(size);

    return 0;
}

double calculateScore(CPU *cpu, double weight) {
    return (cpu->clock * cpu->cores) + (cpu->l3cache * weight);
}

void hashSeperator(int size) {

    for (int i = 0; i < size; i++) {
	    printf("#");
    }
    printf("\n");
}
