# projeto0-2024-1
# Gerenciador de Tarefas

Este é um simples gerenciador de tarefas desenvolvido em C. Ele permite que os usuários criem, visualizem, removam, exportem e salvem tarefas.

## Funcionalidades

- **Criar Tarefa**: Os usuários podem criar uma nova tarefa especificando sua prioridade, categoria e descrição.
- **Deletar Tarefa**: Os usuários podem remover uma tarefa existente com base na sua posição.
- **Listar Tarefas**: Os usuários podem visualizar todas as tarefas cadastradas, incluindo sua prioridade, categoria e descrição.
- **Exportar Tarefas**: Os usuários podem exportar todas as tarefas para um arquivo de texto simples.
- **Salvar Tarefas**: Os usuários podem salvar todas as tarefas em um arquivo binário para carregá-las posteriormente.
- **Carregar Tarefas**: Os usuários podem carregar as tarefas salvas anteriormente a partir de um arquivo binário.

### Observações

- Certifique-se de que os arquivos de tarefas sejam salvos como `tarefas.bin` no diretório do programa para que a funcionalidade de salvar e carregar tarefas funcione corretamente.
- Ao exportar tarefas para um arquivo de texto, você será solicitado a inserir o nome do arquivo. Certifique-se de inserir um nome de arquivo válido e que você tenha permissão para escrever nesse diretório.