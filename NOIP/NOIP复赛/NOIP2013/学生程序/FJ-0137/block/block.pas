var
  ans,zxz,n,i,t,x,xx:longint;
  a:array[0..100000]of longint;
  dmax,dmin:array[0..100000]of longint;
function max(a,b:longint):longint;
begin
 if a>b then exit(b) else exit(a);
end;
begin
  assign(input,'block.in');reset(input);

  assign(output,'block.out');rewrite(Output);


  readln(n);   zxz:=100001;
  t:=1;
  for i:=1 to n do
   begin
    read(a[i]);
    if a[i]<zxz then zxz:=a[i];
   end;

  dmin[t]:=a[1];dmax[t]:=a[1];

  for i:=2 to n do
   begin
    x:=a[i];

     if x>=dmax[t] then
       dmax[t]:=x
     else
      if x<dmax[t] then
       if x>dmin[t] then continue
       else
       if x<=dmin[t] then
      begin
       inc(t);
       dmin[t]:=x;
       dmax[t]:=x;
      end;
   end;

  for i:=1 to t do
    ans:=ans+dmax[i]-dmin[i];

  if dmin[1]>dmin[2] then ans:=ans+(dmin[1]-dmin[2]);
  for i:=2 to t-1 do
   begin
    if (dmin[i]<dmin[i-1])and(dmin[i]<dmin[i+1]) then continue;

    if (dmin[i]>dmin[i-1])and(dmin[i]<=dmin[i+1]) then
     ans:=ans+dmin[i]-dmin[i-1];

    if (dmin[i]>dmin[i+1])and(dmin[i]<=dmin[i-1]) then
     ans:=ans+dmin[i]-dmin[i+1];

    if (dmin[i]>dmin[i-1])and(dmin[i]>dmin[i+1]) then
     begin
      xx:=max(dmin[i-1],dmin[i+1]);
      ans:=ans+dmin[i]-xx;
     end;

   end;

   if dmin[t]>dmin[t-1] then ans:=ans+dmin[t]-dmin[t-1];

  ans:=zxz+ans;
  writeln(ans);
  close(Input);close(output);
end.
