const
  maxn=66;
var
  f,s:array[1..maxn] of integer;
  i,j,k,g,n:integer;
begin
  write('n=');
  readln(n);
  fillchar(f,sizeof(f),0);
  fillchar(s,sizeof(f),0);
  f[maxn]:=1;
  for i:=1 to n do
  begin
    {f<-f*i}
    g:=0;
    for j:=maxn downto 1 do
    begin
      k:=f[j]*i+g;
      f[j]:=k mod 10;
      g:=k div 10;
    end;
    {s<-s+f}
    g:=0;
    for j:=maxn downto 1 do
    begin
      k:=s[j]+f[j]+g;
      s[j]:=k mod 10;
      g:=k div 10;
    end;
  end;
  for j:=1 to maxn do
    if s[j]<>0 then break;
  for i:=j to maxn do
    write(s[i]);
  writeln;
end.
