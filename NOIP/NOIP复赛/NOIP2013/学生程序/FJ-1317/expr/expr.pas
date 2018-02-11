program expr;
var a,b,c,he,he1,he2,he3,shu1,shu2,shu3,code,p,q:longint;
    n,m,o,r:string;
    x:array[1..10000] of longint;y:array[1..10000] of longint;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  read(n); p:=1;q:=1;
  for a:=1 to length(n) do
    begin
      if n[a]='+' then begin x[p]:=a; p:=p+1; end;
      if n[a]='*' then begin y[q]:=a; q:=q+1; end;
    end;
  for a:=1 to length(n) do
    begin
      m:=copy(n,1,x[1]-1);val(m,shu1,code);he1:=shu1+shu1;
      o:=copy(n,1,y[1]-1);val(o,shu2,code);
      r:=copy(n,1,y[1]+1);val(r,shu3,code);
      he2:=shu2*shu3;
    end;
    he3:=he1+he2;

  write(he3);
  close(input);close(output);
end.
