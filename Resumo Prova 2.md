---


---

<h1 id="resumo-prova-2-oa">Resumo Prova 2 OA</h1>
<h2 id="acesso-a-arquivos-vs-organização-de-arquivos">Acesso a arquivos VS Organização de Arquivos</h2>
<ul>
<li>Pode se organizar um arquivo em registros de 2 modos:
<ul>
<li>Tamanho fixo;</li>
<li>Tamanho variável;</li>
</ul>
</li>
<li>Já o acesso pode ser feito:
<ul>
<li>Diretamente;</li>
<li>Sequencialmente;</li>
</ul>
</li>
<li>Acesso Direto:
<ul>
<li>Arquivos de tamanho fixo:
<ul>
<li>É imediato e utiliza a função <code>fseek()</code>;</li>
</ul>
</li>
<li>Arquivos de tamanho variável:
<ul>
<li>Precisa-se conhecer a PRR em bytes (?);</li>
<li>Implementado via estrutura de índice (Lista 6);</li>
<li>Em C/C++ pode se acessar qualquer byte, sendo assim, o programador pode implementar um acesso direto a um determinado registro;</li>
</ul>
</li>
</ul>
</li>
</ul>
<h2 id="tipo-abstrato-de-dados">Tipo Abstrato de Dados</h2>
<ul>
<li>Objetivo: Focar no conteúdo da informação e não no seu formato físico.</li>
<li>Para sua aplicação, interessante conhecer:
<ul>
<li>Seus objetos;</li>
<li>Suas propriedades;</li>
<li>Operações a ser realizado com esses objetos;</li>
<li>Sem se preocupar em como esses objetos estão armazenados fisicamente;</li>
</ul>
</li>
<li>Permite:
<ul>
<li>Descrever objetos, suas propriedades;</li>
<li>Organização e acesso de acordo com a aplicação, e não como foram armazenados fisicamente;</li>
</ul>
</li>
<li>Implementação:
<ul>
<li>Os detalhes da implementação são encapsulados;</li>
<li>Na visão do programador, apenas o nome do tipo e lista de operações estão disponíveis;</li>
<li>Algumas informações são usadas pelo software de acesso para entender esses objetos;</li>
</ul>
</li>
<li>Arquivo Auto-Descritivo:
<ul>
<li>É um arquivo com registro cabeçalho, no qual possuii as informações que o descreve:
<ul>
<li>Número de campos por registro;</li>
<li>Nome de cada campo;</li>
<li>Tipo de cada campo;</li>
<li>Número de registro efetivos, etc…</li>
</ul>
</li>
<li>Vantagem:
<ul>
<li>Permite o uso de programas genéricos: um programa genérico pode ler ou escrever “qualquer” arquivo deste tipo.</li>
</ul>
</li>
<li>Desvantagem:
<ul>
<li>Os programas precisam ser mais sofisticados;<img src="https://picasaweb.google.com/108530487111855138967/6561810839969888433#6561810843451850002" alt="" title="Exemplo - Metadados"></li>
<li></li>
</ul>
</li>
</ul>
</li>
</ul>

