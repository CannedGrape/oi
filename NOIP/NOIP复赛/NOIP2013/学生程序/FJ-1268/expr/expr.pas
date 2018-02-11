program s2;
var
  s,g:string;
  i,p,a1,b1,aa:longint;
  a:array[1..100001] of string;
  b:array[1..100001] of string;
  c:array[1..100001] of longint;
  t:int64;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  read(s);
  p:=length(s);
  for i:=1 to length(s) do
    c[i]:=-1;
  for i:=1 to p do
    if (s[i]='+') or (s[i]='*')
    then
      begin
        if aa>0 then
          begin inc(a1); a[a1]:=copy(s,i-aa,aa); aa:=0; end;
        inc(b1); b[b1]:=s[i];
      end
    else
      begin
        inc(aa);
        if i=p then
          begin inc(a1); a[a1]:=copy(s,i-aa+1,aa); aa:=0; end;
      end;
  for i:=1 to a1 do
    val(a[i],c[i]);
  for i:=1 to b1 do
    if b[i]='*' then begin c[i]:=c[i]*c[i+1]; c[i+1]:=0; end;
  for i:=1 to a1 do
    if c[i]<>-1 then t:=t+c[i];
  writeln(t mod 10000);
  close(input);
  close(output);
end.