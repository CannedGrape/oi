const
  fin='car10.in';
var
  fi:text;
  c,m,w,i,j:integer;
  a:array[1..50]of integer;
begin
  assign(fi,fin);
  reset(fi);
  readln(fi,c,m,w);
  fillchar(a,sizeof(a),0);
  for i:=1 to c do
    begin
      read(fi,j);
      if j<1 then write('error ',j);
      if j>m then write('error ',j);
      inc(a[j]);
    end;
  for i:=1 to m do
    if a[i]=0 then write('error: no ',i);
  writeln;
  close(fi);
  writeln(fin,' OK!');
end.
