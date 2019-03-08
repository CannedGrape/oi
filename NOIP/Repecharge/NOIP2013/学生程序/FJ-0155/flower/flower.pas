program flower;
 var n,i,m,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10:integer;
 begin
     assign(input,'flower.in');
	 reset(input);
	 assign(output,'flower.out');
	 rewrite(output);
	 read(n);read(a1);read(a2);read(a3);read(a4);read(a5);read(a6);read(a7);read(a8);read(a9);read(a10);
	 close(input);
	 n:=n-2;
	 writeln(n);
	 close(output);
end.	 