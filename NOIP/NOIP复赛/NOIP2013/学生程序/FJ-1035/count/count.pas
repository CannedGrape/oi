var
  n,ans:longint;
	i,j:longint;

	k,a:char;
	s:string;
begin
	assign(input,'count.in');
	assign(output,'count.out');
	reset(input);
	rewrite(output);
	readln(n,a,k);
	ans:=0;
	for i:=1 to n do
		begin
      str(i,s);
	    for j:=1 to length(s) do
				begin

				if s[j]=k then ans:=ans+1;
					end;
		end;
	writeln(ans);
	close(input);
	close(output);
end.
	    