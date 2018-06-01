
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
		- Precisa-se conhecer a PRR em bytes (?);
		- Implementado via estrutura de índice (Lista 6);
		- Em C/C++ pode se acessar qualquer byte, sendo assim, o programador pode implementar um acesso direto a um determinado registro;

## Tipo Abstrato de Dados
- Objetivo: Focar no conteúdo da informação e não no seu formato físico.
- Para sua aplicação, interessante conhecer:
	- Seus objetos;
	- Suas propriedades;
	- Operações a ser realizado com esses objetos;
	- Sem se preocupar em como esses objetos estão armazenados fisicamente;
- Permite:
	- Descrever objetos, suas propriedades;
	- Organização e acesso de acordo com a aplicação, e não como foram armazenados fisicamente;
- Implementação:
	- Os detalhes da implementação são encapsulados;
	- Na visão do programador, apenas o nome do tipo e lista de operações estão disponíveis;
	- Algumas informações são usadas pelo software de acesso para entender esses objetos;
- Arquivo Auto-Descritivo:
	- É um arquivo com registro cabeçalho, no qual possuii as informações que o descreve:
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

- Comunicação de imagens digitais e medicina, é o padra internacional para imagens médias e informação relacionada
- Define:
	- Formato para imagens, formas de onda, estrutura de dados...
		-Com a qualidade de matadados (visto aqui em cima) necessários para o uso clínico
	- Gerenciador do fluxo de trabalho 
	- Intercambio de Mídia e Impressão
	- Serviço de protocolos de rede sobre TPC/IP e HTTP (wtf)
- Funcionamento:
	- Armazena todas as classes de imagens, CT, MR, Raio-X, Ultrassom...
	- Ajuda a geenciar suas imagens
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

*FALA COMO FUNCIONA O DICOM, GIOVANNI (PLS)*

*FALAR SOBRE FITS*


## Compressão de dados

- Sistema operacional:
	- Uma de suas funções é formar uma interface entre os usuários e os dispositivos da memória secundária
	- Já em relação aos meios de armazenameto, as funções do SO podem ser de baixo nível oou de alto nível
	- As funções de baixo nível referem-se à transferência de blocos de bytes entre a memória princial e a secundária, comreendendo:
		- Gerenciamento da memória cache;
		- Programação de transferência de dados;
		- Codificação e decodificação dos dados ( detecção e correção de erros, criptografia, compressão de dados..)
- Já as funções de alto nível devem operar na:
	- Estrutura do sistema de arquivos
	- Segurança (gereciamento de usuários)
	- Integridade
	- Alocação de espaço

## Funções de baixo nível

- Caching
	- Processadores são mais rápidos que as memórias, então pode acontecer de um processador ficar esperando alguns ciclos enquant o pdado é lido da memória. Sendo assim, existem alguns métodos para resolver este problema:
		- Fazer memórias mais rápidas:	
			- São mais caras
		- Combinar memórias mais baratas com umas caras (tendo mais baratas do que caras nessa junção)
		- A RAM é feita com tecnologia mais barata em conjunto com a memória cache que é feita com uma tecnologia mais cara.
		
	- A ideia geral do caching é que quando uma palavra é referenciadas ela é trazida da RAM para a chache, fazendo com que na próxima vez que for utilizada ele pode ser acessada diretamente da cacha, que por sua vez é mais rápido
	- Se uma palavra é requerida k vezes, entao ela é acessada 1 vez na RAM e jogada pra cache, acessando todas as outras vezes lá mesmo ( k - 1)
	- Se ‘c’ é o tempo médio de acesso a cache, ‘m’ é o tempo médio de acesso a
RAM, e ‘h’ é a taxa de acerto (no exemplo anterior seria (k-1)/k. Então o
tempo de acesso a memória é:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ``` Tempo médio de acesso = c + (1-h) * m```
	
- Programação de Transferência
	- Nas operaçãos de leitura e gravação, o que mais demora nessas operaçoẽs é o movimento do braço das cabeças
	- Sendo assim, existe um controlador de dispositivos inteligente que organiza uma série de transferências de tal forma que consegue minimizar a perda de tempo recorrente ao movimento do braço (seeking)
- Codificação de dados
	- A transformação (codificação) é feita para atingir um certo objetivo (*Compressão*)
	- Suas características:
		- Seguro em relação a proteção e autenticação (criptografia)
		- Robusto
			- Possui detecção e correção de erros, pois a naturea física do armazenameto pode ocasionar a corrupção de dados
			- Para realizar a detecção de erros, deve-se incluir redundância na informação:
				- Utilizar uma certa quantidade de bits de controle para um determinado bloco de informação
				- Os bits de controle devem ser gerados a partir dos bits que representam a informção e gravá-los junto com o bloco
				- Quando for ler a informação, gera-se novamente os bits de controle (ta aí a redundância), se não der match nos 2 então a informação foi corrompida
	- Observação:
		- Note que cada um dos objetivos normalmente possuem requisitos opostos uns aos outros, como por exemplo:
			- Os algoritmos de compressão tem como objetivo reduzir o comprimento da mensagem
			- Os algoritmos de controle de erros implicam, muitas vezes, o aumento do comprimento da mensagem

##  Compressão de dados
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

* PERGUNTAR SE CAI ENTROPIA DE SHANNON (CTZ QUE ELE N SABE)*
		
- Existem 2 tipos de compressão:
	- Sem perdas (Lossless)
		- É a compressão que foca em apenas retirar a redundância de dados
	- Com perdas(Lossy)
		- Além de tirar a redundância, também retira dados irrelevantes para uma determinada aplicação. Esse sinal recontruído após a compressão nao é exatamente o mesmo (obviamente), sua distorção é *D*, que é tolerada para um determinada aplicação
	-	Obs: É possivel comprimir um sinal sem perdas numa taxa NÃO inferior a entropia do sinal (wtf)
- Compressão de dados por Notação diferente
	- Pegando o exemplo de sala com um registro com os seguintes campos
		```<matrícula><nome><endereço><uf><curso><opção><departamento>```
	 
	- O campo de uf por exemplo é representado por 2 bytes (DF, MG, SP..), este campo pode ser reduzido a 1 byte em binário para representar os 26 estados do país (pode representar até 256 estados se tiver achando pouco hehe)
	- Já pro curso, opção e departamento, pode-se usar códigos correspondentes a essas entidades, em binário (mais econômico) ou uma string numérica.
	- Todos esses ajustes reduzem a redundãncia, deixando mais compacto, ecnomizando bytes e representando a mesma informação.

- Desvantagens
	- O uso de código em binário torna o arquivo menos legível para humanos (nós somos super-humanos então)
	- Há um costo para codificar e decodificar das entidades
	- Aumenta a complexidade do software (ai nós ganahamos mamis) 
	- Demanda tempo para codificar e decodificar (?)
	-  Torna o processo mais lento
- Quando usar a compressão     (Economia de acesso compensa o custo de compressão)
	- Arquivos grandes (milhares de registros)
	- Em arquivos cujo poucos programas tenham acesso
	- Se a conversão for simples
- Quando NÃO usar a compressão
	- Arquivos pequenos (certos scasos)
	- Arquivos com muitos programas tendo acesso a ele (pq ?)
	- Aplicação sem capacidade de lidar com binários Ex: Editor de texto
	
- Supressão de Sequências repetidas - Run lenght Coding
	- Indicado quando arquivos possuem uma sequência do mesmo byte frequente
	- Utiliza-se código de escape, se um caracter K aparece N vezes, então pode substituir   essa sequência por este modelo:
		
      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```<Código de escape><N><K>```
		
	- Exemplo:
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ```PEEEEEEENIS -> P$7NIS```
			
	- Pode-se também definir um número mínimo de repetições.

	- Exemplo: Utilizando repetição mínima de 3 em um arquivo binário: 

		*ENTENDI NADA DESSA PARTE (SLIDE 9 PÁGINA 29)*	
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTE4NDExNzM5NCwyMTI5NDQzNTAyLDg5NT
QzMzkyLC0xMDY2MjkwOTU4XX0=
-->