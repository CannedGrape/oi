var
    ans:int64;
    max,i,j,n:longint;
    f:array[0..200000,1..2] of int64;
    h:array[0..200000] of longint;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input); rewrite(output);
   readln(n);
   for i:=1 to n do
  begin
   read(h[i]);
   if h[i]>max then max:=h[i];
  end;

   fillchar(f,sizeof(f),0);
   for j:=1 to h[1] do
  begin
   f[j,2]:=1;
   f[j,1]:=1;
   inc(ans);
  end;

   for i:=2 to n  do
   begin
    for j:=1 to h[i] do
    begin
    if f[j,2]<>i-1 then
   begin
    inc(f[j,1]);
    inc(ans);
   end;
    f[j,2]:=i;
    end;

   end;
   writeln(ans);



close(input); close(output);
end.
