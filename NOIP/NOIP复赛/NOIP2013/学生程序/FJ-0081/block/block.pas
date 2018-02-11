var n,i,ans,max,decrease:longint;
    a,b:array[0..100000]of longint;
function maxs(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;
begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do
    read(a[i]);
  a[0]:=-maxlongint;
  for i:=1 to n do
    begin
      b[i]:=a[i];
      dec(b[i],decrease);
      if b[i]<0 then
        begin
          inc(decrease,b[i]);
          inc(ans,max);
          max:=0;
          continue;
        end;
      if b[i]>max then
        begin
          max:=b[i];
          decrease:=maxs(decrease,a[i]);
          continue;
        end;
      if b[i]<max then
        begin
          decrease:=a[i];
          inc(ans,max);
          max:=0;
        end;
      decrease:=maxs(decrease,a[i]);
    end;
  writeln(ans+max);
  close(input);
  close(output);
end.
