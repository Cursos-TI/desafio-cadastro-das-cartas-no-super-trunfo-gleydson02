#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste Gleydson


    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
  
typedef struct {
    char estado[3];
    char codigo [10];
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

    printf("Cadastro da Carta 1:\n");
    
    printf("Digite o código da carta): ");
    scanf("%s", c->codigo);

    printf("Digite o Nome da Cidade): ");
    scanf("%s", c->nomeCidade);

    printf("Digite a população: ");
    scanf("%d", c->populacao);

    printf("Digite a área(km²): ");
    scanf("%f", c->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", c->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", c->pontosTuristicos);

      // Exibição dos Dados das Cartas:

      void exibirCarta (Carta c) {
        printf("\n--- Dados da Cidade %s (%s) ---\n", c.nomeCidade);
        printf("Código: m%s\n, c.codigo");
        printf("População: %d\n, c.populacao");
        printf("Área: %.2f km²zn, c.area");
        printf ("PIB: %2f Bilhões\n");
        printf("Pontos Turísticos: %dzn, c.pontosTuristicos");
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



    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
  

    
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
