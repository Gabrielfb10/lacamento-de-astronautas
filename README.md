# 🚀 Sistema de Gestão de Agência Espacial

Este é um projeto acadêmico desenvolvido em C++ para simular o sistema de gerenciamento de voos e tripulações de uma Agência Espacial. O sistema opera via linha de comando, processando instruções em lote para cadastrar astronautas, planejar voos, gerenciar embarques e registrar o desfecho das missões espaciais.

## 🛠️ Conceitos e Tecnologias Aplicadas

Durante o desenvolvimento deste sistema, foram aplicados diversos conceitos fundamentais de Ciência da Computação e Engenharia de Software:
* **Linguagem:** C++
* **Orientação a Objetos (POO):** Modelagem do sistema utilizando classes (`Astronauta` e `Voo`) para encapsular propriedades e comportamentos.
* **Estruturas de Dados Dinâmicas:** Uso extensivo de `std::vector` para gerenciar coleções mutáveis de dados na memória.
* **Gerenciamento de Memória:** Uso de passagem por referência (`&`) nas funções para otimizar o desempenho e evitar cópias desnecessárias de objetos grandes.
* **Validação de Dados e Cláusulas de Guarda (Early Return):** Implementação de checagens rigorosas (ex: CPF contendo apenas 11 dígitos numéricos, impedimento de embarque de astronautas mortos ou em outras missões).

## ⚙️ Funcionalidades do Sistema

O sistema é capaz de ler e interpretar os seguintes comandos:

* **Gestão de Pessoas:**
  * `CADASTRAR_ASTRONAUTA [CPF] [IDADE] [NOME]`: Registra um novo astronauta, validando o formato do CPF e impedindo duplicidades.
* **Gestão de Missões:**
  * `CADASTRAR_VOO [CODIGO]`: Cria um novo voo com o status inicial de "planejado".
  * `ADICIONAR_ASTRONAUTA [CPF] [CODIGO_VOO]`: Aloca um astronauta a um voo (apenas se o voo estiver planejado e o astronauta vivo/disponível).
  * `REMOVER_ASTRONAUTA [CPF] [CODIGO_VOO]`: Retira um astronauta da tripulação de um voo em planejamento.
* **Ciclo de Vida do Voo:**
  * `LANCAR_VOO [CODIGO_VOO]`: Altera o status do voo para "em curso". Astronautas a bordo ficam indisponíveis para outros voos.
  * `FINALIZAR_VOO [CODIGO_VOO]`: Pouso bem-sucedido. Os astronautas voltam a ficar disponíveis para novas missões.
  * `EXPLODIR_VOO [CODIGO_VOO]`: Falha catastrófica. O voo é finalizado com explosão e todos os astronautas a bordo são registrados como mortos.
* **Relatórios:**
  * `LISTAR_VOOS`: Exibe todos os voos agrupados por status (planejado, em curso, finalizado com sucesso, finalizado com explosão), detalhando seus tripulantes.
  * `LISTAR_MORTOS`: Exibe o histórico de todos os astronautas que faleceram em missões, informando em quais voos eles estavam.
  * `FIM`: Encerra a execução do programa.

## 🚀 Como Executar o Projeto

O programa foi projetado para receber comandos através da entrada padrão (`stdin`). A maneira mais eficiente de testá-lo é utilizando o redirecionamento de um arquivo de texto contendo os comandos.

### Pré-requisitos
* Um compilador C++ instalado (como `g++` via MinGW no Windows, ou nativo no Linux/Mac).

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git](https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git)
   cd NOME_DO_REPOSITORIO
