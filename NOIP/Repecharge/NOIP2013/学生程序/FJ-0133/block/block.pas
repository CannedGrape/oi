program exm1;
var n,i,ans,m,j:longint;
a:array[1..100000] of integer;
procedure firs;
begin
 readln(n);
 ans:=0;
 m:=0;
  for i:=1 to n do
     read(a[i]);
       end;

procedure main;
begin
        for i:=1 to n do
        for j:=n-1 downto 2 do
        if   a[i]>a[j]   then
           begin
             ans:=a[i];
             a[i]:=a[j];
             a[j]:=ans;
             m:=m+1;
        end;
end;

procedure anm;
begin

        writeln(m);
        readln;
end;
begin
{assign(input,'block.pas');
reset(input);
assign(output,'block.pas');
rewrite(output);}
  firs;
  main;
  anm;
 { close(input);
  close(output);}
end.
