How to compile:
gcc readFile.o Main.c -o main
How to execute
./main <table name> 

--------------------------------------

Deverá ser entregue o arquivo fonte com as seguintes características:
• Ao executar o programa deverá ser passado um parâmetro (uma sequência de caracteres) correspondente ao nome lógico 
(tabela) deum arquivo de dados.
• O aplicativo procurará no arquivo table.dic o nome da tabela passa do como parâmetro , caso encontrar, deverá abir o 
arquivo com o nome físico para leitura.

A estrutura do arquivo table.dic é a seguinte: um inteiro que corresponde ao id do arquivo, uma sequência de
20 caracteres que corresponde ao nome lógico do arquivo e outra se quência de 20 caracteres que corresponde ao nome 
físico do arquivo (nome do arquivo no disco).
• Caso o nome lógico for encontrado em table.dic, o arquivo att.dic deve ser aberto para procurar o e Esquema do arquivo.

O arquivo att.dic está organizado da seguinte forma: um inteiro que corresponde ao id do arquivo (chave estrangeira de 
table.dic) a ser consultado, uma sequência de 20 caracteres que corresponde ao nome do atributo, um caracterer que 
corresponde ao tipo (S string, I inteiro ou D double), um caracter que indica a opcionalidade do atributo 
(0 obrigatório, 1 opcional) e um inteiro que indica o tamanho do atributo.
Exemplo:
table.dic <1, "carros", "xyz.dat">, <2, "donos", "d001.dat">
att.dic <1, "modelo", 'S', 0, 30>, <1,"ano", 'I',0, 4>, <2, "cpf", 'S', 0, 12>,<2, "nome", 'S', 0, 30>
Se for passado o nome lógico donos, o arquivo d001.dat conterá os dados com o esquema correspondente ao id 2 no 
arquivo att.dic, ou seja, cpf sequência de 12 caracteres, obrigatório; e nome sequência de 30 caracteres, obrigatório.
• Finalmente, o conteúdo do arquivo físico deve ser listado. Para facilitar, não será necessário tratar atributos 
opcionais pois todos serão considerados obrigatórios.
• O .zip anexo contém um exemplo de table.dic, att.dic e um arquivo de dados que devem ser utilizados como teste.
