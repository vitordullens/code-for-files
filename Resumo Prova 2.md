# Resumo Prova 2 OA
## Acesso a arquivos VS Organização de Arquivos
- Pode se organizar um arquivo em registros de 2 modos:
	- Tamanho fixo;
	- Tamanho variável;
- Já o acesso pode ser feito:
	- Diretamente;
	- Sequencialmente;
- Acesso Direto:
	- Arquivos de tamanho fixo:
		- É imediato e utiliza a função ```fseek()```;
	- Arquivos de tamanho variável:
		- Precisa-se conhecer a PRR em bytes;
			```
			A Posição Relativa do Registro (PRR) é o offset, em bytes, do começo do arquivo até o primeiro byte do registro.
			```
		- Implementado via estrutura de índice (Lista 6);
		- Em C/C++ pode se acessar qualquer byte, sendo assim, o programador pode implementar um acesso direto a um determinado registro;

## Tipo Abstrato de Dados
- Objetivo: Focar no conteúdo da informação e não no seu formato físico.
- Para sua aplicação, interessante conhecer:
	- Seus objetos;
	- Suas propriedades;
	- Operações a ser realizado com esses objetos;
	- Não se preocupar em como esses objetos estão armazenados fisicamente;
- Permite:
	- Descrever objetos e suas propriedades;
	- Organização e acesso de acordo com a aplicação, e não como foram armazenados fisicamente;
- Implementação:
	- Os detalhes da implementação são encapsulados;
	- Na visão do programador, apenas o nome do tipo e lista de operações estão disponíveis;
	- Algumas informações são usadas pelo software de acesso para entender esses objetos;

**Usamos TADs para representar estruturas de arquivos, como os registros.**


- Arquivo Auto-Descritivo:
	- É um arquivo com registro cabeçalho, no qual possui as informações que o descreve:
		- Número de campos por registro;
		- Nome de cada campo;
		- Tipo de cada campo;
		- Número de registro efetivos, etc...
	- Vantagem:
		- Permite o uso de programas genéricos: um programa genérico pode ler ou escrever "qualquer" arquivo deste tipo.
	- Desvantagem:
		- Os programas precisam ser mais sofisticados;

<img src="https://i.imgur.com/XaB4bYF.png" width="50%" height="50%" >

## DICOM ( Digital Imaging and Communications in Medicine)

- Comunicação de imagens digitais e medicina, é o padrão internacional para imagens médias e informação relacionada
- Define:
	- Formato para imagens, formas de onda, estrutura de dados...
		- Com a qualidade de metadados (visto aqui em cima) necessários para o uso clínico
	- Gerenciador do fluxo de trabalho 
	- Intercambio de Mídia e Impressão
	- Serviço de protocolos de rede sobre TPC/IP e HTTP (transmissão de dados entre equipamentos médicos e computadores por rede sem fio)
- Funcionamento:
	- Armazena todas as classes de imagens, CT, MR, Raio-X, Ultrassom...
	- Ajuda a gerenciar suas imagens
	- Gerencia as imagens não justo a pixels -> metadados significativos (??)
	- Contém a identificação do paciente e demografia
- Outras funções:
	- Armazenamento de imagens:
		- Crescimento fetal, saída cardíaca, tamanho do tumor...
		- Gerenciamento do fluxo de trabalho (??)
		- Apresentação de imagens com calibração de tela, anotações, layouts....
	- Armazenameto de Anáise de resultados:
		- Cadastros
		- Segmentações
		- Modelos de implantes
	- É seguro pois possui esquemas de identificação, encriptação (mas a gente nao conseguiu acessar ?)

## Padrão DICOM (simplificado)
#### Por que utilizar?

- Padronizar armazenamento e transmissão de imagens entre sistemas diferentes.      
	Existem muitas máquinas e equipamentos diferentes que têm que mexer com imagens médicas. Sem contar que a quantidade de exames é muito vasta. Por isso, estabelecer um padrão para todas facilita a implementação de um sistema eficiente para utilizá-las.
- Armazenar informações sobre as imagens junto delas
	O padrão DICOM faz uso intensivo de metadados para manter as informações pertinentes de uma imagem junto com ela.

#### Como funciona?
[Estrutura Básica](https://www.leadtools.com/help/leadtools/v19/dicom/api/overviewbasicdicomfilestructure.html) bem completa. Vamos ver um resumo aqui.
	
#### Partes do arquivo DICOM
![DICOM Structure](https://www.leadtools.com/help/leadtools/v19/resources/images/cppltdicdlln/dicom.gif)

1. **Preamble** - Informações específicas para aplicação. Tamanho fixo de 128 bytes. Deve ser incluído por causa do padrão, mas se não for utilizado os bytes têm valor 0x00.

2. **Prefix** - Valor fixo de 4 bytes : 'D', 'I', 'C', 'M'.

3. **Data Set** - Aqui é a parte do arquivo em que os metadados e os dados são incluídos. Um data set é uma coleção de Data Elements. Pode ter tamanho variável.

4. **Data Element** - Parte mais importante do arquivo, que contém os dados ou metadados. Os data elements são formados por `<tag><vr><length><value>`, em geral.

	1. TAG - Definida como uma tupla de 2 valores: ( Group Number, Element Number). Cada TAG é utilizada como identificador único de um tipo de metadado (ou dado, existe a TAG da imagem também). OS Group Numbers pares são públicos e os ímpares são privados (informações criptografadas).

	2. VR - Reference Value, é o "tipo" de valor daquele elemento.

	3. LENGTH - O tamanho do campo de valor. Pode ser indeterminado para alguns tipos de valores

	4. VALUE - O valor em si.

Existem 3 estruturas aceitáveis para os Data Elements. Elas são mostradas abaixo e discutidas em seguida.

1. Explicit VR for special fields (OB, OW, SQ, or UN) 


	![First DICOM Data Element Structure](https://www.leadtools.com/help/leadtools/v19/resources/images/cppltdicdlln/deevr.gif)

2. Explicir VR for normal fields        


	![Second DICOM Data Element Structure](https://www.leadtools.com/help/leadtools/v19/resources/images/cppltdicdlln/deevr2.gif)

3. Implicit VR             


	![Thrid DICOM Data Element Structure](https://www.leadtools.com/help/leadtools/v19/resources/images/cppltdicdlln/deivr.gif)
	
Os Data Elements iniciais de um arquivo (logo após o prefixo) especificam a sintaxe utilizada pelo arquivo (qual das três estruturas de Data Element foi utilizada), além da Endianess do arquivo (Little Endian, Big Endian) e algumas outras informações necessárias para a leitura correta do arquivo.

Os Data Elements seguintes trazem informações relacionadas à(s) imagem(s) que se segue(m). 

*FALAR SOBRE FITS*


## Compressão de dados

### Introdução

- Sistema operacional:
	- Uma de suas funções é formar uma interface entre os usuários e os dispositivos da memória secundária
	- Já em relação aos meios de armazenameto, as funções do SO podem ser de baixo nível ou de alto nível
	- As funções de baixo nível referem-se à transferência de blocos de bytes entre a memória princial e a secundária, compreendendo:
		- Gerenciamento da memória cache;
		- Programação de transferência de dados;
		- Codificação e decodificação dos dados ( detecção e correção de erros, criptografia, compressão de dados..)
	- Já as funções de alto nível devem operar na:
		- Estrutura do sistema de arquivos
		- Segurança (gereciamento de usuários)
		- Integridade
		- Alocação de espaço



- Caching
	- Processadores são mais rápidos que as memórias, então pode acontecer de um processador ficar esperando alguns ciclos enquanto o dado é lido da memória. Sendo assim, existem alguns métodos para resolver este problema:
		- Fazer memórias mais rápidas:	
			- São mais caras
		- Combinar memórias mais baratas com umas caras (tendo mais baratas do que caras nessa junção)
		- A RAM é feita com tecnologia mais barata em conjunto com a memória cache que é feita com uma tecnologia mais cara.
		
	- A ideia geral do caching é que quando uma palavra é referenciadas ela é trazida da RAM para a chache, fazendo com que na próxima vez que for utilizada ela pode ser acessada diretamente da cache, que por sua vez tem acesso mais rápido.
	- Se uma palavra é requerida k vezes, entao ela é acessada 1 vez na RAM e jogada pra cache, acessando todas as outras vezes lá mesmo ( k - 1 )
	- Se ‘c’ é o tempo médio de acesso a cache, ‘m’ é o tempo médio de acesso a
RAM, e ‘h’ é a taxa de acerto (no exemplo anterior seria (k-1)/k. Então o
tempo de acesso a memória é:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ``` Tempo médio de acesso = c + (1-h) * m```  (ta certo isso? não deveria ser c\*h + (1-h)\*m ?)
	
- Programação de Transferência
	- Nas operaçãos de leitura e gravação, o que mais demora nessas operaçoẽs é o movimento do braço das cabeças
	- Sendo assim, existe um controlador de dispositivos inteligente que organiza uma série de transferências de tal forma que consegue minimizar a perda de tempo recorrente ao movimento do braço (seeking)
- Codificação de dados
	- A transformação (codificação) é feita para atingir um certo objetivo (*Compressão*)
	- Suas características:
		- Seguro em relação a proteção e autenticação (criptografia)
		- Robusto
			- Possui detecção e correção de erros, pois a natureza física do armazenameto pode ocasionar a corrupção de dados
			- Para realizar a detecção de erros, deve-se incluir redundância na informação:
				- Utilizar uma certa quantidade de bits de controle para um determinado bloco de informação
				- Os bits de controle devem ser gerados a partir dos bits que representam a informção e gravá-los junto com o bloco
				- Quando for ler a informação, gera-se novamente os bits de controle (ta aí a redundância), se não der match nos 2 então a informação foi corrompida
	- Observação:
		- Note que cada um dos objetivos normalmente possuem requisitos opostos uns aos outros, como por exemplo:
			- Os algoritmos de compressão tem como objetivo reduzir o comprimento da mensagem
			- Os algoritmos de controle de erros implicam, muitas vezes, o aumento do comprimento da mensagem

###  Comprimindo  dados
- Compressão de dados é o processo de codificar uma determinada
informação utilizando uma menor representação. Os dois principais
benefícios trazidos pela compressão de dados são:
	- Capacidade de armazenamento das informações crescente: o uso de
compressão de dados pode aumentar significativamente a
capacidade de armazenamento do sistema. “um sinal comprimido
ocupa menos espaço”.
	- Transmissão de dados crescente: informações digitais podem ser
comprimidas antes de serem transmitidas de um módulo para outro.
“Um sinal comprimido requer menor largura de banda”.

*PERGUNTAR SE CAI ENTROPIA DE SHANNON (CTZ QUE ELE N SABE)*
[É possível que a entropia seja a probabilidade de cada caractere ocorrer na mensagem... só um chute]
		
- Existem 2 tipos de compressão:
	- Sem perdas (Lossless)
		- É a compressão que foca em apenas retirar a redundância de dados
		- Exemplo: GIF, ZIP, 7z, RAR
	- Com perdas(Lossy)
		- Além de tirar a redundância, também retira dados irrelevantes para uma determinada aplicação. Esse sinal recontruído após a compressão nao é exatamente o mesmo (obviamente), sua distorção é *D*, que é tolerada para um determinada aplicação
		- Exemplo: JPEG, Flash, MPEG-1, MP2, MP3. 
	-	Obs: É possivel comprimir um sinal sem perdas numa taxa NÃO inferior a entropia do sinal (wtf)

## LossLess Compression   
- Compressão de dados por Notação diferente
	- Pegando o exemplo de sala, temos um registro com os seguintes campos
		```<matrícula><nome><endereço><uf><curso><opção><departamento>```
	 
	- O campo de uf por exemplo é representado por 2 bytes (DF, MG, SP..), este campo pode ser reduzido a 1 byte em binário para representar os 26 estados do país (pode representar até 256 estados se tiver achando pouco hehe)
	- Já pro curso, opção e departamento, pode-se usar códigos correspondentes a essas entidades, em binário (mais econômico) ou uma string numérica.
	- Todos esses ajustes reduzem a redundância, deixando mais compacto, economizando bytes e representando a mesma informação.

- Desvantagens
	- O uso de código em binário torna o arquivo menos legível para humanos (nós somos super-humanos então)
	- Há um custo para codificar e decodificar as entidades
	- Aumenta a complexidade do software (ai nós ganahamos mais) 
	- Demanda tempo para codificar e decodificar (Qualquer operação de codificar um mensagem, por exemplo, é no mínimo O(n), com n sendo o tamanho da mensagem)
	-  Torna o processo mais lento
- Quando usar a compressão     (Economia de acesso compensa o custo de compressão)
	- Arquivos grandes (milhares de registros)
	- Em arquivos cujo poucos programas tenham acesso
	- Se a conversão for simples
- Quando NÃO usar a compressão
	- Arquivos pequenos (certos scasos)
	- Arquivos com muitos programas tendo acesso a ele (pq ? Talvez o custo de ficar comprimindo e descomprimindo para cada programa não compense, e pode gerar mais erros, já que as operações são repetidas muitas vezes)
	- Aplicação sem capacidade de lidar com binários Ex: Editor de texto
	
- Supressão de Sequências repetidas - Run lenght Coding
	- Indicado quando arquivos possuem uma sequência do mesmo byte frequente
	- Utiliza-se código de escape, se um caracter K aparece N vezes, então pode substituir   essa sequência por este modelo:
		
      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```<Código de escape><N><K>```
		
	- Exemplo:
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ```PEEEEEEENIS -> P$7ENIS```
			
	- Pode-se também definir um número mínimo de repetições, nesse caso, a técnica só será utilizada se N &ge; M, onde M é o número mínimo de repetições.

	- Exemplo: 	  
		Vamos assumir M = 3, Código de escape = '$'.     
		`Baataaaaaaattttttttaaaaaaaaaaaaaa -> Baat$7a$8t$14a`

		
- Códigos de comprimento variável
	- Os códigos de comprimento variável são aqueles que os simbolos codificados podem ter tamanhos diferentes (em bits)
	- É possível comprimi-los sem perda
	- Cada símbolo deve ser unicamente codificável, ou se ja, nenhum símbolo codificado pode ser prefixo de outro
	- Podem ser ou não instantaneamente codificável, ou seja, as vezes a mensagem precisa ser totalmente codificada para poder decodificar
	-  O princípio de sua codificação vem com a ideía de que alguns valores ocorrem mais do que outros, ou seja, valores que mais repetem são codificados com símbolos menores e símbolos maiores para valores com uma menor frequência
	- Exemplos:
		- Código Morse:  Utiliza-se apenas 2 símbolos para codificação (ponto e traço), como no alfabeto inglês as 2 letras que mais se repetem são  *E* e *T*, entao elas são codificadas com apenas 1 ponto para o *E* e 1 traço para o *T*, ou seja, valores que mais se repetem recebem símbolos menores
		- Código de Huffman: Utiliza a frequência de cada símbolo na mensagem para criar um código para cada símbolo. Símbolos mais frequentes possuem códigos menores, ocupando assim menos espaço na mensagem codificada.
		- Código de LZ78: cada simbolo é codificado por um par <i,c>, onde i é o índice correspondente a letra (ou conjunto de letras) que ja existe no dicionario e c é a letra seguinte. 
	- Analise:
		- Na maioria dos casos o Huffman é mais eficiente na compressão de arquivos.


## Funções de Alto Nível do S.O

Entre elas temos:

- Estrutura do sistema de arquivos:
	- Arquivos sao armazenados em diretorios;
	- Cada arquivo é indentificado pelo seu nome e caminho;
	-ex: `/home/usr/a.cpp`.
- Segurança:
	- Um usuario deve poder controlar o acesso a seus dados;
	- O S.O deve conceder diferentes permissoes de leitura e escrita, dependendo do usuario.
- Integridade:
	- Realização de Backups;
	- Manual ou Automaticamente dependendo da configuração e do S.O.
- Alocação de Espaco na memoria secundaria:
	- Adicionar, atualizar e remover registros.

## Funções de Baixo Nível do S.O
- Transmissao do bloco de bytes entre a memoria principal e a secundaria, usando o método chamado `caching`, onde pega o arquivo que foi colocado na RAM e passa ele para a memoria Cache, afim de diminuir o tempo de acesso.


## Operações basicas de indexação

### Criar arquivo de indices e de dados:
- Arquivos de indices sao iniciados como vazios;
- Serão posteriormente carregados com seus dados.

### Carregar arquivo de indices para a memoria:
- Leia o arquivo de indice e o cabeçalho (chave primaria);
- Verificar se a data do cabeçalho é compativel com a do arquivo de dados;
- Se não: gerar um arquivo de indices válido.
- Leia os registros do arquivo de indice e os coloque em um vetor;
- Leitura é rapida:
	- Registros sao pequenos;
	- No mesmo bloco;
	- Leitura sequencial, pouco `seeking`
	
### Regravar arquivo de indice depois de usa-lo
- Checa pra ver integridade dos dados a partir do cabeçalho
- Antes de qualquer acesso ao arquivo de indice deve estar atualizado o cabeçalho.

### Incluir registros:
- No arquivo de dados:
	- Atraves do PRR do registro
	- Insere ao final ou em algum espaço nao utilizado
- No arquivo de indices:
	- Incluir a chave primaria na ordem certa
	- Atualizar o cabeçalho
	- Reorganizar o INDEX[]
	
### Excluir registros:
- Eliminar do arquivo de dados:
	- Atualizar LED para reaproveitar espaço
- Eliminar do arquivo de indices:
	- Reorganização do INDEX[]
	- Atualizar cabeçalho
	
### Atualizar registros:
- Com mudança na chave primaria:
	- Atualizar INDEX[]
	- Alterar o registro correspondente
- Sem mudanças na chave primaria:
	- Se a mudança couber no registro, não precisa atualizar o INDEX[]

		 

## FIM :+1:

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTU2NjAxOTEzNF19
-->
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE5NDQ2MjY2MDgsMjA4MzIyMDQ2LDE5Nj
YxNDgxMTMsLTY2MzIxMjQyNSwxNjg0NzU5MjkzLDEzODQ1MzEy
NDMsMTQxMjQxMDU5Nyw2NjQxODA1MTBdfQ==
-->