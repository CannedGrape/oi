var
  s:array[1..20] of string;
  t:string;
  i,j,k,n:longint;
begin
  write('n=');
  readln(n);
  for i:=1 to n do
  begin
    read(k);
    str(k,s[i]);
  end;
  readln;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if s[i]+s[j]<s[j]+s[i] then
      begin
        t:=s[i];
        s[i]:=s[j];
        s[j]:=t;
      end;
  for i:=1 to n do
    write(s[i]);
  writeln;
end.
