Actually, don't read me. Using this file to remember some stuff.

gcc me.c ../includes/pipex.h && ./a.out

shell rules:
	*a single unscaped duble quotation mark(") not encapsulated by 2 unescaped simple quotation ('__') marks will disregard EVERYTHING until a new unescaped quotation mark is found, or any termination signals are sent to the running process. This will not and should not run pipex properly.
	ie: ./a.out "'whatever text....' -> [prompt]
	* (') takes everything inside as simple characters, whereas (") will interpret ($), (`), (\), (!).
	*escaped simple quotation (') marks encapsulated by two others of the same type will be counted as unescaped quotation marks. Note that the 1st " is encapsulated by ' and \' and is not treated as a special character:
	ie: '"123 23z\'a"b' c 'd" - > {"123 23z\ab' c 'd}
		this would in turn be sent to execve as single argument
	*split on [space] unless it is encapsulated between 2 of the same quotation marks:
	ie: a b "_ c _" -> {a}, {b}, {_ c _};
		a b '_ c _' -> {a}, {b}, {_ c _};
	*if any number of quotation marks are found inside 2 different quotation marks, they are disregarded as being special characters:
	ie:	" 1' 2' 3' 4' 5' " -> { 1' 2' 3' 4' 5' }
		note that this in turn would be sent to execve as {1 2}, { 3 4}, { 5' } and would result in user input prompt.
	*any escaped quotation inside a pair of the same type is not considered a special character:
	ie: "and thus he said: \"'sup\"" -> {and thus he said: "'sup"}
	*exclamation marks followed by a backslash need to be escaped AND have their preffixed backslash removed after:
	ie : " :\"sup'!\" " -> -bash: !\: event not found
		 " :\"sup'\!\" " -> {sup'\!" }
		 this somehow only occurs for !
	*One may concatenate strings into a single argument, so long as no spaces are fount outside quotation marks:
	ie: 0 "12  34""ab cd"'++ --' -> {0}, {12  34ab cd++ --}
	*you can escape spaces and backslashes :|
	ie: 0\ 123 -> {0 123}
	ie2: \\ -> {\}
	*Using single unfollowed backslashes will fuck shit up. There's the threshold for user input error.
	ie: $ echo banana | tr a \ > outfile && cat outfile -> {b n n }
			it escapes the space as a delimiter and swaps 'a's for ' 's.

last case is \[space].
./pipex "cmd1 case0 \"case 1\" 'case 1.1' case\" 2\" case' 2.2' case\ 3 'case\ 4' 'case 5''now 5.1'\"this is 5.2\" '\"case 6\' \\'case 7\' \\\"case 8\\\" 'case9\!' \ "
ARGV[cmd1] = {cmd1 case0 "case 1" 'case 1.1' case" 2" case' 2.2' case\ 3 'case\ 4' 'case 5''now 5.1'"this is 5.2" '"case 6\' \'case 7\' \"case 8\" 'case9\!' \};
{{cmd1}, {case0}, {"case 1"}, {'case 1.1'}, {case" 2"}, {case' 2.2'}, {case\ 3}, {'case\ 4'}, {'case 5''now 5.1'"this is 5.2"}, {'"case 6\'}, {\'case7\'}, {\"case8\"}, {case9\!}};

./pipex 'cmd2 case0 "case 1" case" 2" case\ 3 "case 5""now 5.1" \"case 6\" \\"case 7\\" \\\"case 8\\\" "case9\!" \ '
ARGV[cmd2] = {cmd2 case0 "case 1" case" 2" case\ 3 "case 5""now 5.1" \"case 6\" \\"case 7\\" \\\"case 8\\\" "case9\!" \};
EXECVE = {{cmd2}, {case0}, {"case 1"}, {case" 2"}, {case\ 3}, {"case 5""now 5.1"}, {\"case 6\"}, {\\"case 7\\"}, {\\\"case 8\\\"}, {"case9\!"}, {\}};

splitting to execve arguments:

	count how many splits we want:
		initialize skip flag as 0;
		start iterating through argument



./pipex "CMD1 cmd1.arg1 'cmd1.arg2 as string'" 'CMD2 cmd2.arg1 "cmd2.arg2 as string"'
	ARG[0]: >>./pipex<<
	ARG[1]: >>CMD1 cmd1.arg1 'cmd1.arg2 as string'<<
	ARG[2]: >>CMD2 cmd2.arg1 "cmd2.arg2 as string"<<

Worst case scenario input(not really) - can't backslash simple quotation marks.
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

Exit codes;
1 - Catchall for general errors.
2 - Misuse of shell builtins (according to Bash documentation)
126 - Command invoked cannot execute.
127 - “command not found”
128 - Invalid argument to exit.
128+n - Fatal error signal “n”
130 - Script terminated by Control-C.
255\* - Exit status out of range.