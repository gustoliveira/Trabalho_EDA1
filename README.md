### Estrutura de Dados e Algoritmos
Trabalho relativo a avaliação de nota na disciplina Estrutura de Dados e Algoritmos - MATA40 da UFBA aplicado pelo professor Roberto Freitas Parente, no semestre 2019.2.

### Descrição
O objetivo final é desenvolver uma simulação de uma agência de banco simplificada. Tal simulação gerencia o saldo dos clientes envolvidos na simulação através de saques, transferências e depósitos realizados nos guichês da agência.

### Etapas
O trabalho foi divido em quatros fases:

* Implementação inicial dos guichês de atendimentos utilizando __pilhas de alocação encadeada__ e impressão do relatório parcial de cada guichê.
* Implementação da fila de clientes utilizando __filas de alocação sequêncial circular com tamanho estático__, impressão do relatório final utilizando __lista ordenada de alocação encadeada sem cabeça__ e integração com os guichês de atendimento.
* Implementação dos relatórios diários utilizando um __vetor de ponteiros para pilhas__, modularização aplicando o conceito de __TAD__, arquivos compilados com auxilio do __Makefile__. Algumas estruturas foram alteradas, a fila de clientes foi refeita com uma __fila de alocação sequêncial circular com tamanho piso(sqrt(D))__, lista de relatório final foi refeita com uma __lista ordenada de alocação duplamente encadeada circular__.
* Criando operações do banco com uma __árvore AVL__

### Para Rodar
#### Compilação
Utiliza-se o comando: __gcc -Wall -Wextra -Werror -Wpedantic__:
* __-Wall__: Ativa todos warmings sobre construção que alguns usuários consideram questionaveis
* __-Wextra__: Ativa diversas outras flags para detecção de erros
* __-Werror__: Transforma todos Warmings em erros
* __-Wpedantic__: Rejeita todos os programas que não seguem a ISO C

#### Teste de alocação de memória
Utiliza-se o programa __Valgrind__:
* Para instalar no linux, cole o comando __apt-get install valgrind__ no terminal ou entre no [site do desenvolvedor](http://valgrind.org/downloads/?src=www.discoversdk.com)
* Para rodar, apenas execute o comando __valgrind --tool=memcheck --leak-check=yes ./a.out__ no terminal e cole a entrada
* Qualquer duvida, consulte a [documentação](http://valgrind.org/docs/) do desenvolvedor

#### Comparar saída:
Utiliza-se o diff:
* Compile o programa, e gere a saída em um arquivo, utilizando o comando: __./a.out > TesteSaida.txt__, isto irá gerar um arquivo chamado TesteSaida.txt no diretório
* Utilize o comando __diff saida.txt TesteSaida.txt__, tal que, saida.txt é o arquivo contendo a saída oficial disponibilizada pelo professor, e TesteSaida.txt é um arquivo contendo a saída gerada pelo seu programa, caso ambas sejam iguais, não irá gerar nada, caso o contrário, ele irá acusar no terminal as diferenças entre ambos os arquivos
* Outra possibilidade, é utilizando sites com essa função, recomenda-se o site [Diffchecker](https://www.diffchecker.com/), neste caso é só colar a saída oficial do lado esquerdo, e a sua saída no lado direito, ele irá indicar de maneira mais visual quais as diferenças entre ambos as saídas

#### Observação:
* Note que para as fases 3 e 4, utilizou-se TAD para modularização dos códigos, e Makefile para facilitar a compilação
* Para compilar utilizando Makefile, utiliza-se o comando __make__, contudo, para evitar qualquer tipo de problema, digite __make clear && make__, isto apagará os arquivos binários e gerará novos.