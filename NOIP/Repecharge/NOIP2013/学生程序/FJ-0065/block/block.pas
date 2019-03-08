var h:array[0..100000]of longint;
    i,j,k,n,m,ans:longint;bo:boolean;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  for i:=1 to n do
   begin
    if h[i]=0 then continue;

    repeat
     m:=h[i];
     if m=0 then break;
     j:=i+1;
     while j<=n do
      begin
       if h[j]<m then m:=h[j];
       if m=0 then
        break;
       inc(j);
      end;
     for k:=i to j-1 do h[k]:=h[k]-1;
     inc(ans);
    until false;

   end;
  writeln(ans);
close(input); close(output);
end.
