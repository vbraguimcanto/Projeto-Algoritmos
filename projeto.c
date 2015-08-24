/*
Victor Hugo Braguim Canto
Bacharelado em Ciência da Computação - UTFPR
Disciplina: Algoritmos - P3
RA: 1429388
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct rota{
    char companhiaaerea[50], origem[50], destino[50], data[11], horasaida[7], horachegada[7];
}rota;
void menu(void)
{
    printf("\n===================================================\n");
    printf(" Sistema de Busca e Cadastros de Viagens v1.0 BETA\n\n");
    printf(" Universidade Tecnologica Federal do Parana - UTFPR\n\n");
    printf("  Sistema Desenvolvido por Victor Hugo B. Canto\n");
    printf("===================================================\n\n");
    printf("1 - Incluir \n");
    printf("2 - Consultar \n");
    printf("3 - Alterar \n");
    printf("4 - Excluir\n");
    printf("5 - Sair \n\n");
     printf("---------------------------------------------------\n");
}
void incluir(rota *viagens, int n, char *op)
{
    printf("\n\nDigite a companhia:       ");
    scanf("\n%[^\n]s", &viagens[n].companhiaaerea);
    printf("Local de Saida:           ");
    scanf("\n%[^\n]s", &viagens[n].origem);
    printf("Local de Destino:         ");
    scanf("\n%[^\n]s", &viagens[n].destino);
    printf("Data (XX/YY/ZZZZ):        ");
    scanf("%s", &viagens[n].data);
    printf("Horario de Saida(XX:YY):  ");
    scanf("%s", &viagens[n].horasaida);
    printf("Horario de Chegada(XX:YY):");
    scanf("%s", &viagens[n].horachegada);
    printf("\n\nVoo Cadastrado !\n\n\n  ");
}
void imprimir (rota *viagens, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n\nCOMPANHIA:   %s", viagens[i].companhiaaerea);
        printf("\nORIGEM:      %s", viagens[i].origem);
        printf("\nDESTINO:     %s", viagens[i].destino);
        printf("\nDATA:        %s", viagens[i].data);
        printf("\nHORA SAIDA:  %s", viagens[i].horasaida);
        printf("\nHORA CHEGADA:%s", viagens[i].horachegada);
        printf("\nCODIGO:      %d", i+1);
    }
}
void pesquisa(rota *viagens, char *origem, char *destino, char*x)
{
    int i, n=100, flag=0;
    for(i=0;i<n;i++)
    {
        if((strcmp(origem, viagens[i].origem) && (strcmp(destino, viagens[i].destino)) && (strcmp(x, viagens[i].data)))==0)
        {
            flag = flag + 1;
            printf("\n\nCOMPANHIA:   %s", viagens[i].companhiaaerea);
            printf("\nORIGEM:      %s", viagens[i].origem);
            printf("\nDESTINO:     %s", viagens[i].destino);
            printf("\nDATA:        %s", viagens[i].data);
            printf("\nHORA SAIDA:  %s", viagens[i].horasaida);
            printf("\nHORA CHEGADA:%s\n\n", viagens[i].horachegada);
        }
    }
    if(flag == 0)
    {
        printf("\n\n\nNenhum voo foi encontrado!\n");
    }
}
void altera(rota *viagens, int codigo)
{

    printf("\n\nDigite a companhia:     ");
    scanf("\n%[^\n]s", &viagens[codigo].companhiaaerea);
    printf("Local de Saida:           ");
    scanf("\n%[^\n]s", &viagens[codigo].origem);
    printf("Local de Destino:         ");
    scanf("\n%[^\n]s", &viagens[codigo].destino);
    printf("Data (XX/YY/ZZZZ):        ");
    scanf("%s", &viagens[codigo].data);
    printf("Horario de Saida(XX:YY):  ");
    scanf("%s", &viagens[codigo].horasaida);
    printf("Horario de Chegada(XX:YY):");
    scanf("%s", &viagens[codigo].horachegada);
    printf("\n\nVoo Alterado !\n");

}
void excluir(rota *viagens, int codigo, int qtd)
{
    strcpy(viagens[codigo].companhiaaerea, viagens[qtd-1].companhiaaerea);
    strcpy(viagens[codigo].origem, viagens[qtd-1].origem);
    strcpy(viagens[codigo].destino, viagens[qtd-1].destino);
    strcpy(viagens[codigo].data, viagens[qtd-1].data);
    strcpy(viagens[codigo].horasaida, viagens[qtd-1].horasaida);
    strcpy(viagens[codigo].horachegada, viagens[qtd-1].horachegada);
    strcpy(viagens[qtd-1].companhiaaerea," ");
    strcpy(viagens[qtd-1].origem," ");
    strcpy(viagens[qtd-1].destino," ");
    strcpy(viagens[qtd-1].data,"  ");
    strcpy(viagens[qtd-1].horasaida," ");
    strcpy(viagens[qtd-1].horachegada," ");
}
int main()
{
    int qtd=0, op, codigo;
    char origem[100], destino[100], data[10];
    rota viagens[100];
    while(op != 100000)
    {
    menu();
    printf("Digite a opcao: ");
    scanf("%d", &op);
    switch(op)
        {
            case 1:

            incluir(viagens, qtd, op);
            qtd++;
            break;
            case 2:
            printf("\nLocal de Saida: ");
            scanf("\n%[^\n]s", &origem);
            printf("Local de Destino: ");
            scanf("\n%[^\n]s", &destino);
            printf("Data (XX/YY/ZZZZ):");
            scanf("%s", &data);
            pesquisa(viagens, origem, destino, data);
            break;
            case 3:
            if(qtd == 0)
            {
                printf("\n\nNenhum voo cadastrado!\n\n");
            }
            else
            {
                imprimir(viagens, qtd);
                printf("\n\nDigite o codigo para alterar: ");
                scanf("%d", &codigo);
                codigo--;
                altera(viagens, codigo);
            }
            break;
            case 4:
            imprimir(viagens, qtd);
            printf("\n\nDigite o codigo para excluir: ");
            scanf("%d", &codigo);
            codigo--;
            excluir(viagens, codigo, qtd);
            qtd--;
            printf("\n\nVoo Excluido!");
            break;
            case 5: printf("\n\nObrigado por utilizar nosso sistema. Ate Mais !\n\n");
            return 0;
            break;
            default:
            printf("\n\nOpcao Invalida!\n\n");
        }
    }
    return 0;
}
