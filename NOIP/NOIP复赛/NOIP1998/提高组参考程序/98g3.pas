var
  t:array[0..8,0..8] of string[2];
  v:array['A'..'Z'] of integer;
  s:string;
  c,c2:char;
  i,j,n,p,k,tot:integer;

procedure error;
begin
  writeln('ERROR!');
  halt;
end;

begin
  for c:='A' to 'Z' do
    v[c]:=-1;
  write('N=');
  readln(n);
  k:=n-1;
  for i:=0 to n-1 do
  begin
    readln(s);
    s:=s+' ';
    c:=s[1];
    if i<>0 then v[c]:=0;
    for j:=0 to n-1 do
    begin
      while s[1]=' 'do delete(s,1,1);
      p:=pos(' ',s);
      t[i,j]:=copy(s,1,p-1);
      if p=3 then inc(v[c]);
      delete(s,1,p);
    end;
  end;

  tot:=0;
  for c:='A' to 'Z' do
    if v[c]<>-1 then inc(tot);
  if tot<>k then error;

  for c:='A' to 'Y' do
    for c2:=succ(c) to 'Z' do
      if (v[c]<>-1)and(v[c]=v[c2]) then error; {equal}
  {check}
  for i:=1 to k do
    for j:=1 to k do
    begin
      if length(t[i,j])=2 then
        p:=v[t[i,j,1]]*k+v[t[i,j,2]]
      else
        p:=v[t[i,j,1]];
      if v[t[i,0,1]]+v[t[0,j,1]]<>p then
        error;
    end;
  for c:='A' to 'Z' do
    if v[c]<>-1 then write(c,'=',v[c],' ');
  writeln;
  writeln('RADIX=',k);
end.
