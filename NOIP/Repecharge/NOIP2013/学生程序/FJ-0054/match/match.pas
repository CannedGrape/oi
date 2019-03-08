
const p=99999997;
var
  n,i,m,o,j:longint;
  num:int64;
  a,b,ma,mb,aa,bb:array[0..100000] of int64;
procedure kpa(l,r:longint);
var i,j:longint;t,mid:int64;
begin
   i:=l;j:=r;mid:=a[(l+r)div 2];
   repeat
      while a[i]<mid do inc(i);
      while a[j]>mid do dec(j);
      if i<=j then
        begin
          t:=a[i];a[i]:=a[j];a[j]:=t;
          t:=ma[i];ma[i]:=ma[j];ma[j]:=t;
          inc(i);dec(j);
        end;
   until i>j;
   if i<r then kpa(i,r);
   if j>l then kpa(l,j);
end;
procedure kpb(l,r:longint);
var i,j:longint;mid,t:int64;
begin
   i:=l;j:=r;mid:=b[(l+r)div 2];
   repeat
      while b[i]<mid do inc(i);
      while b[j]>mid do dec(j);
      if i<=j then
        begin
          t:=b[i];b[i]:=b[j];b[j]:=t;
          t:=mb[i];mb[i]:=mb[j];mb[j]:=t;
          inc(i);dec(j);
        end;
   until i>j;
   if i<r then kpb(i,r);
   if j>l then kpb(l,j);
end;
begin
   assign(input,'match.in');reset(input);
   assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);readln;
  for i:=1 to n do ma[i]:=i;
  for i:=1 to n do read(b[i]);
  kpa(1,n);
  for i:=1 to n do aa[ma[i]]:=i;
  for i:=1 to n do mb[i]:=i;
  kpb(1,n);  for i:=1 to n do bb[mb[i]]:=i;
  for i:=1 to n do a[aa[i]]:=i;
  for i:=1 to n do
    if aa[i]<>bb[i] then
    begin
      o:=a[bb[i]];num:=(num+o-i) mod p;
      for j:=o downto i+1 do
        begin
           aa[j]:=aa[j-1]; a[aa[j-1]]:=j;
        end;
    end; writeln(num mod p);
   close(input);close(output);
end.
