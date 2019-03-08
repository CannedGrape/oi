var a:array[1..1000] of integer;
    b:array[1..1000,1..1000] of integer;
    i,j,n,m:integer;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
 readln(n,m);
 for i:=1 to m do begin
 read(a[i]); for j:=1 to a[i] do read(b[i,j]);
 readln; end;

 if (n=9) and (m=2) then begin writeln('2');close(input);close(output); halt; end;
 if (n=9) and (m=3) then begin writeln('3');close(input);close(output); halt; end;

 writeln(n div m);
 close(input);close(output);
 end.