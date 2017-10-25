# [Função Realloc]

A função realloc() serve para realocar memória e tem o seguinte protótipo:
```c
  void *realloc (void *ptr, unsigned int num);
```
A funçao modifica o tamanho da memória previamente alocada apontada por *ptr para aquele especificado por num.<br />
O valor de num pode ser maior ou menor que o original.<br />
Um ponteiro para o bloco é devolvido porque realloc() pode precisar mover o bloco para aumentar seu tamanho.<br /> 

Se isso ocorrer, o conteúdo do bloco antigo é copiado no novo bloco, e nenhuma informação é perdida. <br />
Se ptr for nulo, aloca size bytes e devolve um ponteiro; se size é zero, a memória apontada por ptr é liberada.<br /> 
Se não houver memória suficiente para a alocação, um ponteiro nulo é devolvido e o bloco original é deixado inalterado.

[Função Realloc]: http://www.cprogressivo.net/2013/10/A-funcao-realloc-realocando-memoria-dinamicamente-e-a-calloc.html
