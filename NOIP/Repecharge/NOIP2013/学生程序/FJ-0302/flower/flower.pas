program sfsaf;
var i,j,k,n,ans,i1:longint;
    h:array[1..100010]of longint;
    f:array[0..1,0..1000,0..1000]of longint;
 function max(xx,yy:longint):longint;
 begin
  if xx>yy then exit(xx) else exit(yy);
 end;
begin
 assign(input,'flower.in');
 reset(input);
 read(n);
 for i:=1 to n do
  read(h[i]);
 f[0,0,0]:=1;
 for i:=1 to n do
 begin
  i1:=i mod 2;
  fillchar(f[i1],sizeof(f[i1]),0);
  for J:=0 to i-1 do
   for k:=j to i-1 do
    if f[1-i1,j,k]<>0 then
     begin
      if j=0 then
       begin
        if k=0 then
         f[i1,0,i]:=max(f[1-i1,j,k]+1,f[i1,0,i])
        else
         begin
          if h[k]>h[i] then
            f[i1,k,i]:=max(f[1-i1,j,k]+1,f[i1,k,i])
           else
            f[i1,k,i]:=max(f[1-i1,j,k]+1,f[i1,k,i]);
         end;
       end
      else
       begin
        if (h[j]>h[k])and(h[i]>h[k]) then
         f[i1,k,i]:=max(f[1-i1,j,k]+1,f[i1,k,i]);
        if (h[j]<h[k])and(h[i]<h[k]) then
         f[i1,j,i]:=max(f[1-i1,j,k]+1,f[i1,k,i]);
       end;
      f[i1,j,k]:=max(f[1-i1,j,k],f[i1,j,k]);
     end;
 end;
 for i:=1 to n do
  for j:=i to n do
   ans:=max(ans,f[n mod 2,i,j]);
 assign(output,'flower.out');
 rewrite(output);
 write(ans-1);
 close(output);
end.
