var n,i,ans,k:longint;a,b:array[1..100001]of longint;

begin
assign(input,'flower.in');
reset(input);
assign(output,'flower.out');
rewrite(output);
  readln(n);
  for i:=1 to n do  read(a[i]);
  ans:=2;k:=2;
  while a[k]=a[1] do k:=k+1;
  if a[1]>a[k] then b[1]:=1 else b[1]:=2;


  for i:=2 to n do begin
         if a[i]=a[i-1] then b[i]:=b[i-1];
         if a[i]<a[i-1] then b[i]:=1;
         if a[i]>a[i-1] then b[i]:=2;
  end;
   for i:=2 to n do begin
      if b[i]<>b[i-1] then inc(ans);
   end;
   write(ans);
close(input);
close(output);
end.
