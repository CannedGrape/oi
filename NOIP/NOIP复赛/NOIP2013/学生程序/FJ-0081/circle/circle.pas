var n,m,k,x,i,find:longint;
    ss:int64;
    a:array[1.. 1000000]of longint;
    hash:array[0..999999]of longint;
procedure working(looking,last:longint);
begin
  last:=last mod looking;
  if last=0 then last:=looking;
  writeln((a[last+hash[m]]+x)mod n);
  close(input);
  close(output);
  halt;
end;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  read(n,m,k,x);
  for i:=1 to 999999 do hash[i]:=-1;
  for i:=1 to k do
    begin
      m:=(m*10) mod n;
      a[i]:=m;
      if hash[m]>0 then
          working(i-hash[m],k-hash[m]);
      hash[m]:=i;
    end;
  writeln((a[k]+x)mod n);
  close(input);
  close(output);
end.
