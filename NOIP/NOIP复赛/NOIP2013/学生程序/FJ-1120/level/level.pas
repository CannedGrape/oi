var
  a,s,q:array[1..2000] of longint;
  tra:array[1..2000,1..2000] of longint;
  n,m,i,j,k,ma,ans,rans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'level.in'); reset(input);
  assign(output,'level.out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do a[i]:=1;
  ans:=1;
  for i:=1 to m do
    begin
      read(s[i]);
      for j:=1 to s[i] do
        read(tra[i,j]);
      readln;
    end;
  for i:=1 to m do
    begin
      ma:=0; k:=1;
      for j:=tra[i,1] to tra[i,s[i]] do
        if j<>tra[i,k] then
          ma:=max(ma,a[j])
        else
          inc(k);
      inc(ma);
      for j:=1 to s[i] do
        a[tra[i,j]]:=max(a[tra[i,j]],ma);
      ans:=max(ans,ma);
    end;
  fillchar(q,sizeof(q),0);
  for i:=1 to n do
    inc(q[a[n]]);
  rans:=ans;
 { for i:=1 to ans do
    if q[i]=0 then dec(rans);}
  writeln(rans);
  close(input); close(output);
end.
