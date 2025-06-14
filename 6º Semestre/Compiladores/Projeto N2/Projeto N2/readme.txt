README - Projeto N2 Compiladores
=================================

Autores:
--------
- Cleverson Pereira da Silva - RA: 10391119  
- Felipe Nakandakari dos Santos - RA: 1039516

Descrição:
----------
Compilador para a linguagem TINY-C que faz:
1. Análise léxica - Parte 1
2. Análise sintática - Parte 1
3. Análise semântica - Parte 2
4. Geração de código intermediário (MEPA) - Parte 2

O que o programa faz:
----------------------
- Verifica se o código está correto (sintaxe e semântica)
- Cria uma tabela de variáveis (tabela de símbolos)
- Gera instruções da linguagem MEPA

Como funciona:
--------------
  1. Tokens (palavras, números, símbolos)
  2. Estrutura do código (gramática)
  3. Declarações e usos de variáveis
- Gera código intermediário com comandos como: `CRCT`, `CRVL`, `ARMZ`, `DSVF`, `IMPR`, `PARA`, etc.

Como compilar:
--------------
gcc -g -Og -Wall compilador.c -o compilador