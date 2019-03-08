program block;
var a:array[1..100000] of longint;
    i,m,n,h,j,k,g,f,l,s,max,t:longint;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
max:=-maxint;
readln(n);
k:=1;
for i:=1 to n do
read(a[i]);
for i:=1 to n do if a[i]>max then begin max:=a[i];f:=f+(max-a[i]);end;
for i:=1 to n-1 do
 begin
  if (a[i]=a[i+1])   then begin k:=k+1;l:=i;end;
  if (f=0) and (k>1) and (a[i]=1) then k:=k div l;
  if (f=0) and (k>1) and(a[i]>1) then k:=a[i];
 end;
if (a[i]>a[i+1]) then if a[i]-f=a[i+1] then k:=a[i]-f;
if (a[i]<a[i+1]) then if a[i]=a[f+1]-f then k:=a[i+1]-f;
  for i:=1 to n-1 do
   begin
   if (a[i]-k<>a[i+1]-k) then
    begin
     s:=s+1;
     t:=abs(a[1]-a[1+s])+t;
    end;
   end;


writeln(k+t);
close(input);close(output);
end.
