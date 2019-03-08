var f,b:array[0..110000,0..1,0..1] of longint;
ans,i,j,n:longint;
h:array[0..110000] of longint;

function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  read(h[i]);
  ans:=1;
  fillchar(f,sizeof(f),255);
  for i:=1 to n do
  for j:=0 to 1 do
  begin
    b[i,j,0]:=-maxlongint;
    b[i,j,1]:=maxlongint;
  end;
  b[1,0,0]:=maxlongint; b[1,0,1]:=-maxlongint;
  f[1,1,0]:=1; f[1,1,1]:=1;
  b[1,1,0]:=h[1]; b[1,1,1]:=h[1];
  f[1,0,0]:=0; f[1,0,1]:=0;
  for i:=2 to n do
  begin
    if f[i-1,0,0]<>-1 then
    begin
    f[i,0,0]:=f[i-1,0,0];
    if b[i-1,0,0]>h[i] then b[i,0,0]:=b[i-1,0,0] else b[i,0,0]:=h[i];
    end;
    if f[i-1,1,0]<>-1 then
    if (f[i-1,1,0]>f[i,0,0]) or ((f[i-1,1,0]=f[i,0,0]) and( b[i-1,1,0]>b[i,0,0]))  then
    begin
      f[i,0,0]:=f[i-1,1,0];
      b[i,0,0]:=b[i-1,1,0];
    end;

    if f[i-1,0,1]<>-1 then
    begin
    f[i,0,1]:=f[i-1,0,1];
    if b[i-1,0,1]<h[i] then b[i,0,1]:=b[i-1,0,1] else b[i,0,1]:=h[i];
    end;
    if f[i-1,1,1]<>-1 then
    if( f[i-1,1,1]>f[i,0,1]) or ((f[i-1,1,1]=f[i,0,1]) and (b[i-1,0,1]<b[i,0,1])) then
    begin
      f[i,0,1]:=f[i-1,1,1];
      b[i,0,1]:=b[i-1,1,1];
    end;

    if (f[i-1,1,1]<>-1) and (b[i-1,1,1]<h[i]) then
    begin
      f[i,1,0]:=f[i-1,1,1]+1;
      b[i,1,0]:=h[i];
    end;
    if (f[i-1,0,1]<>-1) and (b[i-1,1,1]<h[i])  and (f[i,1,0]<f[i-1,0,1]+1) then
    begin
      f[i,1,0]:=f[i-1,0,1]+1;
      b[i,1,0]:=h[i];
    end;

    if (f[i-1,1,0]<>-1)  and (b[i-1,1,0]>h[i]) then
    begin
      f[i,1,1]:=f[i-1,1,0]+1;
      b[i,1,1]:=h[i];
    end;
    if (f[i-1,0,0]<>-1) and (b[i-1,0,0]>h[i]) and (f[i,1,1]<f[i-1,0,0]+1) then
    begin
      f[i,1,1]:=f[i-1,0,0]+1;
      b[i,1,1]:=h[i];
    end;

    ans:=max(ans,f[i,1,0]);
    ans:=max(ans,f[i,1,1]);
  end;
  writeln(ans);
  close(input); close(output);
end.

