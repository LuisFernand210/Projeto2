#define TOTAL 100
#define CATEGORIA_LEN 100
#define DESCRICAO_LEN 300

typedef struct {
    int prioridade;
    char descricao[DESCRICAO_LEN];
    char categoria[CATEGORIA_LEN];
} Tarefa;


typedef enum {OK, MAX_TAREFA, SEM_TAREFAS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

typedef ERROS (*funcao)(Tarefa[], int*);

ERROS criar(Tarefa tarefas[], int *pos);
ERROS deletar(Tarefa tarefas[], int *pos);
ERROS listar(Tarefa tarefas[], int *pos);
ERROS exportar(Tarefa tarefas[], int *pos);
ERROS salvar_binario(Tarefa tarefas[], int *pos);
ERROS carregar_binario(Tarefa tarefas[], int *pos);

void clearBuffer();