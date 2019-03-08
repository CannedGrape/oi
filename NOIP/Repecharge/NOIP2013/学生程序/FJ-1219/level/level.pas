program ex4;
  var j,i,n,m,a,b,maxx,maxx1:longint;
      l,f:array[0..1000] of longint;
      ff:array[0..1000] of boolean;
  function max(c,d:longint):longint;
    var i:longint;
    begin
    max:=0;
    for i:=c to d do
      if (l[i]>max) and (ff[i]) then max:=l[i];
    end;
  begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  read(n,m);
  for i:=1 to n do
    l[i]:=1;
  for i:=1 to m do
    begin
    read(a);
    fillchar(f,sizeof(f),0);
      fillchar(ff,sizeof(ff),true);
    for j:=1 to a do
      begin
      read(f[j]);
      ff[f[j]]:=false;
      end;
    maxx:=max(f[1],f[a]);
    for j:=1 to a do
    if l[f[j]]<maxx+1 then
      l[f[j]]:=maxx+1;
    end;
    fillchar(ff,sizeof(ff),true);
  maxx1:=max(1,n);
  write(maxx1);
  close(input);
  close(output);
  end.