#include <stdio.h>
typedef struct {
        char estado;
        char codigo[4], cidade[50];
        int populacao, pontosTuristicos;
        float area, pib, densidade, pibpercapita, superPoder, inversoDaDensidade;
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
        printf("Super Poder: %2.f de forca\n", c.superPoder);
    
};
void comparandoAsCartas(Carta c1, Carta c2){
    printf("\nComparacao das Cartas:\n");
    printf("Populacao: %s venceu\n", (c1.populacao > c2.populacao) ? "Carta 1" : "Carta 2");
    printf("Area: %s venceu\n", (c1.area > c2.area) ? "Carta 1" : "Carta 2");
    printf("PIB: %s venceu\n", (c1.pib > c2.pib) ? "Carta 1" : "Carta 2");
    printf("Pontos Turisticos: %s venceu\n", (c1.pontosTuristicos > c2.pontosTuristicos) ? "Carta 1" : "Carta 2");
    printf("Densidade: %s venceu\n", (c1.densidade > c2.densidade) ? "Carta 1" : "Carta 2");
    printf("PIB per Capita: %s venceu\n", (c1.pibpercapita > c2.pibpercapita) ? "Carta 1" : "Carta 2");
    printf("Super Poder: %s venceu\n", (c1.superPoder > c2.superPoder) ? "Carta 1" : "Carta 2");
}
float inversoDensidade(Carta c){
    if(c.area > 0){
        return 1 / c.densidade;
    } else {
        return 0;
    };
};
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
    scanf(" %d", &carta1.populacao);
    printf("Area: ");
    scanf(" %f", &carta1.area);
    printf("PIB: ");
    scanf(" %f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &carta1.pontosTuristicos);

    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibpercapita = carta1.pib / carta1.populacao;
    carta1.superPoder = (float) carta1.populacao + carta1.pontosTuristicos + carta1.area + carta1.pib + carta1.pibpercapita + inversoDensidade(carta1);


    printf("\nDigite as informacoes da Segunda Carta: \n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da Carta (Estado + Numeral de 01 - 04): ");
    scanf("%s", carta2.codigo);
    getchar();
    printf("Nome da Cidade: ");
    fgets(carta2.cidade, 50, stdin); 
    printf("Populacao: ");
    scanf(" %d", &carta2.populacao);
    printf("Area: ");
    scanf(" %f", &carta2.area);
    printf("PIB: ");
    scanf(" %f", &carta2.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &carta2.pontosTuristicos);

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibpercapita = carta2.pib / carta2.populacao;
    carta2.superPoder = (float) carta2.populacao + carta2.pontosTuristicos + carta2.area + carta2.pib + carta2.pibpercapita + inversoDensidade(carta2);

    printf("\nCartas Definidas:\n");
    dadosDasCartas(carta1, 2);
    dadosDasCartas(carta2, 2);
    comparandoAsCartas(carta1, carta2);
    return 0;
};