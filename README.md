Actually, don't read me. Using this file to remember some stuff.

gcc me.c ft_split.c ft_strlen.c ../includes/pipex.h && ./a.out

./pipex "CMD1 cmd1.arg1 'cmd1.arg2 as string'" 'CMD2 cmd2.arg1 "cmd2.arg2 as string"'
	ARG[0]: >>./pipex<<
	ARG[1]: >>CMD1 cmd1.arg1 'cmd1.arg2 as string'<<
	ARG[2]: >>CMD2 cmd2.arg1 "cmd2.arg2 as string"<<

Worst case scenario input - can't backslash simple quotation marks.
	./pipex "echo 'this is f'cked up'" "tr ''' '\"'"
	echo "this is f'cked up" | tr "'" "\""

./pipex INFILE "CMD1 cmd1.arg1 cmd1.arg2" "CMD2 cmd2.arg1 'cmd2.arg2 is a string'" OUTFILE



TRATAMENTO DE ERROS:
	argc != 5; -> printa erro e não roda.
	INFILE não encontrado; -> segue para cmd2 e printa mensagem de erro:
			$ cat INVALIDfile | echo aalalal > outfile
			cat: infole: No such file or directory
			$ cat outfile
			aalalal
	2 erros de input; -> printa erro do cmd1, depois printa erro do cmd2:
		x$ cat infole | echao aalalal > outfile
			cat: infole: No such file or directory
			bash: echao: command not found
	erro no 2o comando; -> executa o comando 1, repassando o input para cmd2 (que resulta em porra nenhuma), printa erro do cmd2:
		cat infile | echao aalalal > outfile
			bash: echao: command not found
	string nula como comando 1; -> ???:
		./pipex INFILE "" "cmd2 cmd2.arg1 cmd2.arg2" OUTFILE
		$ | echo > outfile
			bash: syntax error near unexpected token `|'
	string nula como comando 2; -> roda comando 2 e nada acontece:
		./pipex INFILE "cmd1 cmd1.arg1 cmd1.arg2" "" OUTFILE
		$ cat infile | > outfile
			$

