var
  n,i,j,k,tot,m:longint;
  h:array[1..100000]of longint;
  b:array[1..100000]of boolean;

begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    b[i]:=true;
    read(h[i]);
  end;
  repeat
    k:=0; m:=0;
    for i:=1 to n do
    begin

      if b[i] then
      begin
        h[i]:=h[i]-1;
        k:=k+1;
      end;

      if (k<>0)and(b[i]=false) then
      begin
        tot:=tot+1;
        break;
      end;
      if b[i]=false then
        m:=m+1;
      if h[i]=0 then
        b[i]:=false;

    end;
    if (k+m=n) then
     tot:=tot+1;
  until k=0;
  writeln(tot-1);
  close(input); close(output);
end.
