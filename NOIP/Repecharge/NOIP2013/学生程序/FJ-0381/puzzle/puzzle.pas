var input,output:text;
    n,m,q:integer;

procedure putin;
 begin
  readln(input,n,m,q);
 end;

procedure putout;
 var x:integer;
 begin
  for x:=1 to q do writeln(output,-1);
 end;

procedure main;
 begin

 end;

begin
 assign(input,'e:\FJ-0381\puzzle\puzzle.in');
 assign(output,'e:\FJ-0381\puzzle\puzzle.out');
 reset(input);
 rewrite(output);
 putin;
 main;
 putout;
 close(input);
 close(output);
end.
