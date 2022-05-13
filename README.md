Actually, don't read me. Using this file to remember some stuff.


./pipex "CMD1 cmd1.arg1 'cmd1.arg2 as string'" 'CMD2 cmd2.arg1 "cmd2.arg2 as string"'
	ARG[0]: >>./pipex<<
	ARG[1]: >>CMD1 cmd1.arg1 'cmd1.arg2 as string'<<
	ARG[2]: >>CMD2 cmd2.arg1 "cmd2.arg2 as string"<<

Worst case scenario input - can't backslash simple quotation marks.
	./pipex "echo 'this is f'cked up'" "tr ''' '\"'"
	echo "this is f'cked up" | tr "'" "\""

./pipex INFILE "CMD1 cmd1.arg1 cmd1.arg2" "CMD2 cmd2.arg1 'cmd2.arg2 is a string'" OUTFILE
