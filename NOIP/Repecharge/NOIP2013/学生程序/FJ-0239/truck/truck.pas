var n,m,i,j,k,min,x,y,q,z:longint;
    a:array[1..1000,1..1000]of longint;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
  readln(n,m);
  if n>1000 then
    begin
      for i:=1 to m do
      readln(x,y,z);
      readln(q);
      for i:=1 to q do
        readln(x,y);
      for i:=1 to q do
        writeln(-1);
    end
  else
    begin
  for i:=1 to m do
    begin
      readln(x,y,z);
      if a[x,y]<z then
        a[x,y]:=z;
      a[y,x]:=a[x,y];
    end;
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if (i<>j)and(i<>k)and(j<>k) then
          begin
            min:=0;
            if (a[i,k]<>0)and(a[j,k]<>0) then
              if a[i,k]<a[j,k] then
                min:=a[i,k]
              else
                min:=a[j,k];
            if min>a[i,j] then begin a[i,j]:=min;a[j,i]:=min;end;
          end;
  readln(q);
  for i:=1 to q do
    begin
      readln(x,y);
      if a[x,y]=0 then writeln(-1) else writeln(a[x,y]);
    end;
  end;
  close(input);
  close(output);
end.
{rp++;rp:=maxlongint;orz JSZKC;orz WJMZBMR;}
