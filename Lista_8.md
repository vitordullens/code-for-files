## [OA] - Lista 8
` by Gguidini. Answers not verified. If any mistake is found please report `

#### 1) 
##### a) Como são organizados fisicamente os discos? 

Os discos rígidos são formados por pratos. Cada prato é dividido em trilhas (círculos concêntricos), e cada trilha em setores de 512 bytes (ou mais). Esses discos são "empilhados" um sobre o outro e presos por um eixo central. As trilhas de cada disco ficam alinhadas com os discos abaixo e acima.

##### b) De que forma os discos armazenam os arquivos? 

Os discos possuem uma camada de material magnético. Uma cabeça de leitura e escrita existe virada para cada superfície de cada disco no HD. Esta cabeça é capaz de detectar a polaridade das partículas de uma região pequena do disco, que são as informações dos bits dos arquivos. Estas cabeças também possuem pequenas bobinas que geram campos magnéticos capazes de alterar a polaridade do disco.
Assim os arquivos podem ser lidos e escritos em um HD.

##### c) Por que o tamanho real de um arquivo em disco é sempre maior do que o seu tamanho nominal?

No HD o arquivo, além dos bytes do seu conteúdo, também deve armazenar dados relacionados ao arquivo, setores que ocupa, etc. Ou seja, dados para que o SO e o próprio HD consigam recuperar o arquivo futuramente. Daí vem o tamanho extra.

#### 2)  
##### a) Quais parâmetros são considerados para calcular o tempo de leitura de um arquivo mantido em disco?

Os parâmetros são:
    1. Taxa de latência
    2. Taxa de transferência
    3. tempo de _seeking_
    
##### b) Calcule quanto tempo um disco levaria para ler sequencialmente todo o conteúdo de um arquivo de 1MB (1MB = 2^20 bytes,considere que o arquivo está armazenado em regiões consecutivas, i.e., em um único extent).

Assumindo:
Tempo de _seeking_ médio 13ms
Latência 8.3ms
Taxa máxima de transferência: 1229 bytes/ms

Como está armazenado em um único extent só precisa de 1 operação de seeking + latência para posicionamento no setor correto de início + bytes do arquivo / taxa de transferência

Total: 13ms + 8.3ms + (2^20)/1229 = *874.49 ms*

#### 3) Refaça a questão anterior supondo agora que o mesmo arquivo está distribuído em 5 extents distintos no mesmo disco.
```
2^20/ 5 = 209.715 bytes por extent
_seeking_ * 5 + latência * 5 + (209.715/1229) * 5 = 
13 * 5 + 8.3 * 5 + 170.64 * 5 = 959.70 ms
```

#### 4) Refaça a questão anterior supondo agora que o mesmo arquivo está distribuído em 5 extents distintos no mesmo disco, mas considerando um acesso aleatório a um único registro do arquivo, ao invés de acesso sequencial a todo o seu conteúdo

Não entendi

#### 5) Explique o que é um cilindro, e a razão para a organização de arquivos em cilindros.

Um cilindro se refere à trilhas com a mesma numeração de pratos diferentes, que estão alinhadas verticalmente. Como todas as cabeças de I/O também estão alinhadas, é possível acessar todas as trilhas em um cilindro sem mover a cabeça de I/O, economizando tempo.

#### 6) Explique o que é um cluster e o que é um extent.

Um cluster é a menor unidade de alocação que o SO considera para o HD. Basicamente um conjunto de setores.

Um _extent_ é uma sequẽncia de clusters consecutivos em disco.

#### 7) O que é a fragmentação de um arquivo no disco? Quais os tipos de fragmentação do arquivo, porque elas ocorrem e quais seus efeitos?

A fragmentação de um arquivo se refere ao espalhamento dos bytes que pertencem à este arquivo pelo disco.
A fragmentação pode acontecer a nível de cluster, bloco ou _extent_.
A nível de cluster ou bloco ocorrem quando o tamanho dos clusters não é múltiplo do tamanho dos registros, então parte do espaço do cluster não é utilizado. O efeito é a existência de espaços vazios no disco.
A nível de _extent_ ocorre quando não há espaço para armazenar o arquivo em clusters adjacentes, isso acarreta um aumento no número de _seekings_ necessário para processar o arquivo.

#### 8) Discuta as vantagens e desvantagens de organizar arquivos em blocos de tamanho definido pelo usuário, ao invés de em setores de tamanho fixo.

A vantagem é que o usuário pode aproveitar melhor o espaço do disco, otimizando o acesso para cada arquivo, e diminuindo a fragmentação que o arquivo poderia sofrer. 
As desvantagens são que o usuário precisa de um conhecimento sobre como os arquivos são armazenados e o SO precisa ser capaz de gerênciar os diferentes tamanho de bloco por arquivo.

#### 9) Por que os discos são considerados o gargalo de um sistema computacional? Explique como este problema pode ser minimizado.

O tempo de I/O em discos é muito maior do que o tempo de acesso da RAM, que já é lento se comparado com os tempos de acesso do processador. Portanto qualquer operação que necessite do disco vai esperar muito tempo pelos dados necessários. Por isso o HD é um gargalo do sistema.

Técnicas para contornar este problema podem utilizar _buffering_, uma memória RAM dentro do disco para agilizar operações, e a utilização de sistemas RAIDs que diminuem o tempo de acesso usando _data stripping_.

#### 10) Como os arquivos são organizados em uma fita magnética? Por que as fitas organizam os dados em blocos?

Nas fitas magnéticas os dados são organizados de forma sequencial. Existem 9 bits organizados em trilhas diferentes: os 8 primeiros são um byte armazenado e o último é um bit de paridade. Este conjunto é chamado de frame.
A organização em blocos se dá por que existem espaços entre os blocos vazios, utilizados para auxiliar na rodagem da fita. Assim, é necessário definir o tamanho de cada bloco e dos gaps entre eles.

#### 11) Quais as vantagens e desvantagens de fitas sobre discos com dispositivos de memória secundária?

Vantagens são a enorme capacidade de armazenamento e simplicidade com que as informações são armazenadas nas fitas (o endereço lógico é o mesmo do físico).
As desvantagens estão principalmente nos tempos de acesso. Elas são ótimas para acessos sequenciais, mas demoram muito para acessos aleatórios.

#### 12) No que consiste um sistema de armazenamento terciário?

São _back-ups_ de sistemas, geralmente armazenados em fitas magnéticas. Costumam ser pouco acessados e ocupar vários tera.

#### 13) 
##### a) Quais parâmetros são considerados para calcular o tempo de leitura de um arquivo em fita? 

Os parâmetros são:
    1. Densidade
    2. Velocidade da fita
    3. Tamanho dos gaps
    4. Tamanho dos blocos
    
##### b)Procure estas informações para um dispositivo de fita comercial e calcule quanto tempo tal dispositivo levaria para ler um arquivo de 1 MB.

#### 14) O que são “buffers” de E/S (ou I/O)? Quais os passos executados para que ler um byte do disco de forma que ele possa ser utilizado por um programa?
