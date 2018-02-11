var
  a:array[1..100000]of integer;
	b:array[1..100000]of char;
	i,j,ans:longint;
begin
	assign(input,'expr.in');
	assign(output,'expr.out');
	reset(input);
	rewrite(output);
i:=1;
while true do
	begin
		inc(i);
    read(a[i]);
    if eof then break;
    read(b[i]);
  end;
for j:=1 to i do 
	if b[j]='*' then
    begin
	    a[j+1]:=a[j]*a[j+1];
	    a[j]:=0;
	    b[j]:='+';
	  end;
for j:=1 to i do
	ans:=ans+a[i];
writeln(ans);
close(input);
close(output);
end.
	