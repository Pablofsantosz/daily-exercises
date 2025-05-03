#include <stdio.h>

void encontrar_indices(int nums[], int tamanho, int target) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Indices encontrados: [%d, %d]\n", i, j);
                return;
            }
        }
    }
    printf("Nenhuma combinacao encontarada.\n");
}


int main() {
    int vetor[5];
    int target;

    printf("Informe o numero target: ");
    scanf("%d", &target);

    printf("Agora informe os valores dentro do vetor:\n");
    for (int i = 0; i < 5; i++) {
        printf("valor na posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    encontrar_indices(vetor, tamanho, target);

    return 0;
}
 