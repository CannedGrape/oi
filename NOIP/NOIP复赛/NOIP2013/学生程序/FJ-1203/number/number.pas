var
  shu:array[1..1000000]of longint;
  te:array[1..1000000]of longint;
  fen:array[1..1000000]of longint;
  n,p,i,j,k,c,m,q:longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(shu[i]);
  te[1]:=shu[1];
  for i:=2 to n do
  for j:=1 to i do begin
    for k:=j to i do c:=shu[k]+c;
    if c>te[i]then te[i]:=c;
    c:=0;
  end;
  fen[1]:=shu[1];
  fen[2]:=fen[1]+te[1];
  m:=fen[1];
  q:=fen[2]+te[2];
  for i:=3 to n do begin
    if m>q then begin
      fen[i]:=m;
      q:=fen[i]+te[i];
    end else begin
      fen[i]:=q;
      m:=fen[i]+te[i];
    end;
  end;
  writeln(fen[n] mod p);
  close(input);
  close(output);
end.
