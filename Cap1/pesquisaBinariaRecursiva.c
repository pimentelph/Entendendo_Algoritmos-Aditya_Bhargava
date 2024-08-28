#include <stdio.h>
#include <math.h>

#define tamanho 10

int pesquisaBinaria(int arr[], int valorProcurado, int inicio, int final);
int main(void) {

	//Esse array precisa estar ordenado para que possa acontecer a pesquisa binC!ria!
	int arr[tamanho] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 23};
	int valorProcurado = 13;

	int resultado = pesquisaBinaria(arr, valorProcurado, 0, tamanho - 1);

	if (resultado != -1) {
		printf("Elemento encontrado na posicao %d.\n", resultado);
	} else {
		printf("Elemento nao encontrado.\n");
	}


	return 0;
}

int pesquisaBinaria(int arr[], int valorProcurado, int inicio, int final) {

	int meio;

	if(inicio > final) {
		return -1;
	} else {
		meio = (inicio + final)/2;
		if(arr[meio] == valorProcurado) {
			return meio;
		} else if(valorProcurado < arr[meio]) {
			pesquisaBinaria(arr, valorProcurado, inicio, meio - 1);
		} else {
			pesquisaBinaria(arr, valorProcurado, meio + 1, final);
		}
	}
}
