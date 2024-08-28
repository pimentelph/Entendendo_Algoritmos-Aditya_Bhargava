#include <stdio.h>
#include <math.h>

int pesquisaBinaria(int arr[], int valorProcurado);

int main(void) {

  //Esse array precisa estar ordenado para que possa acontecer a pesquisa binária!
  int arr[10] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 23};
  int valorProcurado = 5;

  int resultado = pesquisaBinaria(arr, valorProcurado);

  if (resultado != -1) {
      printf("Elemento encontrado na posição %d.\n", resultado);
  } else {
      printf("Elemento não encontrado.\n");
  }

  
  return 0;
}

int pesquisaBinaria(int arr[], int valorProcurado){
  
  int inicio = 0;
  int final = sizeof(arr) - 1;

  while (inicio <= final){
    int somado = inicio + final;
    int meio = (int)floor(somado / 2);
    int chute = arr[meio];

    if (chute == valorProcurado){
      return meio;
    } else if(chute > valorProcurado){
      final = meio - 1;
    } else{
      inicio = meio + 1;
    }
  }
  return -1;
}
