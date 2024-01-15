//Pedro Henrique Karpinski Silva
//RA 11202130643

#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct aluno {
    char nome[MAX];
    Data data_nascimento;
    int ra;
} Aluno;

void cria_cadastro(Aluno a[], int n) {
    printf("---------------------------------------\n");
    printf("Inicio do cadastro\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("Aluno %d\n", i+1);
        for (int j = 0; j < 3; j++)
            if (j == 0) {
                printf("RA: ");
                scanf("%d", &a[i].ra);
                getchar();
            }
            else if (j == 1) {
                printf("Nome: ");
                fgets(a[i].nome, MAX, stdin);
            }
            else if (j == 2) {
                printf("Data de nascimento\n");
                printf("Dia: ");
                scanf("%d", &a[i].data_nascimento.dia);
                printf("Mes: ");
                scanf("%d", &a[i].data_nascimento.mes);
                printf("Ano: ");
                scanf("%d", &a[i].data_nascimento.ano);
                getchar();
            }
        printf("---------------------------------------\n");
    }
}

int faz_parte(char palavra[MAX], char frase[MAX]) {
    int tam_palavra = strlen(palavra);
    int tam_frase = strlen(frase);
    int contador = 0;
    for (int i = 0; i < tam_frase; i++) {
        if (frase[i] == palavra[0]) {
            if (i == 0)
                for (int j = i; j < i + tam_palavra; j++) {
                if (frase[j] == palavra[j - i])
                    contador++;
                else if (frase[j] == 32 && palavra[j - i] == 10)
                    contador++;
                else {
                    contador = 0;
                    break;
                }
            }
            else
                if (frase[i-1] == ' ')
                for (int j = i; j < i + tam_palavra; j++) {
                    if (frase[j] == palavra[j - i])
                        contador++;
                    else if (frase[j] == 32 && palavra[j - i] == 10)
                        contador++;
                    else {
                        contador = 0;
                        break;
                    }
            }
        if (contador == tam_palavra)    
            break;
        }
    }
    if (contador == tam_palavra)
        return 1;
    else
        return 0;
}

void busca_aluno_nome(Aluno a[], int n, char nome[MAX]) {
    int contador = 0;
    printf("\n");
    for (int i = 0; i < n; i++)
        if (faz_parte(nome, a[i].nome) == 1) {
            printf("%s", a[i].nome);
            contador++;
        }
    if (contador == 0)
        printf("Nenhum aluno com esse nome\n");
}

void busca_aluno_data(Data d1, Data d2, Aluno a[], int n) {
    if (d1.ano > d2.ano)
        for (int i = d2.ano; i <= d1.ano; i++){
            for (int j = 0; j < n; j++)
                if (a[j].data_nascimento.ano == i && a[j].data_nascimento.ano != d2.ano && a[j].data_nascimento.ano && d1.ano)
                    printf("%s", a[j].nome);
                else if (a[j].data_nascimento.ano == d2.ano) {
                    if (a[j].data_nascimento.mes > d2.mes)
                        printf("%s", a[j].nome);
                    else if (a[j].data_nascimento.ano == d2.mes)
                        if (a[j].data_nascimento.dia > d2.dia)
                            printf("%s", a[j].nome);
                }
                else if (a[j].data_nascimento.ano == d1.ano) {
                    if (a[j].data_nascimento.mes < d1.mes)
                        printf("%s", a[j].nome);
                    else if (a[j].data_nascimento.ano == d1.mes)
                        if (a[j].data_nascimento.dia < d1.dia)
                            printf("%s", a[j].nome);
                }
        }
    else if (d2.ano > d1.ano)
        for (int i = d1.ano; i <= d2.ano; i++){
            for (int j = 0; j < n; j++)
                if (a[j].data_nascimento.ano == i && a[j].data_nascimento.ano != d1.ano && a[j].data_nascimento.ano && d2.ano)
                    printf("%s", a[j].nome);
                else if (a[j].data_nascimento.ano == d1.ano) {
                    if (a[j].data_nascimento.mes > d1.mes)
                        printf("%s", a[j].nome);
                    else if (a[j].data_nascimento.ano == d1.mes)
                        if (a[j].data_nascimento.dia > d1.dia)
                            printf("%s", a[j].nome);
                }
                else if (a[j].data_nascimento.ano == d2.ano) {
                    if (a[j].data_nascimento.mes < d2.mes)
                        printf("%s", a[j].nome);
                    else if (a[j].data_nascimento.ano == d2.mes)
                        if (a[j].data_nascimento.dia < d2.dia)
                            printf("%s", a[j].nome);
                }
            }
}

int main() {
    Aluno alunos[MAX];
    int n_alunos;
    char nome[MAX];
    int dec_nome;
    printf("Digite a quantidade de alunos que voce quer cadastrar\n");
    scanf("%d", &n_alunos);
    printf("Para cadastrar um aluno, informe o RA, o nome e a data de nascimento do aluno respectivamente\n");
    cria_cadastro(alunos, n_alunos);
    printf("Digite 1 se quer buscar alunos por nome\nDigite 2 se quer buscar alunos por data\nDigite 3 se quer sair\n");
    scanf("%d", &dec_nome);
    if (dec_nome == 1) {
        printf("Digite um nome para buscar na lista de alunos\n");
        fgets(nome, MAX, stdin);
        busca_aluno_nome(alunos, n_alunos, nome);
    }
    else if (dec_nome == 2) {
        printf("Digite duas datas para buscar alunos nascidos entre essas datas\n");
        Data data1;
        printf("Data 1\n");
        printf("Dia: ");
        scanf("%d", &data1.dia);
        printf("Mes: ");
        scanf("%d", &data1.mes);
        printf("Ano: ");
        scanf("%d", &data1.ano);
        Data data2;
        printf("Data 2\n");
        printf("Dia: ");
        scanf("%d", &data2.dia);
        printf("Mes: ");
        scanf("%d", &data2.mes);
        printf("Ano: ");
        scanf("%d", &data2.ano);
        busca_aluno_data(data1, data2, alunos, n_alunos);
    }
    else if (dec_nome == 3)
        printf("SAIU");
}