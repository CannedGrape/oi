var
  ans,t,i,n,o,x:longint;
  b,b1,a1,a2:array[1..100000]of longint;
  c:array[1..100000,1..2]of longint;
procedure pai1(o,p:longint);
begin
  while o+o<=p do
    begin
      o:=o+o;
      if (o<p)and(a1[o]<a1[o+1]) then inc(o);
      if a1[o]>a1[o shr 1] then
        begin
          b[b1[o]]:=o shr 1;b[b1[o shr 1]]:=o;
          x:=b1[o];b1[o]:=b1[o shr 1];b1[o shr 1]:=x;
          x:=a1[o];a1[o]:=a1[o shr 1];a1[o shr 1]:=x;
        end else break;
    end;
end;
procedure pai2(o,p:longint);
begin
  while o+o<=p do
    begin
      o:=o+o;
      if (o<p)and(a2[o]<a2[o+1]) then inc(o);
      if a2[o]>a2[o shr 1] then
        begin
          c[c[o,2],1]:=i;c[c[o shr 1,2],1]:=1;
          x:=c[o,2];c[o,2]:=c[o shr 1,2];c[o shr 1,2]:=x;
          x:=a2[o];a2[o]:=a2[o shr 1];a2[o shr 1]:=x;
        end else break;
    end;
end;


begin
assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
  read(n);
  for i:=1 to n do begin read(a1[i]);b[i]:=i;b1[i]:=i;end;
  for i:=1 to n do begin read(a2[i]);c[i,1]:=i;c[i,2]:=i;end;

  for i:=n div 2 downto 1 do pai1(i,n);
  for i:=n downto 2 do
    begin
      b[b1[1]]:=i;b[b1[i]]:=1;
      o:=b1[1];b1[1]:=b1[i];b1[i]:=o;
      o:=a1[1];a1[1]:=a1[i];a1[i]:=o;
      pai1(1,i-1);
    end;


  for i:=n div 2 downto 1 do pai2(i,n);
  for i:=n downto 2 do
    begin
      c[c[1,2],1]:=i;c[c[i,2],1]:=1;
      o:=c[1,2];c[1,2]:=c[i,2];c[i,2]:=o;
      o:=a2[1];a2[1]:=a2[i];a2[i]:=o;
      pai2(1,i-1);
    end;
  for i:=1 to n do
  if c[i,1]<>b[i]then
    begin
      x:=i;t:=c[b[i],2];
      repeat
        ans:=(ans mod 99999997)+1;
        o:=c[t,1];c[t,1]:=c[x,1];c[x,1]:=o;
        o:=c[c[t,1],2];c[c[t,1],2]:=c[c[x,1],2];c[c[x,1],2]:=o;
        o:=x;x:=t;t:=c[b[c[c[t,1],2]],2];
      until t=x;
    end;
    write(ans);
close(input);close(output);
end.
