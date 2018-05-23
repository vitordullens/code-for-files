# To do
1. O que é uma lista invertida? Quais são suas vantagens?
2. Por que se usa chaves secundárias?
3. Por que é possível eliminar um registro apenas do índice primário, e não
do secundário?
4. Faça um programa que faça os seguintes procedimentos:
    - Peça para o usuário preencher um arquivo o qual vai conter no
mínimo 20 registros e cada registro deve ser composto no mínimo
de 10 campos.
    - A partir desse arquivo criado e usando dois desses campos crie a
chave primaria.
    - Crie um índice simples com essa chave primaria.
    - Faça a busca de um registro nesse arquivo de índices simples.
    - Opcional : crie chaves secundarias e usando essas chaves buscar a
chave primária.

# Answers 
1. Listas invertidas são uma maneira de organizar o arquivo de índices secundários de maneira que cada registro contenho a chave secundaria e um ponteiro para uma lista de referência.
    - Vantagens:
        - O arquivo de índices secundário só é rearranjado quando um novo compositor é adicionado ou o nome de um compositor é modificado.
        - Adicionar ou excluir gravações afeta 1 arquivo.
        - Excluir todas as gravações para um indice é facil.
        - Rearranjar o arquivo de índices secundário é mais rápido, pois ele está
        menor.

2. ...