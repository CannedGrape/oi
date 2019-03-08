var s:ansistring;
p:shortstring;
i,l,j,k,sum:longint;
a:array[1..100000,1..1000]of shortint;
b,c:array[1..100000]of longint;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  while not eoln do
    begin
      inc(l);
      read(s[l]);
      if (ord(s[l])>=48)and(ord(s[l])<=59)then
        p:=p+s[l]
      else
        begin
          inc(k);
          for i:=1 to length(p) do
            val(p[i],a[k,length(p)-i+1]);
          del(s,p);
        end;
    end;
  for i:=1 to k do
    b[i]:=a[i,1]+10*a[i,2]+100*a[i,3]+1000*a[i,4];
  i:=pos(s,'*');
  while i<>0 do
    begin
      c[i]:=b[i]*b[i+1]mod 10000;
      for j:=i to k do
        begin
          b[j]:=b[j+1];
          s[j]:=s[j+1];
        end;
      dec(k);
      i:=pos(s,'*');
    end;
  for i:=1 to k do
    if c[i]=0 then
      c[i]:=b[i];
  for i:=1 to k do
    begin
      sum:=c[i]+sum;
      if sum>=10000 then sum:=sum mod 10000;
    end;
  writeln(sum);
  close(input);
  close(output);
end.
