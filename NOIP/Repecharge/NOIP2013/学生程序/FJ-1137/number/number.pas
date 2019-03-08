program number;
var
  i,j,k,n,x,max:longint;
  a,f,te,fen:array[-100..1000500]of longint;
  fu:boolean;
procedure pai(p,q:longint);
begin
  max:=1;
  for j:=p to q-1 do
  begin
    if fen[j]+te[j]>fen[max]+te[max] then
    begin
      max:=j;
    end;
  end;
end;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,x);
  for i:=1 to n do
  begin
    read(a[i]);
    fillchar(f,sizeof(f),0);
    for j:=1 to i do
    begin
      for k:=j to i do
      begin
        if f[j]<f[j]+a[k] then
        begin
          f[j]:=f[j]+a[k];
        end;
      end;
    end;
    max:=0;
    for j:=1 to i do
    begin
      if max<f[j] then max:=f[j];
    end;
    te[i]:=max;
  end;
  fu:=true;
  for i:=1 to n do
  begin
    if a[i]>=0 then fu:=false;
  end;
  if a[1]<0 then te[1]:=a[1];
  if fu then
  begin
    for i:=1 to n do
    begin
      te[i]:=a[i];
    end;
  end;

  fen[1]:=te[1];
  for i:=2 to n do
  begin
    pai(1,i);
    fen[i]:=te[max]+fen[max];
  end;

  max:=-$2f;
  for i:=1 to n do
  begin
    if max<fen[i] then max:=fen[i];
  end;
  writeln((max) mod x);
  close(input);
  close(output);
end.
