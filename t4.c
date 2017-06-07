//Gustavo farias e mateus pasqualini

#include <stdio.h>
#include <stdlib.h>

enum tiposCasa {
    alvenaria = 1,
    madeira = 2,
    mista = 3
};

typedef struct {
    enum tiposCasa tipo;
    int metragemTotal;
} construcao;

typedef struct {
    construcao  casa;
    int largura;
    int comprimento;
    double valorCondominio;
} terreno;

void precocond(terreno *t){
    int i, metroq=0;

    metroq = t -> largura * t -> comprimento;//para achar a área do terreno


    if (t->casa.tipo == 1)
        t->casa.metragemTotal= t->casa.metragemTotal * 1.50;
    else if (t->casa.tipo == 2)
        t->casa.metragemTotal= t->casa.metragemTotal * 1.20;
        else if (t->casa.tipo == 3)
            t->casa.metragemTotal= t->casa.metragemTotal * 1.30;

    t->valorCondominio = metroq + t->casa.metragemTotal;
    }
void funcaoterreno(terreno cond[10]){
    FILE * saida;
    saida = fopen("t4.txt","w");
    int i;
    for(i=0;i<10;i++){
            fprintf(saida,"O tipo da casa %d:%d\n\n",i+1,cond[i].casa.tipo);
            fprintf(saida,"Metragem total da casa %d:%d\n\n",i+1,cond[i].casa.metragemTotal);
            fprintf(saida,"Largura da casa %d:%d\n\n",i+1,cond[i].largura);
            fprintf(saida,"Comprimento da casa %d:%d\n\n",i+1,cond[i].comprimento);
            fprintf(saida,"Valor do condominio da casa %d:%f\n\n",i+1,cond[i].valorCondominio);
    }
}
int main(void){
    int i;
    terreno condominio[10];
    for(i=0; i<10 ; i++){
    printf("Cadastrando casa %d:\n", i+1);
        printf("Informe o tipo da casa - [1]Alvenaria, [2]Madeira, [3]Mista: ");
        scanf("%d", &condominio[i].casa.tipo);
        if(condominio[i].casa.tipo < 1 || condominio[i].casa.tipo > 3){
            printf("Tipo invalido. Reiniciando o cadastro da casa %d...\n", i+1);
            i--;
        }
    }
    for(i=0;i<10;i++){
        printf("Informe a largura da casa %d:\n", i+1);
        scanf("%d",&condominio[i].largura);
        printf("Informe o comprimento da casa %d: \n", i+1);
        scanf("%d",&condominio[i].comprimento);

        printf("informe a metragem total da casa %d:\n",i+1);
        scanf("%d",&condominio[i].casa.metragemTotal);


        }
        for (i=0 ; i<10 ; i++){
            precocond(&condominio[i]);



    }
    funcaoterreno(condominio);
    return 0;
}
