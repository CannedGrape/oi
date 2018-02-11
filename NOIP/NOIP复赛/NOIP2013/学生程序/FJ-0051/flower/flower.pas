var
   f,ff:array[0..100010,1..2]of longint;
   i,j,k,m,n,ans:longint;
   a:array[0..100010]of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
procedure sqrn;
begin
   f[1,2]:=-maxlongint;
   ff[1,2]:=-maxlongint;
   for i:=1 to n do ff[i,1]:=1;
   for i:=1 to n do f[i,1]:=1;
   for i:=2 to n do
   begin
     for j:=1 to i-1 do
     begin
       if a[j]>a[i] then
       begin
         f[i,1]:=max(f[i,1],f[j,2]+1);
         ff[i,2]:=max(ff[i,2],ff[j,1]+1);
       end;
       if a[j]<a[i] then
       begin
         f[i,2]:=max(f[i,2],f[j,1]+1);
         ff[i,1]:=max(ff[i,1],ff[j,2]+1);
       end;
       if f[i,1]>ans then ans:=f[i,1];
       if f[i,2]>ans then ans:=f[i,2];
       if ff[i,1]>ans then ans:=ff[i,1];
       if ff[i,2]>ans then ans:=ff[i,2];
     end;
   end;
   writeln(ans);
end;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
   readln(n);
   if n=1 then
   begin
     writeln('1');
     close(input);close(output);
     halt;
   end;
   for i:=1 to n do read(a[i]);
   ans:=0;
   sqrn;
close(input);close(output);
end.
