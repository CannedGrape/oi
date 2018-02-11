const
  mo=99999997;
var
   a,b,aa,bb,p,f:array[1..100010]of longint;
   i,j,k,m,n,ans:longint;
procedure kp(l,r:longint);
var
  i,j,t,m:longint;
begin
   i:=l;j:=r;
   m:=a[(l+r) div 2];
   repeat
     while a[i]<m do inc(i);
     while a[j]>m do dec(j);
     if i<=j then
     begin
       t:=a[i];a[i]:=a[j];a[j]:=t;
       t:=b[i];b[i]:=b[j];b[j]:=t;
       inc(i);dec(j);
     end;
   until i>j;
   if i<r then kp(i,r);
   if j>l then kp(l,j);
end;
procedure kp1(l,r:longint);
var
  i,j,t,m:longint;
begin
   i:=l;j:=r;
   m:=aa[(l+r) div 2];
   repeat
     while aa[i]<m do inc(i);
     while aa[j]>m do dec(j);
     if i<=j then
     begin
       t:=aa[i];aa[i]:=aa[j];aa[j]:=t;
       t:=bb[i];bb[i]:=bb[j];bb[j]:=t;
       inc(i);dec(j);
     end;
   until i>j;
   if i<r then kp1(i,r);
   if j>l then kp1(l,j);
end;
procedure treegroup;
begin
   for i:=n downto 1 do
   begin

   end;
end;
procedure sqrn;
begin
   for i:=1 to n-1 do
     for j:=i+1 to n do
       if p[i]>p[j] then ans:=(ans+1) mod mo;
   writeln((ans+mo)mod mo);
end;
begin
assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
   readln(n);
   for i:=1 to n do
   begin
     read(a[i]);
     b[i]:=i;
   end;
   readln;
   for i:=1 to n do
   begin
     read(aa[i]);
     bb[i]:=i;
   end;
   kp(1,n);
   kp1(1,n);
   for i:=1 to n do p[b[i]]:=bb[i];
   ans:=0;
   sqrn;
   //if n<=1000 then sqrn else treegroup;
close(input);close(output);
end.
