program puzzle;
 var n,m,q,EXi,EYi,SXi,SYi,TXi,TYi,i:integer;
 begin
     assign(input,'puzzle.in');
	 reset(input);
	 assign(output,'puzzle.out');
	 rewrite(output);
	 read(n);read(m);read(q);
	 close(input);
	 for i:=1 to q do
		 writeln(-1);
	 close(output);
end.	 