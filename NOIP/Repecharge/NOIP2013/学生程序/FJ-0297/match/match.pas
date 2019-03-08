{$R+,S+,Q+}
var dis:array[1..1000000] of integer;
    aff:array[1..1000000] of integer;
    a,b:array[1..1000000] of longint;
    na,nb,f:array[1..1000000] of integer;
    i,n,ans:longint;

procedure qsort1(l,r:longint);
 var i,j,x,y:longint;
 begin
  i:=l;j:=r;x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if not(i>j) then
     begin
      y:=a[i];a[i]:=a[j];a[j]:=y;
      y:=na[i];na[i]:=na[j];na[j]:=y;
      inc(i);dec(j);
     end;
  until i>j;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
 end;

procedure qsort2(l,r:longint);
 var i,j,x,y:longint;
 begin
  i:=l;j:=r;x:=b[(l+r) div 2];
  repeat
    while b[i]<x do inc(i);
    while x<b[j] do dec(j);
    if not(i>j) then
     begin
      y:=b[i];b[i]:=b[j];b[j]:=y;
      y:=nb[i];nb[i]:=nb[j];nb[j]:=y;
      inc(i);dec(j);
     end;
  until i>j;
  if l<j then qsort2(l,j);
  if i<r then qsort2(i,r);
 end;

function check:boolean;
 var i:longint;
 begin
  for i:=1 to n do
   if dis[i]<>0 then exit(false);
  exit(true);
 end;

procedure work;
 var max,mn,x:longint;
 begin
   while not(check) do
    begin
      max:=0;
      for i:=1 to n-1 do
       if aff[i]>=max then
        begin
          max:=dis[i];
          mn:=i;
        end;
      x:=f[mn];f[mn]:=f[mn+1];f[mn+1]:=x;
      dis[mn]:=abs(mn-f[mn]);
      dis[mn+1]:=abs(mn+1-f[mn+1]);
      aff[mn]:=0;
      if f[mn]>mn then inc(aff[mn]);
      if f[mn]<mn then dec(aff[mn]);
      if f[mn+1]>mn+1 then dec(aff[mn]);
      if f[mn+1]<mn+1 then inc(aff[mn]);
      aff[mn+1]:=0;
      if f[mn+1]>mn+1 then inc(aff[mn+1]);
      if f[mn+1]<mn+1 then dec(aff[mn+1]);
      if f[mn+2]>mn+2 then dec(aff[mn+1]);
      if f[mn+2]<mn+2 then inc(aff[mn+1]);
      inc(ans);
      ans:=ans mod 99999997;
    end;
end;

begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
   begin
     read(a[i]);
     na[i]:=i;
   end;
  readln;
  for i:=1 to n do
   begin
     read(b[i]);
     nb[i]:=i;
   end;
  qsort1(1,n);
  qsort2(1,n);
  for i:=1 to n do
   begin
     f[na[i]]:=nb[i];
     dis[na[i]]:=abs(na[i]-nb[i]);
   end;
  for i:=1 to n do
   begin
     aff[na[i]]:=0;
     if f[na[i]]>na[i] then inc(aff[na[i]]);
     if f[na[i]]<na[i] then dec(aff[na[i]]);
     if f[na[i]+1]>na[i]+1 then dec(aff[na[i]]);
     if f[na[i]+1]<na[i]+1 then inc(aff[na[i]]);
   end;
  ans:=0;
  work;
  write(ans);
  close(input);close(output);
end.

