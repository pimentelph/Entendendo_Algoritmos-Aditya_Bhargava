#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void troca(int *a, int *b);
void bubbleSort(int *arr, int tamanhoArr);
void printArray(int arr[], int tamanhoArr);
int pesquisaBinaria(int arr[], int tamanhoArr, int valor);

int main(void) {

  int tamanhoVetorUsuario;
  int valorProcurado;

  printf("Escreva aqui o tamanho do seu vetor: ");
  scanf("%d", &tamanhoVetorUsuario);

  int arrUsuario[tamanhoVetorUsuario];

  printf("Agora, coloque os valores desse vetor, lembre que são somente %d "
         "números\n ", tamanhoVetorUsuario);

  for (int i = 0; i < tamanhoVetorUsuario; i++) {
    printf("\nNúmero %d: ", i + 1);
    scanf("%d", &arrUsuario[i]);
  }

  printf("\n \n");
  
  printf("Agora, usando a pesquisa binária, quer encontrar a posição de qual "
         "valor? Escreva o valor (Lembrando que esse valor precisa existir "
         "dentro do vetor): ");
  scanf("%d", &valorProcurado);
  
  printf("\n \n");
  
  bubbleSort(arrUsuario, tamanhoVetorUsuario);

  printf("Para que possamos fazer a busca binária usamos bubble sort para "
         "ordenar o seu vetor:\n");
  printArray(arrUsuario, tamanhoVetorUsuario);

  int resultado = pesquisaBinaria(arrUsuario, tamanhoVetorUsuario, valorProcurado);

  if (resultado != -1) {
    printf("\nElemento encontrado na posição %d.\n", resultado);
  } else {
    printf("\nElemento não encontrado.\n");
  }

  return 0;
}

void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int *arr, int tamanhoArr) {

  int i, j;
  bool trocado;

  for (i = 0; i < tamanhoArr; i++) {
    trocado = false;
    for (j = 0; j< tamanhoArr - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        troca(&arr[j], &arr[j + 1]);
        trocado = true;
      }
    }

    if (trocado == false)
      break;
  }
}

void printArray(int arr[], int tamanhoArr) {

  for (int i = 0; i < tamanhoArr; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int pesquisaBinaria(int arr[], int tamanhoArr, int valorProcurado) {

  int baixo = 0;
  int alto = tamanhoArr - 1;

  while (baixo <= alto) {
    int somado = baixo + alto;
    int meio = (int)floor((double)somado / 2);
    int chute = arr[meio];

    if (chute == valorProcurado) {
      return meio;
    } else if (chute > valorProcurado) {
      alto = meio - 1;
    } else {
      baixo = meio + 1;
    }
  }
  return -1;
}
