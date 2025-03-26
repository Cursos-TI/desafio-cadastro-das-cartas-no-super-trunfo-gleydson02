#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
//Teste Gleydson


    // Definição das varriáveis para cada atributo da cidade.
  
typedef struct {
    char estado[3];
    int codigo;
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPercapta;
} Carta;

        
    // Cadastro das cartas:

void cadastrarCarta (Carta *c) {

    printf("Cadastro a Carta:\n ");
    
    printf("Digite o código da carta: ");
    scanf("%d", &c->codigo);

    printf("Digite o Nome da Cidade: ");
    scanf(" %s", &c->nomeCidade);

    printf("Digite a população: ");
    scanf("%d", &c->populacao);

    printf("Digite a área(km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
}

      // Exibição dos Dados das Cartas:

      void exibirCarta (Carta c) {
        printf("\n--- Dados da Cidade %d  ---\n", c.nomeCidade);
        printf("Código: %d\n", c.codigo);
        printf("População: %d\n", c.populacao);
        printf("Área: %.2f km²\n", c.area);
        printf ("PIB: %2f Bilhões\n", c.pib);
        printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
      }

    int main() {
        Carta carta1, carta2;

        // cadastro das cartas
        cadastrarCarta(&carta1);
        cadastrarCarta(&carta2);

        // Exibição das cartas cadastradas
        exibirCarta(carta1);
        exibirCarta(carta2);

        return 0;
    }


