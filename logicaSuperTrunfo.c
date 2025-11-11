
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 📇 Estrutura (struct) para representar uma Carta de Cidade
typedef struct {
    char estado[3]; 
    char codigoCarta[10];
    char nomeCidade[50];
    long populacao;        // Atributo 1: População
    double area;           // Atributo 2: Área (km²)
    double pib;            // Atributo 3: PIB (em bilhões, R$)
    int numPontosTuristicos; // Atributo 4: Número de pontos turísticos
} CartaCidade;

// --- Função para Cadastrar uma Carta ---
void cadastrarCarta(CartaCidade *carta, int numero) {
    printf("\n--- 📝 Cadastro da Carta %d ---\n", numero);
    
    printf("Estado (ex: RJ): ");
    scanf("%2s", carta->estado); 
    
    printf("Código da Carta (ex: C001): ");
    scanf("%9s", carta->codigoCarta); 
    
    printf("Nome da Cidade: ");
    // Limpa o buffer do teclado para ler strings com espaços
    getchar(); 
    fgets(carta->nomeCidade, 50, stdin);
    // Remove o '\n' que o fgets adiciona
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0; 

    printf("População (apenas números): ");
    scanf("%ld", &carta->populacao);
    
    printf("Área (km²): ");
    scanf("%lf", &carta->area);
    
    printf("PIB (em bilhões, R$): ");
    scanf("%lf", &carta->pib);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->numPontosTuristicos);
}

// --- Função para Exibir uma Carta ---
void exibirCarta(const CartaCidade *carta) {
    printf("  **%s - %s (%s)**\n", carta->nomeCidade, carta->estado, carta->codigoCarta);
    printf("    * População: %ld habitantes\n", carta->populacao);
    printf("    * Área: %.2lf km²\n", carta->area);
    printf("    * PIB: R$ %.2lf bilhões\n", carta->pib);
    printf("    * Pontos Turísticos: %d\n", carta->numPontosTuristicos);
}

// --- Função Principal ---
int main() {
    CartaCidade carta1, carta2;
    
    // 1. 📝 Cadastro de Cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // 2. 📊 Exibição de Dados Cadastrados
    printf("\n==================================\n");
    printf("    ✨ Cartas Cadastradas ✨\n");
    printf("----------------------------------\n");
    printf("Carta 1:\n");
    exibirCarta(&carta1);
    printf("\nCarta 2:\n");
    exibirCarta(&carta2);
    printf("==================================\n");

    // 3. ⚔️ Comparação de Cartas com Desempate
    
    printf("\n--- 🏆 Resultado da Comparação ---\n");
    printf("Critério Principal: População (Maior vence)\n");
    printf("Critério de Desempate: PIB (Maior vence)\n");

    // Lógica principal: População
    if (carta1.populacao > carta2.populacao) {
        // Carta 1 vence pela População
        printf("VENCEDORA: **Carta 1 (%s)**. Venceu pela População (%ld).\n", 
               carta1.nomeCidade, carta1.populacao);
    } else if (carta2.populacao > carta1.populacao) {
        // Carta 2 vence pela População
        printf("VENCEDORA: **Carta 2 (%s)**. Venceu pela População (%ld).\n", 
               carta2.nomeCidade, carta2.populacao);
    } else {
        // HOUVE EMPATE NA POPULAÇÃO -> Entra a LÓGICA DE DESEMPATE
        printf("⚠️ EMPATE na População (%ld). Iniciando desempate por PIB...\n", carta1.populacao);
        
        // Lógica de desempate: PIB (Aninhada)
        // Usa carta1.pib e carta2.pib (correto)
        if (carta1.pib > carta2.pib) {
            // Carta 1 vence pelo PIB
            printf("VENCEDORA: **Carta 1 (%s)**. Venceu no desempate pelo PIB (R$ %.2lf bi).\n", 
                   carta1.nomeCidade, carta1.pib);
        } else if (carta2.pib > carta1.pib) {
            // Carta 2 vence pelo PIB
            printf("VENCEDORA: **Carta 2 (%s)**. Venceu no desempate pelo PIB (R$ %.2lf bi).\n", 
                   carta2.nomeCidade, carta2.pib);
        } else {
            // EMPATE FINAL
            printf("⚠️ EMPATE FINAL! População e PIB são iguais. O jogo segue!\n");
        }
    }

    printf("----------------------------------\n");
    
    printf("\nCritério Extra: Densidade Populacional (Menor vence)\n");
    
    double densidade1 = (double)carta1.populacao / carta1.area;
    double densidade2 = (double)carta2.populacao / carta2.area;
    
    printf("Densidade da Carta 1 (%s): %.2lf hab/km²\n", carta1.nomeCidade, densidade1);
    printf("Densidade da Carta 2 (%s): %.2lf hab/km²\n", carta2.nomeCidade, densidade2);

    if (densidade1 < densidade2) {
        printf("A **Carta 1 (%s)** venceu, com a menor densidade.\n", carta1.nomeCidade);
    } else if (densidade2 < densidade1) {
        printf("A **Carta 2 (%s)** venceu, com a menor densidade.\n", carta2.nomeCidade);
    } else {
        printf("Empate na densidade populacional.\n");
    }

   return 0; 
}