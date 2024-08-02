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
  
  int baixo = 0;
  int alto = sizeof(arr) - 1;

  while (baixo <= alto){
    int somado = baixo + alto;
    int meio = (int)floor((double)somado / 2);
    int chute = arr[meio];

    if (chute == valorProcurado){
      return meio;
    } else if(chute > valorProcurado){
      alto = meio - 1;
    } else{
      baixo = meio + 1;
    }
  }
  return -1;
}
