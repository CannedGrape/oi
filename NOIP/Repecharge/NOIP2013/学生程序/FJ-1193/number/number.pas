const
  da=1000000001;
var
  i,j,n,p,ans,cun,zc:longint;
  shu,te,fen:array[-1000000..1000000]of longint;
procedure pai(x:longint);
begin
  for i:=1 to x do
  begin
   for j:=1 to i do
   zc:=zc+shu[j];
   if (zc<cun) and (cun<>0) then
   if cun>te[i] then te[i]:=cun else
   begin
     cun:=cun+shu[j];
     if cun>te[i] then te[i]:=cun;
   end;
  end;
  {for i:=1 to x do
  begin
    for j:=1 to i do
    if (cun+shu[j]<cun)and (cun<>0) then if cun>te[i] then te[i]:=cun
    else
    begin
      cun:=cun+shu[j];
      if cun>te[i] then te[i]:=cun;
    end;
  end;}
end;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p);
  for i:=1 to n do
  read(shu[i]);
  readln;
  ans:=-da;
  for i:=1 to n do
  begin
    fen[i]:=-da;
    te[i]:=-da;
  end;
  pai(n);
  for i:=1 to n do
  begin
    for j:=1 to i-1 do
    cun:=shu[j]+te[j];
    if cun>fen[i] then fen[i]:=cun;
  end;
  for i:=1 to n do
  if ans<fen[i] then ans:=fen[i];
  ans:=(ans mod p);
  writeln(ans);
  {for i:=1 to n do
  writeln(shu[i],' ',te[i],' ',fen[i]);}
  close(input); close(output);
end.