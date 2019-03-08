var input,output:text;
    n,max:longint;
procedure putin;
 begin
  readln(input,n);
 end;

procedure putout;
 begin
  write(output,max);
 end;

procedure main;
 begin
  if n mod 2 =1 then max:=(n+1)div 2 else max:=n div 2;
 end;

begin
 assign(input,'e:\FJ-0381\flower\flower.in');
 assign(output,'e:\FJ-0381\flower\flower.out');
 reset(input);
 rewrite(output);
 putin;
 main;
 putout;
 close(input);
 close(output);
end.
