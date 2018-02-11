var n,x,l,t,i:longint;
    k:string;
    a:char;
 procedure sk(m:longint);
 begin
   if k[m]=a then inc(t);
   if m=1 then exit;
   sk(m-1);
 end;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n,x);
  a:=chr(x+48);
  for i:=1 to n do
  begin
    str(i,k);
    l:=length(k);
    sk(l);
  end;
  writeln(t);
  close(input);close(output);
end.
