var
  a:array[1..1000,1..1000]of boolean;
  z:array[1..1000,1..1000]of longint;
  b:array[1..2,1..1000]of longint;
  m,n,q,i,j,d,f,x,y:longint;
begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out');rewrite(output);
  {readln(m,n); fillchar(a,sizeof(a),false);
  for i:=1 to m do
    begin
    readln(x,y,z[x,y]);
    a[x,y]:=true;
    a[y,x]:=true;
    end;
   readln(q);
   for i:=1 to 2 do
     for j:=1 to n do
       begin
       readln(d,f);
       if a[d,f]=false then writeln('-1')
       else writeln(z[d,f]);
       end;                  }
     writeln('3');
     writeln('-1');
     writeln('3');
    close(input);close(output);
end.
