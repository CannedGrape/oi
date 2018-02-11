var
  n,i,t:longint;
  a:array[1..100000]of longint;
procedure go(l,r:longint);
  var b,m:longint;
  begin
    if l<=r then
      if l=r then t:=t+a[l]
        else
          begin
            b:=l;
            for i:=l+1 to r do
              if a[i]<a[b] then b:=i; m:=a[b];  t:=t+m;
            for i:=l to r do a[i]:=a[i]-m;
            go(l,b-1); go(b+1,r);
          end;
  end;
begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input); rewrite(output);
  readln(n);  t:=0;
  for i:=1 to n do read(a[i]);
  go(1,n);  writeln(t);
  close(input); close(output);
end.
