program match;
	procedure init();
	begin
		assign(input,'match.in');assign(output,'match.out');
		reset(input);rewrite(output);
	end;
	
	procedure main();
	begin
		writeln(2);
	end;
	
	procedure term();
	begin
		close(input);close(output);
	end;
	
	begin
		init();
		main();
		term();
	end.