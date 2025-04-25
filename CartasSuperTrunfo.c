#include <stdio.h>
#include <string.h> //em pesquisas na internet foi verificado a inclusão dessa biblioteca

// Desafio Super Trunfo - Países
// Tema 3 - Final
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
    scanf("%s", c->codigo);

    printf("Digite a população: ");
    scanf("%lu", &c->populacao);

    printf("Digite a área(km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

 // Cálculo automático dos atributos derivados
 c->densidadePopulacional = c->populacao / c->area;
 c->pibPercapta = (c->pib * 1000000000) / c->populacao;
}

       // exibição do menu
int escolherAtributo(int ignorar){
       int opcao;
       do{
       printf("Escolha um atributo para comparação:\n");

       if (ignorar != 1) printf("1. População\n");
       if (ignorar != 2)printf("2. Área\n");
       if (ignorar != 3)printf("3. PIB\n");
       if (ignorar != 4)printf("4. PIB per capta\n");
       if (ignorar != 5)printf("5. Densidade populacional\n");
       if (ignorar != 6)printf("6. Pontos turísticos\n");

       printf("Digite sua opção: ");
       scanf("%d", &opcao);
              // verifica se a opção é válida
       if (opcao == ignorar){
              printf("Você já escolheu esse atributo. Escolha outro.\n");
       } else if(opcao <1 || opcao >6){
              printf("Opção inválida ou já foi escolhida anteriormente\n");
       }
  }while (opcao < 1 || opcao > 6 || opcao == ignorar);
  
  return opcao;
}

       // obter valores da do atributo
float obterValorAtributo(Carta c, int atributo){
       switch (atributo){
              case 1: return c.populacao;
              case 2: return c.area;
              case 3: return c.pib * 1000000000;
              case 4: return c.pibPercapta;
              case 5: return c.densidadePopulacional;
              case 6: return c.pontosTuristicos;
              default : return 0;
       }
}
       // exibir nome do atributo
const char* nomeDoAtributo(int atributo){

       switch (atributo){

       case 1: return "População";
       case 2: return "Área";
       case 3: return "PIB";
       case 4: return "PIB per capta";
       case 5: return "Densidade Populacional";
       case 6: return "Pontos turisticos";
       default: return "";
       }
}

       //comparar atributos escolhidos



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
      void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
        float valor1a = obterValorAtributo(c1, atributo1);
        float valor2a = obterValorAtributo(c2, atributo1);

        float valor1b = obterValorAtributo(c1, atributo2);
        float valor2b = obterValorAtributo(c2, atributo2);

         // Soma dos atributos
    float somaCarta1 = valor1a + valor1b;
    float somaCarta2 = valor2a + valor2b;
    
        printf("\n--- Comparação das cartas ---\n");
    
         // Comparação do primeiro atributo
    printf("%s: %.2f vs %.2f => %s\n", nomeDoAtributo(atributo1), valor1a, valor2a,
    valor1a > valor2a ? "Carta 1 vence" : "Carta 2 vence");

     // Comparação do segundo atributo
     printf("%s: %.2f vs %.2f => %s\n", nomeDoAtributo(atributo2), valor1b, valor2b,
     valor1b > valor2b ? "Carta 1 vence" : "Carta 2 vence");

     printf("\nSoma dos atributos para a Carta 1: %.2f\n", somaCarta1);
     printf("Soma dos atributos para a Carta 2: %.2f\n", somaCarta2);

          // Verificação do vencedor
      if (somaCarta1 > somaCarta2) {
       printf("\nCarta 1 vence a rodada!\n");
   } else if (somaCarta1 < somaCarta2) {
       printf("\nCarta 2 vence a rodada!\n");
   } else {
       printf("\nEmpate!\n");
   }
    }
    
      
      //Função principal
      int main() {
          Carta carta1, carta2;
      
          // Cadastro de duas cidades
          printf("\nCadatro da carta 1:\n");
          cadastrarCarta(&carta1);

          printf("\nCadatro da carta 2:\n");
          cadastrarCarta(&carta2);
      
          // Exibição dos dados das duas cidades
          exibirCarta(carta1);
          exibirCarta(carta2);

          //escolha dos atributos
          printf("Escolher atributo da 1 carta\n");
          int atributo1 = escolherAtributo(0);
          printf("escolher atributo da 2 carta\n");
          int atributo2 = escolherAtributo(atributo1);

         //comparar cartas
          compararCartas(carta1, carta2, atributo1, atributo2);
      
          return 0;
      }
