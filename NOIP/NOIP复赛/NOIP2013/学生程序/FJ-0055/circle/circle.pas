var n,m,k,x,y:longint;

procedure fopen;
begin
 assign(input,'circle.in');
 assign(output,'circle.out');
 reset(input);
 rewrite(output);
end;
procedure fclose;
begin
 close(input);
 close(output);
end;

function f(a:longint):longint;
begin
 if a=1 then exit(y);
 if odd(a) then
  exit((((f(a div 2)*f(a div 2))mod n)*y)mod n)
 else exit((f(a div 2)*f(a div 2))mod n);
end;

begin
 fopen;
 readln(n,m,k,x);
 y:=10 mod n;
 writeln((x+m*f(k))mod n);
 fclose;
end.
