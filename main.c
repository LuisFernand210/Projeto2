#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, exportar, salvar_binario, carregar_binario};

    Tarefa tarefas[TOTAL];
    int pos = 0;
    ERROS erro = carregar_binario(tarefas, &pos);
    if(erro != OK)
        pos = 0;

    int opcao;
    do{
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("4 - Exportar tarefas para um arquivo de texto\n");
        printf("5 - Salvar tarefas em um arquivo binario\n");
        printf("6 - Carregar tarefas de um arquivo binario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        if(opcao < 0 || opcao > 6) {
            printf("Opcao invalida\n");
            continue;
        }

        if(opcao == 0) {
            printf("Saindo...\n");
            break;
        }

        erro = fs[opcao - 1](tarefas, &pos);
        if(opcao >= 4 && opcao <= 6) {
            if(erro != OK)
                printf("Erro ao abrir o arquivo (Erro: %d). Verifique se o caminho está correto e se você tem permissão para acessá-lo.\n", erro);
            else
                printf("Operação realizada com sucesso.\n");
        }


    } while(opcao != 0);

    if(pos > 0)
        salvar_binario(tarefas, &pos);

    return 0;
}
