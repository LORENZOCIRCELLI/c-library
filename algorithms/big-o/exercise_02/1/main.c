#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef int32_t i32;

bool runNumbers(i32 n) {
  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);

  for (long i = 0; i < n; i++)
    ;

  double tempo =
      (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

  printf("Tempo da Funcao: %f s\n", tempo);
  return 1;
}

int main(void) {

  int option = -1;

  printf("Bem-vindo a Central de Operacoes Big-O!\n");

  printf("Aqui voce vera algumas operacoes e suas complexidades de tempo!\n");

  printf("-------------------  M E N U  -------------------\n");

  while (option != 0) {

    printf("Insira a operacao que deseja efetuar!\n");

    printf("1 - Imprimir os numeros de 0 a n-1\n");
    printf("2 - Realizar as operacoes fatoriais\n");
    printf("3 - Realizar uma busca linear\n");
    printf("4 - Realizar uma busca em um array ordenado\n");
    printf("5 - Analisar o tempo de ordenacao de um algoritmo bubble sort\n");
    printf("6 - Complexidade de tempo do algoritmo merge sort\n");
    printf("7 - Executar todas as funcoes em sequencia\n");
    printf("0 - Sair do programa!\n");

    scanf("%d", &option);

    switch (option) {
    case 1:
      i32 n = 0;
      printf("\n---------------------------------------------------------------"
             "\n");
      printf("Iniciando Operacao: Imprimir os números de 0 a n-1\n");
      printf("Alocando n...\n");
      scanf("%d", &n);
      printf("Atribuindo a variavel n a funcao...\n");
      printf("Iniciando o contador\n");
      printf("Funcao em Operacao\n");
      bool flag = runNumbers(n);
      if (flag == 1) {
        printf("Funcao executada com sucesso!\n");
        printf("Encerrando operacao...\n");
        printf("Retornando ao menu!\n");
      }
      printf("---------------------------------------------------------------"
             "\n");
      break;
    case 2:

    case 0:
      break;
    }
  }
}
