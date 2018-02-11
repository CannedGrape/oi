var ans,n,p,w:int64;
    i:longint;
    flag:boolean;
   a,f:array[0..1000000]of int64;
begin
assign(input,'number.in');
assign(output,'number.out');
reset(input);
rewrite(output);
  readln(n,p);
  w:=0;
  for i:=1 to n do
    begin
    read(a[i]);
    if w+a[i]>=a[i] then
      w:=w+a[i]
    else
      w:=a[i];
    f[i]:=w;
    end;
  ans:=f[1];
  w:=f[1]*2;
  if w>ans then flag:=true;
  for i:=2 to n-1 do
    begin
      if f[i]>0 then
      begin
      w:=w+f[i];
      if w>ans then flag:=true;
      if w>0 then w:=w mod p;
      end;
    end;

  if not flag then w:=ans;
  writeln(w mod p);
close(input);
close(output); 
end.




