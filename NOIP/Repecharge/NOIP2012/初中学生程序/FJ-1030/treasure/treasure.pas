program treasure;
var n,m,i,j,t,k,ans:longint;
   a:array[0..10000,0..100,1..2]of longint;
   b:array[0..10000]of longint;
begin
 assign(input,'treasure.in');reset(input);
 assign(output,'treasure.out');rewrite(output);
 readln(n,m);
 for i:=1 to n do
 for j:=0 to m-1 do
  begin
   readln(a[i,j,1],a[i,j,2]);
   a[i,j,2]:=a[i,j,2]mod 20123;
   if a[i,j,1]=1 then inc(b[i]);
  end;
 readln(t);
 ans:=0;
 for i:=1 to n do
 begin
  ans:=(ans+a[i,t,2])mod 20123;
  if a[i,t,1]=0 then
  begin
   k:=a[i,t,2]mod b[i];
   if k=0 then k:=b[i];
   while k>0 do
   begin
    t:=(t+1)mod m;
    if a[i,t,1]=1 then dec(k);
   end;
  end;
 end;
 writeln(ans);
 close(input);close(output);
end.
