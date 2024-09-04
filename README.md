# Simulação de Empilhadeira
<h3>
    Alunos: Divaldo Verçosa e Ludmila Barbosa da Silva<br>
Sistemas de Informações - 3º Período<br>
Professora: Cledja Rolim
</h3>

<p align="justify">
  Este projeto é um sistema desenvolvido na linguagem C para gerenciar o armazenamento de caixas em um depósito utilizando pilhas. O sistema permite inserir, consultar e remover caixas de diferentes pesos, garantindo que caixas mais pesadas nunca sejam empilhadas sobre caixas mais leves
</p>

## Funcionalidades Principais

- **Inserção de Caixas:** Permite inserir caixas com identificação, peso e descrição, organizando-as nas pilhas de forma que caixas mais pesadas não fiquem sobre as mais leves.
- **Consulta de Caixas:** Permite consultar a existência e os detalhes de uma caixa específica no depósito.
- **Remoção de Caixas:** Permite remover uma caixa específica da pilha principal, reorganizando as outras caixas conforme necessário.
- **Movimentação entre Pilhas:** As caixas podem ser movidas entre as pilhas para garantir que as regras de empilhamento sejam seguidas.

## Estrutura do projeto

<p align="jutsify">
  O projeto está organizado em diferentes diretórios e arquivos, cada um responsável por uma parte específica do sistema:
</p>

### Diretórios e sub-diretórios

### Principais arquivos do projeto

## Estrutura de Dados

No projeto, foi utilizada principalmente a estruturas de dados: **pilhas**.

- **Pilhas**: As caixas são armazenadas em pilhas, onde apenas a última inserida pode ser removida sem reorganizar as outras caixas. Utilizadas para garantir a regra de empilhamento (caixas mais pesadas nunca ficam sobre caixas mais leves). 

## Funcionamento do menu

<p align="justify">
  O sistema oferece um menu principal que vai permitir que o usuário realize diversas operações essenciais. Segue abaixo uma descrição de cada uma dessas funcionalidades disponíveis:
</p>

1. **`inserirCaixa`**: Permite que o usuário insira uma nova caixa no sistema, informando o ID, peso e descrição. As caixas serão empilhadas respeitando as regras de peso;

2. **`consultarCaixa`**: Permite que o usuário consulte uma caixa específica pelo ID, mostrando os detalhes da caixa;

3. **`removerCaixa`**: Permite que o usuário remova uma caixa específica da pilha principal, reorganizando as outras caixas conforme necessário;

4. **`exibirPilha`**: Mostra todas as caixas atualmente empilhadas na pilha principal;

5. **`sair`**: Finaliza o programa.

## Como Rodar o Projeto

### Pré-requisitos

- GCC (GNU Compiler Collection)
- IDE de preferência (VSCode, Clion...)

### Passos para Compilar e Executar

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/ludmilabss/terceira-nota-cledja.git
   cd terceira-nota-cledja
   ```

2. **Compilação:**

   ```bash
   gcc src/cli/main.c src/app/pilha.c src/app/empilhadeira.c src/cli/menu.c -I include -o empilhadeira
   ```

3. **Rodar o executável:**

   ```bash
   ./empilhadeira
  