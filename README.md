manpagr
=======

O Manpagr é uma ferramenta para indexar, organizar e pesquisar em manpages. Ele foi feito como trabalho de implementação 2 do curso de Estrutura de Dados da UFSC.

Para compilar:
```make```
O manpagr é feito em C++11 e, portanto, necessita do GCC 4.8+ ou do clang 3.2+.

Para indexar as manpages:
```manpagr-gen <lista de arquivos de manpages>```
Serão criados os arquivos manpages.dat e manwords.dat, contendo os dados em forma reduzida.

Para pesquisar pelo conteúdo de uma manpage:
```manpagr --page <nome da manpage>```

Para pesquisar uma manpage a partir de um ou mais termos:
```manpagr --terms <termos para pesquisar>```
