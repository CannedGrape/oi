var
  s,l:ansistring;
  a:array[1..100000] of longint;
  fh:array[1..100000] of char;
  q:array[1..100000] of longint;
  n,i,ans,m:longint;
begin
  assign(input,'expr.in'); reset(input);
  assign(output,'expr.out'); rewrite(output);
  readln(s);
  l:='';
  n:=1;
  while length(s)<>0 do
    begin
      if (s[1]<>'+') and (s[1]<>'*') then
        l:=l+s[1]
      else
        begin
          val(l,a[n]);
          a[n]:=a[n] mod 10000;
          fh[n]:=s[1];
          inc(n);
          l:='';
        end;
      delete(s,1,1);
    end;
  val(l,a[n]);
  a[n]:=a[n] mod 10000;
  m:=1;
  for i:=2 to n do
    begin
      if fh[i-1]='*' then
        a[i]:=(a[i-1]*a[i]) mod 10000
      else
        begin
          q[m]:=a[i-1];
          inc(m);
        end;
    end;
  q[m]:=a[n];
  ans:=0;
  for i:=1 to m do
    ans:=ans+q[i];
  writeln(ans mod 10000);
  close(input); close(output);
end.
