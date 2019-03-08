var
  max,total,q,n,m,j,k,i,l,r,v:longint;
  a:array[1..1000] of boolean;
  b:array[1..1000,1..1000] of boolean;
procedure doing(x:integer);
var
  i:integer;
begin
  for i:=1 to q do
    if (i<>x) and b[x,i] then
      begin
        total:=total+1;
        if total>max then
          max:=total;
        if max>=q then
          begin
            halt;write(max);
            close(input);
            close(output);
          end;
        doing(i);
        total:=total-1;
      end;
end;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  max:=1;total:=1;
  readln(q,n);
  for i:=1 to n do
    begin
      fillchar(a,sizeof(a),false);
      read(m);
      for j:=1 to m do
        begin
          read(v);
          if j=1 then l:=v;
          if j=m then r:=v;
          a[v]:=true;
        end;
      for j:=l to r do
        for k:=l to r do
          if (a[j]=true) and (a[k]=false) then
            b[j,k]:=true;
    end;
  for i:=1 to q do
    doing(i);
  write(max);
  close(input);
  close(output);
end.