var	ans:array[1..100000] of record
				  x:longint; y:boolean;
				end;
	s:array[1..100000] of char;
	ch:char;
	i,n,j:longint;
	totans:int64;
begin
	assign(input,'expr.in'); reset(input);
	assign(output,'expr.out'); rewrite(output);
	while not eoln do
	  begin
	    read(ch);
	    inc(n);
	    if (ch='+') or (ch='*') then s[n]:=ch;
	    if (ch<>'+') and (ch<>'*') then
	      begin
		ans[n].x:=ord(ch)-ord('0');
	    	ans[n].y:=true;
	      end;
	  end;
	for i:=1 to n do
	  begin
	    if (s[i]='*') and (ans[i-1].y) then
	      begin
		totans:=totans*ans[i+1].x*ans[i-1].x;
		ans[i-1].y:=false;
	      end;
          end;
	for j:=1 to n do
	  begin
	    if (s[j]='+') and (ans[j-1].y) then
	      begin
		totans:=totans+ans[j+1].x+ans[j-1].x;
		ans[j-1].y:=false;
	      end;
          end;
	writeln(totans-1);
	close(input); close(output);
end.
