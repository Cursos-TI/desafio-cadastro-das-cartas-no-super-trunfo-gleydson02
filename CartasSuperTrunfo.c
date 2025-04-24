#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
//Teste Gleydson


    // Definição das varriáveis para cada atributo da cidade.
  
    typedef struct {
        char codigo[4];
        char nomeCidade[50];
        unsigned long int populacao;
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
    scanf("%lu", &c->populacao);

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
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("PIB per capita: %.2f\n", c.pibPercapta);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
      }

      // Cálculo do Super Poder
      float calcularSuperPoder(Carta c){
        return(float)c.populacao + c.area + (c.pib * 1000000000) + c.pontosTuristicos + c.pibPercapta +(1.0 / c.densidadePopulacional);
      }

      // Função para comparar os atributos entre duas cartas
      void compararCartas(Carta c1, Carta c2) {
        float sp1 = calcularSuperPoder(c1);
        float sp2 = calcularSuperPoder(c2);
    
        printf("\n--- Comparação das cartas ---\n");
    
        printf("População: %lu vs %lu => %s\n", c1.populacao, c2.populacao,
               c1.populacao > c2.populacao ? "Carta 1 vence" : "Carta 2 vence");
    
        printf("Área: %.2f km² vs %.2f km² => %s\n", c1.area, c2.area,
               c1.area > c2.area ? "Carta 1 vence" : "Carta 2 vence");
    
        printf("PIB: %.2f bilhões vs %.2f bilhões => %s\n", c1.pib, c2.pib,
               c1.pib > c2.pib ? "Carta 1 vence" : "Carta 2 vence");
    
        printf("PIB per capita: %.2f vs %.2f => %s\n", c1.pibPercapta, c2.pibPercapta,
               c1.pibPercapta > c2.pibPercapta ? "Carta 1 vence" : "Carta 2 vence");
    
        printf("Densidade Populacional (menor vence): %.2f vs %.2f => %s\n", c1.densidadePopulacional, c2.densidadePopulacional,
               c1.densidadePopulacional < c2.densidadePopulacional ? "Carta 1 vence" : "Carta 2 vence");
    
        printf("Pontos Turísticos: %d vs %d => %s\n", c1.pontosTuristicos, c2.pontosTuristicos,
               c1.pontosTuristicos > c2.pontosTuristicos ? "Carta 1 vence" : "Carta 2 vence");
    
        printf("Super Poder: %.2f vs %.2f => %s\n", sp1, sp2,
               sp1 > sp2 ? "Carta 1 vence" : "Carta 2 vence");
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

         //comparar cartas
          compararCartas(carta1, carta2);
      
          return 0;
      }
