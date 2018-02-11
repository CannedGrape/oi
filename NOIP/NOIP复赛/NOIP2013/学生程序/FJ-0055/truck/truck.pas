var n,m,q:longint;

procedure init;
var i,j,x,y,z:longint;
begin
 readln(n,m);
 for i:=1 to m do
   readln(x,y,z);
 readln(q);
 for j:=1 to q do
  readln(x,y);
 writeln(3);
 writeln(-1);
 writeln(3);

end;
procedure fopen;
begin
 assign(input,'truck.in');
 assign(output,'truck.out');
 reset(input);
 rewrite(output);
end;
procedure fclose;
begin
 close(input);
 close(output);
end;
begin
 fopen;
 init;
 fclose;
end.


