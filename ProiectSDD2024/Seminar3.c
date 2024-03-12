#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Masina {
	int id;
	char* producator;
	int nrUsi;
	float pret;
};


struct Masina* adaugaInVector(struct Masina* masini, struct Masina m, int* nrMasini) {
	struct Masina* aux = malloc(sizeof(struct Masina) * ((*nrMasini) + 1));
	for (int i = 0; i < *nrMasini; i++) {
		aux[i] = masini[i];

	}
	aux[*nrMasini] = m;

	*nrMasini = (*nrMasini) + 1;

	if (masini != NULL) {
		free(masini);
	}

	return aux;




}


struct Masina* citireFisier(const char* numeFisier, int* nrMasini) {
	FILE* file = fopen(numeFisier, "r");
	char buffer[100];
	char delimitator[] = ",\n";
	struct Masina* masini = NULL;

	(*nrMasini) = 0;
	while (fgets(buffer, 100, file) != NULL) {
		char* element = strtok(buffer, delimitator);
		struct Masina m;
		m.id = atoi(element);
		element = strtok(NULL, delimitator);
		m.producator = malloc(strlen(element) + 1);
		strcpy(m.producator, element);
		element = strtok(NULL, delimitator);
		m.nrUsi = atoi(element);
		element = strtok(NULL, delimitator);
		m.pret = atof(element);
		element = strtok(NULL, delimitator);

		masini = adaugaInVector(masini, m, nrMasini);
	}
	fclose(file);
	return masini;
}

//struct Masina* masiniModificate(struct Masina* masini, int* nrMasini) {
//	int nrMasiniNoi = 0;
//	for (int i = 0; i < nrMasini; i++) {
//		if (masini[i].nrUsi > 2) {
//			nrMasiniNoi++;
//		}
//	}
//	struct Masina* masiniUsi = malloc(sizeof(struct Masina) * nrMasiniNoi);
//	int j = 0;
//	for (int i = 0; i < nrMasiniNoi; i++) {
//		if (masini[i].nrUsi > 2) {
//			masiniUsi[j] = masini[i];
//			j++;
//		}
//	}
//}

int main() {
	struct Masina* masini = NULL;
	int nrMasini = 0;
	masini = citireFisier("masina.txt", &nrMasini);
	masini = masiniMulteUsi(masini, &nrMasini);
	for (int i = 0; i < nrMasini; i++) {

		printf("Masina nr: %d\n", i);
		printf("Id: %d\n", masini[i].id);
		printf("Producator: %s\n", masini[i].producator);
		printf("Nr usi: %d\n", masini[i].nrUsi);
		printf("Pret: %5.2f\n", masini[i].pret);
		printf("\n");

	}


}