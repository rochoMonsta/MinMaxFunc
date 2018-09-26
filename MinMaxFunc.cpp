#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


void to_entry(int n1, int n2, int **mas, int na, int nb) {
	int i, j;
	for (i = 0; i < na; i++) {
		for (j = 0; j < nb; j++) {
			mas[i][j] = n1 + rand() % n2;
		}
	}
}

void to_findMaxMin(int **mass, int na, int nb, int rc[], int rc1[]) {
	int i, j, z, max = 0, min = 0;
	for (i = 0; i < na; i++) {
		rc[i] = max;
		rc1[i] = min;
		max = 0;
		min = 0;
		for (z = 0; z < 1; z++) {
			if (mass[i][0] > mass[i][1]) {
				max = mass[i][0];
				min = mass[i][1];
			}
			else {
				max = mass[i][1];
				min = mass[i][0];
			}
			for (j = 2; j < nb; j++) {
				if (max > mass[i][j]) {
					continue;
				}
				else {
					max = mass[i][j];
				}
				if (min > mass[i][j]) {
					min = mass[i][j];
				}
				else {
					continue;
				}
			}
		}
	}
	rc[i + 1] = max;
	rc1[i + 1] = min;
}

int to_findMax(int rc[], int nb) {
	int i, j, max;
	if (rc[0] > rc[1]) {
		max = rc[0];
	}
	else {
		max = rc[1];
	}
	for (i = 0; i < nb + 1; i++) {
		for (j = 2; j < nb + 1; j++) {
			if (rc[j] > max) {
				max = rc[j];
			}
			else {
				continue;
			}
		}
	}
	return max;
}

int to_findMin(int rc1[], int nb) {
	int i, j, min=0;
	if (rc1[1] > rc1[2]) {
		min = rc1[2];
	}
	else {
		min = rc1[1];
	}
	for (j = 3; j < nb; j++) {
		if (rc1[j] > min){
			continue;
		}
		else{
			min = rc1[j];
		}
	}
	return min;
}


int main(void) {
	srand(time(NULL) | clock());
	int a, b, aa, bb, i, j;
	printf("VVedit kilkist ryadkiv: ");
	scanf("%d", &a);
	printf("VVedit kilkist stovpziv: ");
	scanf("%d", &b);

	printf("VVedit granuzi randomu:\n ");
	printf("Min: ");
	scanf("%d", &aa);
	printf("Max: ");
	scanf("%d", &bb);
	int **mass;
	mass = (int**)calloc(a, sizeof(int*));
	for (int i = 0; i < b; i++) {
		mass[i] = (int*)calloc(b, sizeof(int));
	}
	int *masmax;
	int *masmin;
	masmax = (int*)calloc(b + 1, sizeof(int));
	masmin = (int*)calloc(b + 1, sizeof(int));
	
	to_entry(aa, bb, mass, a, b); 
	printf("\n----------Vasha Matruzya----------\n");
	for (i = 0; i < a; i++) {
		printf("\n");
		for (j = 0; j < b; j++) {
			printf("%d ", mass[i][j]);
		}
	}
	to_findMaxMin(mass, a, b, masmax, masmin);
	int maxx = to_findMax(masmax, b);
	int minn = to_findMin(masmin, b);
	printf("\n");
	printf("\n-----Vashe Maxumalne i Minimalne znachenya----- \n");
	printf("\n");
	printf("Maxumalne: %d\n", maxx);
	printf("Minimalne: %d\n", minn);
	return 0;
}
