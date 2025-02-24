#include <stdio.h>
typedef struct {
    char estado;
    char codigo[4], cidade[50];
    int populacao, pontos_turisticos;
    float area, pib;
} Carta;
        
void dadosDasCartas(Carta c, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Nome da Cidade: %s", c.cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km\n", c.area);
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Numero de Pontos Turisticos: %d\n", c.pontos_turisticos);
};
int main(){
    Carta carta1, carta2;
    printf("Bem-Vindo ao Super Trunfo de Paises!\n");
    printf("Digite as informacoes da Primeira Carta: \n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Codigo (A01-H04): ");
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
    scanf(" %d", &carta1.pontos_turisticos);
    
    printf("Digite as informacoes da Segunda Carta: \n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da Carta (A01-H04): ");
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
    scanf(" %d", &carta2.pontos_turisticos);
    
    printf("\nCartas Definidas:\n");
    dadosDasCartas(carta1, 1);
    dadosDasCartas(carta2, 2);
    return 0;
};
