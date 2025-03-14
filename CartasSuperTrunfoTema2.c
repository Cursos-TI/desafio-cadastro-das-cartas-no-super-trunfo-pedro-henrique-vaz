#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4], cidade[50];
    int populacao, pontosTuristicos;
    float area, pib, densidade, pibpercapita, superPoder;
} Carta;

void dadosDasCartas(Carta c, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Nome da Cidade: %s", c.cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km\n", c.area);
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Numero de Pontos Turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional da Cidade: %.2f hab/km\n", c.densidade);
    printf("PIB per Capita da Cidade: %.2f reais\n", c.pibpercapita);
    printf("Super Poder: %.2f de forca\n", c.superPoder);
}

void comparandoAsCartas(Carta c1, Carta c2){
    int opcao;
    int opcaoPopulacao = 1, opcaoArea = 1, opcaoPib = 1, opcaoPontos = 1, opcaoDensidade = 1, opcaoVencedor = 1;
    float somaC1, somaC2;
    
    do {
        printf("Escolha o que quer comparar:\n");
        if (opcaoPopulacao) printf("1. Populacao\n");
        if (opcaoArea) printf("2. Area\n");
        if (opcaoPib) printf("3. PIB\n");
        if (opcaoPontos) printf("4. Pontos Turisticos\n");
        if (opcaoDensidade) printf("5. Densidade Demografica\n");
        if (opcaoVencedor) printf("6. Descobrir Qual Carta e a Vencedora\n");
        printf("Digite a que deseja ou para sair, digite 0: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                if (opcaoPopulacao) {
                    printf("Apos a comparacao, o pais %c e o vencedor com aproximadamente %d habitantes.\n",
                        (c1.populacao > c2.populacao) ? c1.estado : c2.estado,
                        (c1.populacao > c2.populacao) ? c1.populacao : c2.populacao);
                    opcaoPopulacao = 0;
                }
                break;
            case 2:
                if (opcaoArea) {
                    printf("Apos a comparacao, o pais %c e o vencedor com uma area de %.2f km².\n",
                        (c1.area > c2.area) ? c1.estado : c2.estado,
                        (c1.area > c2.area) ? c1.area : c2.area);
                    opcaoArea = 0;
                }
                break;
            case 3:
                if (opcaoPib) {
                    printf("Apos a comparacao, o pais %c e o vencedor com um PIB de %.2f bilhoes.\n",
                        (c1.pib > c2.pib) ? c1.estado : c2.estado,
                        (c1.pib > c2.pib) ? c1.pib : c2.pib);
                    opcaoPib = 0;
                }
                break;
            case 4:
                if (opcaoPontos) {
                    printf("Apos a comparacao, o pais %c e o vencedor com um total de %d pontos turisticos.\n",
                        (c1.pontosTuristicos > c2.pontosTuristicos) ? c1.estado : c2.estado,
                        (c1.pontosTuristicos > c2.pontosTuristicos) ? c1.pontosTuristicos : c2.pontosTuristicos);
                    opcaoPontos = 0;
                }
                break;
            case 5:
                if (opcaoDensidade) {
                    printf("Apos a comparacao, o pais %c e o vencedor com %.2f de densidade demografica.\n",
                        (c1.densidade < c2.densidade) ? c1.estado : c2.estado,
                        (c1.densidade < c2.densidade) ? c1.densidade : c2.densidade);
                    opcaoDensidade = 0;
                }
                break;
            case 6:
                if (opcaoVencedor) {
                    somaC1 = (float) c1.area + c1.populacao + c1.pib + c1.pontosTuristicos + 1 / c1.densidade;
                    somaC2 = (float) c2.area + c2.populacao + c2.pib + c2.pontosTuristicos + 1 / c2.densidade;
                    printf("Apos a comparacao, o pais %c e o vencedor pois possui o maior poder de soma.\n",
                        (somaC1 > somaC2) ? c1.estado : c2.estado);
                    opcaoVencedor = 0;
                }
                break;
            case 0:
                printf("Voce optou por sair do jogo.\n");
                break;
            default:
                printf("Empate!\n");
        }
    } while (opcao != 0);
}

int main(){
    Carta carta1, carta2;
    
    printf("\nBem-Vindo ao Super Trunfo de Paises!\n");
    
    printf("\nDigite as informacoes da Primeira Carta: \n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Codigo (Estado + Numeral de 01 - 04): ");
    scanf("%s", carta1.codigo);
    getchar();
    printf("Nome da Cidade: ");
    fgets(carta1.cidade, 50, stdin);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calcular a densidade da carta 1
    carta1.densidade = carta1.populacao / carta1.area;

    printf("\nDigite as informacoes da Segunda Carta: \n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo (Estado + Numeral de 01 - 04): ");
    scanf("%s", carta2.codigo);
    getchar();
    printf("Nome da Cidade: ");
    fgets(carta2.cidade, 50, stdin);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Calcular a densidade da carta 2
    carta2.densidade = carta2.populacao / carta2.area;

    comparandoAsCartas(carta1, carta2);
    return 0;
}
