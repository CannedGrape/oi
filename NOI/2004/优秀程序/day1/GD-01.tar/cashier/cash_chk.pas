PROGRAM Joshua;
CoNsT
  mxn=100000;
VaR
  hs:array[1..mxn]of longint;
  n,min,tot,m,op,ind:longint;
  ch:char;
Procedure addnum;
  var
    i,j:longint;
  begin
    if op>=min then
    begin
      i:=m;
      while (i>0)and(op>hs[i]) do
        dec(i);
      for j:=m downto i+1 do
        hs[j+1]:=hs[j];
      hs[i+1]:=op;
      inc(m);
    end else inc(tot);
  end;
Procedure addmoney;
  var
    i:longint;
  begin
    for i:=1 to m do
      inc(hs[i],op);
  end;
Procedure decmoney;
  var
    i:longint;
  begin
    for i:=1 to m do
      dec(hs[i],op);
    while (m>0)and(hs[m]<min) do
    begin
      dec(m);
      inc(tot);
    end;
  end;
BeGiN
  assign(input,'cashier.in'); reset(input);
  assign(output,'cashier.std');rewrite(output);
  fillchar(hs,sizeof(hs),0);
  m:=0;
  readln(n,min);
  tot:=0;
  for n:=1 to n do
  begin
    readln(ch,op);
    case ch of
      'I':addnum;
      'A':addmoney;
      'S':decmoney;
      'F':if op>m then writeln(-1) else writeln(hs[op]);
    end;
  end;
  writeln(tot);
  close(input);
  close(output);
EnD.
