# 🚀 Sistema de Gestão de Agência Espacial

Este é um projeto acadêmico desenvolvido em C++ para simular o sistema de gerenciamento de voos e tripulações de uma Agência Espacial. O sistema opera via linha de comando, processando instruções em lote para cadastrar astronautas, planejar voos, gerenciar embarques e registrar o desfecho das missões espaciais. Além disso, foi feito na por mim mesmo, não pela IA👍.

## ⚙️ Funcionalidades do Sistema

O sistema é capaz de ler e interpretar os seguintes comandos:

* **Gestão de Pessoas:**
  * `CADASTRAR_ASTRONAUTA [CPF] [IDADE] [NOME]`: Registra um novo astronauta.
* **Gestão de Missões:**
  * `CADASTRAR_VOO [CODIGO]`: Cria um novo voo com o status inicial de "planejado".
  * `ADICIONAR_ASTRONAUTA [CPF] [CODIGO_VOO]`: Aloca um astronauta a um voo (apenas se o voo estiver planejado e o astronauta vivo/disponível).
  * `REMOVER_ASTRONAUTA [CPF] [CODIGO_VOO]`: Retira um astronauta da tripulação de um voo em planejamento.
* **Ciclo de Vida do Voo:**
  * `LANCAR_VOO [CODIGO_VOO]`: Altera o status para "em curso".
  * `FINALIZAR_VOO [CODIGO_VOO]`: Pouso bem-sucedido. Astronautas voltam a ficar disponíveis.
  * `EXPLODIR_VOO [CODIGO_VOO]`: Falha catastrófica. O voo é finalizado com explosão e os astronautas são registrados como mortos.
* **Relatórios:**
  * `LISTAR_VOOS`: Exibe todos os voos agrupados por status.
  * `LISTAR_MORTOS`: Exibe o histórico de todos os astronautas que faleceram.
  * `FIM`: Encerra a execução do programa.

## 🚀 Como Executar o Projeto

O programa foi projetado para receber comandos através da entrada padrão (`stdin`). A maneira correta de executá-lo é compilando o código-fonte e fazendo com que ele consuma um arquivo de texto (`.txt`) contendo a lista de eventos.

### Passo a Passo

1. **Baixe os arquivos:**
   Faça o download da pasta deste projeto.

2. **Prepare o arquivo de eventos:**
   Certifique-se de que o arquivo `eventos.txt` (contendo os comandos que serão lidos pelo sistema) está localizado na pasta **data**.

3. **Abra o Terminal:**
   Abra o prompt de comando ou terminal do seu sistema operacional e navegue até a pasta geral que contém as pastas do projeto.

4. **Compile o código-fonte:**
   No terminal, execute o seguinte comando usando o compilador C++ (`g++`):
   ```bash
   g++ src/main.cpp -o bin/sistema
5. **Execute o sistema:**
   No terminal, execute o seguinte comando para executar o sistema consumindo um arquivo .txt com os comandos:
   ```bash
   ./bin/sistema < data/eventos.txt
