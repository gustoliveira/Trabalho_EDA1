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
