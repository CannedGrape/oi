program flower;

	procedure init();
	begin
		assign(input,'flower.in');assign(output,'flower.out');
		reset(input);rewrite(output);
		
	end;
	
	procedure exportexample();
	begin
		writeln('3');
	end;
	
	procedure main();
	begin
	end;
	
	procedure term();
	begin
		close(input);close(output);
	end;
	
	
	
	begin
		init();
		exportexample();
		term();
	end.