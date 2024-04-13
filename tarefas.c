#include <stdio.h>
#include <string.h>
#include "tarefas.h"

void strip_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

ERROS criar(Tarefa tarefas[], int *pos){
    if(*pos >= TOTAL)
        return MAX_TAREFA;

    int prioridade;
    do {
        printf("Entre com a prioridade (1-10): ");
        scanf("%d", &prioridade);
        clearBuffer();
    } while (prioridade < 1 || prioridade > 10);

    tarefas[*pos].prioridade = prioridade;

    char categoria[100];
    do {
        printf("Entre com a categoria: ");
        fgets(tarefas[*pos].categoria, CATEGORIA_LEN, stdin);
        strip_newline(tarefas[*pos].categoria);
    } while (strlen(tarefas[*pos].categoria) == 0);

    char descricao[300];
    do {
        printf("Entre com a descricao: ");
        fgets(tarefas[*pos].descricao, DESCRICAO_LEN, stdin);
        strip_newline(tarefas[*pos].descricao);
    } while (strlen(tarefas[*pos].descricao) == 0);

    *pos = *pos + 1;

    return OK;
}

ERROS deletar(Tarefa tarefas[], int *pos){
    // teste se existem tarefas
    if(*pos == 0)
        return SEM_TAREFAS;

    // verifica se a tarefa escolhida existe
    int pos_deletar;
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar);
    pos_deletar--; // garantir posicao certa no array
    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos){
    if(*pos == 0)
        return SEM_TAREFAS;

    clearBuffer();

    printf("Digite a categoria para listar tarefas (deixe em branco para todas): ");
    fgets(tarefas[*pos].categoria, CATEGORIA_LEN, stdin);
    strip_newline(tarefas[*pos].categoria);

    int found = 0;
    for(int i = 0; i < *pos; i++){
        if (tarefas[*pos].categoria[0] == '\0' || strcmp(tarefas[i].categoria, tarefas[*pos].categoria) == 0) {
            printf("Pos: %d\t", i+1);
            printf("Prioridade: %d\t", tarefas[i].prioridade);
            printf("Categoria: %s\t", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            found = 1;
        }
    }

    if (!found)
        printf("Nenhuma tarefa encontrada para a categoria '%s'\n", tarefas[*pos].categoria);

    return OK;
}

ERROS exportar(Tarefa tarefas[], int *pos) {
    char filename[256];
    printf("Digite o nome do arquivo de texto para exportar as tarefas: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return ABRIR;
    }

    for (int i = 0; i < *pos; i++) {
        fprintf(file, "Tarefa %d: Prioridade %d, Categoria %s, Descricao %s\n",
                i + 1, tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].descricao);
    }

    fclose(file);
    return OK;
}


ERROS salvar_binario(Tarefa tarefas[], int *pos) {
    FILE *arquivo = fopen("tarefas.bin", "wb");
    if (arquivo == NULL) {
        return ABRIR;
    }

    int qtd = fwrite(tarefas, sizeof(Tarefa), *pos, arquivo);
    if (qtd != *pos) {
        fclose(arquivo);
        return ESCREVER;
    }

    fclose(arquivo);
    return OK;
}

ERROS carregar_binario(Tarefa tarefas[], int *pos) {
    FILE *arquivo = fopen("tarefas.bin", "rb");
    if (arquivo == NULL) {
        return ABRIR;
    }

    int qtd = fread(tarefas, sizeof(Tarefa), TOTAL, arquivo);
    if (qtd < 0) {
        fclose(arquivo);
        return LER;
    }

    *pos = qtd;
    fclose(arquivo);
    return OK;
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}