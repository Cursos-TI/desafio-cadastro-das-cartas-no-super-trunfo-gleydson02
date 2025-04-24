#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
//Teste Gleydson


    // Definição das varriáveis para cada atributo da cidade.
  
    typedef struct {
        char codigo[4];
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

    //printf("Cadastro a Carta:\n ");
    
      printf("Digite o Nome da Cidade: ");
    scanf("%s", c->nomeCidade);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", &c->codigo);

    printf("Digite a população: ");
    scanf("%d", &c->populacao);

    printf("Digite a área(km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

 // Cálculo dos atributos derivados
 c->densidadePopulacional = c->populacao / c->area;
 c->pibPercapta = (c->pib * 1000000000) / c->populacao;
}
      // Exibição dos Dados das Cartas:
void exibirCarta(Carta c) {
    printf("\n--- Dados da Cidade %s ---\n", c.nomeCidade);
    //printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("PIB per capita: %.2f\n", c.pibPercapta);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
      }

      // Cálculo do Super Poder
      void calcularSuperPoder(Carta c){
        return (float) c.populacao + c.area + c.pib + c.pontosTuristicos + c.pibPercapta +(1 / c.densidadePopulacional);
      }

      // Função para comparar os atributos entre duas cartas
      void compararCartas (Carta c1, Carta c2){

        printf("\n--- Comparação das cartas---\n" );

        printf("População: %d\n", c1.populacao > c2.populacao);
        printf("Área: %.2f km²\n", c1.area > c2.area);
        printf("PIB: %.2f bilhões\n", c1.pib > c2.pib);
        printf("PIB per capita: %.2f\n", c1.pibPercapta > c2.pibPercapta);
        printf("Densidade Populacional: %.2f hab/km²\n", c1.densidadePopulacional < c2.densidadePopulacional);
        printf("Pontos Turísticos: %d\n", c1.pontosTuristicos > c2.pontosTuristicos);
      }
      
      //Função principal
      int main() {
          Carta carta1, carta2;
      
          // Cadastro de duas cidades
          cadastrarCarta(&carta1);
          cadastrarCarta(&carta2);
      
          // Exibição dos dados das duas cidades
          exibirCarta(carta1);
          exibirCarta(carta2);
      
          return 0;
      }
