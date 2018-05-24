# To do
1. O que é uma lista invertida? Quais são suas vantagens?
2. Por que se usa chaves secundárias?
3. Por que é possível eliminar um registro apenas do índice primário, e não
do secundário?
4. Faça um programa que faça os seguintes procedimentos:
    - Peça para o usuário preencher um arquivo o qual vai conter no mínimo 20 registros e cada registro deve ser composto no mínimo
de 10 campos.
    - A partir desse arquivo criado e usando dois desses campos crie a chave primaria.
    - Crie um índice simples com essa chave primaria.
    - Faça a busca de um registro nesse arquivo de índices simples.
    - Opcional : crie chaves secundarias e usando essas chaves buscar a chave primária.

# Answers 
1. Listas invertidas são uma maneira de organizar o arquivo mapeando termos às suas ocorrências em um documento ou conjunto de documentos, de maneira que cada registro contenha a chave secundaria e um ponteiro para uma lista de referência.
    - Vantagens:
        - Rearranjar o arquivo de índices secundário é mais rápido, pois ele está menor;
        - Buscas mais precisas e rápidas;
        - Evita cópias de chaves secundárias.
    - Desvantagens:
        - A lista de referência terá um limite de tamanho, e podemos ter mais registros para incluir na lista de referência;
        - Podemos ter fragmentação interna após muitas inclusões, deleções e adaptações;
        - Talvez algumas das referências apontadas pela lista de referência não são mais válidas.

2. As chaves secundárias são utilizadas a fim de melhorar o acesso as infomações buscadas. Um exemplo dessa situação é a biblioteca, cada livro tem um código, porém normalmente não é pesquisado o codigo do livro, e sim seu assunto, título, etc (i.e. uma chave secundaria). A partir da chave secundária se encontra o código e por fim o livro. 

3. Pois o indice secundario é apenas uma referencia ao primário, fazendo com que ele possa armazenar mais chaves primárias. Seguindo o exemplo da biblioteca, varios livros podem possuir o mesmo assunto. Com isso, é possível apenas remover o arquivo do indice primário e deixar sua referencia no indice secundario, ao invez de ter que atualizar todos os índices ligados a mesma chave primaria. Ao tentar se acessar a chave primária inválida não a acharemos no arquivo indice principal, simplesmente.   
Um problema disso é que podemos ter muitas referências inválidas no arquivo índice secundário. Essas referências precisam ser tratadas.
### notes
- 1 e 3 podem ser complementados, acho que não saquei direito algumas coisas.