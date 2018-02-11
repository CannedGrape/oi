var
  n:ansistring;
  a,b:string;
  i,j,k,s,c,d,aa,bb:longint;
  kao:array[1..10000] of longint;
  pd:array[1..10000] of boolean;
  max:int64;
begin
  readln(n);
  for i:=1 to length(n) do
  begin
    c:=i;
    d:=i;
    if n[i]='*' then
    begin
      s:=s+1;
      while (n[c-1]<>'*') and (n[c-1]<>'+') do
      begin
        pd[c]:=false;
        dec(c);
      end;
      for j:=c to i-1 do
        a:=a+n[j];
      while (n[d+1]<>'*') and (n[d+1]<>'+') do
      begin
        b:=b+n[d+1];
        pd[d]:=false;
        inc(d);
      end;
      ord(a,aa);
      ord(b,bb);
      kao[s]:=aa*bb;
      a:='';
      b:='';
    end;
    if n[i]='+' then
    begin
      s:=s+1;
      while (n[c-1]<>'+') and (n[c-1]<>'*') and (pd[c-1]=false) do
      begin
        dec(c);
      end;
      for j:=c to i-1 do
        a:=a+n[j];
      ord(a,aa);
      kao[s]:=kao[s]+aa;
      a:='';
    end;
  end;
  for i:=1 to 10000 do
    write(kao[i],' ');
end.
