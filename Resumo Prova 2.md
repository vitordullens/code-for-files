
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
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEwMjY0OTYyOTUsLTIxNDEwOTYwMSwxNj
E0MDQ5NzA2LC0yNzI2NzM0MzVdfQ==
-->