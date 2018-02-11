var
  s,o:ansistring;
  ans:qword; mm:qword; j,i,k,w,m:integer;
  a:array[1..5000]of integer;
  b:array[1..5000]of char;
procedure cl(q:char);
begin
      for j:=w to m do
        o:=o+s[j];
      val(o,mm);
      a[k]:=mm mod 10000;
      b[k]:=q;
      inc(k); w:=i+1;
end;
begin
  assign(input,'expr.in'); reset(input);
  assign(output,'expr.out'); rewrite(output);
  readln(s);
  k:=1;
  w:=1;
  for i:=1 to length(s) do
  begin
    m:=i-1;
    if s[i]='+' then  cl('+');
    if s[i]='*' then  cl('*');
    mm:=0;  o:='';
  end;
  for j:=w to length(s) do
        o:=o+s[j];
      val(o,mm);
      a[k]:=mm mod 10000;
  for i:=1 to k do
    if b[i]='*' then
    begin
      a[i+1]:=(a[i]*a[i+1])mod 10000;
      a[i]:=0;
    end;
  for i:=1 to k do
    ans:=(ans+a[i]) mod 10000;
  writeln(ans);
  close(input); close(output);
end.


