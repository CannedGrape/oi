var
   i,j,k,m,n:longint;
   ans:int64;
   a:array[0..100010]of longint;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
   readln(n);    a[0]:=0;
   for i:=1 to n do read(a[i]);
   ans:=0;
   for i:=1 to n do
     if a[i]-a[i-1]>0 then ans:=ans+a[i]-a[i-1];
   writeln(ans);
close(input);close(output);
end.
