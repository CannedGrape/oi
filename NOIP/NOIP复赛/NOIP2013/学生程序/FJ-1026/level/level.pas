program level;
var a:array[1..1000,1..1000]of boolean; flag:boolean;
n,m,s,i,j,kk,q,z,l,ans:integer;
k:array[1..1000]of boolean; rd:array[1..1000]of integer;
begin
  assign(input,'level.in'); reset(input);
  assign(output,'level.out'); rewrite(output);
  readln(n,m); fillchar(a,sizeof(a),false);
  fillchar(rd,sizeof(rd),0); ans:=0;
  for i:=1 to m do
  begin
    fillchar(k,sizeof(k),false);
    read(s); read(q); k[q]:=true; l:=q-1;
    for j:=2 to s do begin read(z); k[z]:=true; end;
    for kk:=1 to s do
    begin
      inc(l); while not(k[l]) do inc(l);
      for j:=q to z do if not((k[j])or(a[l,j])) then
      begin a[l,j]:=true; inc(rd[j]); end;
    end;
  end;
  fillchar(k,sizeof(k),false);
  repeat
    for i:=1 to n do if rd[i]=0 then
    begin
      k[i]:=true;
      for j:=1 to n do if a[i,j] then
      begin a[i,j]:=false; dec(rd[j]); end;
    end;
    flag:=true;
    for i:=1 to n do flag:=(flag)and(k[i]);
    inc(ans);
  until flag;
  writeln(ans);
  close(input); close(output);
end.
