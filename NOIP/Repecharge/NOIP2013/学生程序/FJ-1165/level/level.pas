var
  n,m,i,x,y,j,ans,t,k:integer;
  a:array[1..1005,1..1005] of boolean;
  b:array[1..1005] of integer;
  c:array[1..1005] of record
  s,g:integer;
  end;
begin
  assign(input,'level.in');
  assign(output,'leve.out');
  reset(input);
  rewrite(output);
  fillchar(a,sizeof(a),true);
  fillchar(b,sizeof(b),0);
  ans:=1;
  read(n,m);
  for i:=1 to m do
  begin
    read(x);
    for j:=1 to x do
    begin
      read(y);
      if j=1 then c[i].s:=y;
      if j=x then c[i].g:=y;
      a[i,y]:=false;
    end;
  end;

  for k:=1 to n-1 do
  begin
    for i:=1 to m do
    begin
      t:=0;
      for j:=c[i].s to c[i].g do
      begin
        if (a[i,j]=false) and (b[j]>t) then t:=b[j];
        if (a[i,j]) and (b[j]<=t) then begin b[j]:=t+1; if b[j]>=ans then inc(ans); end;
      end;
    end;
  end;

  writeln(ans);
  close(input);
  close(output);
end.
