var a,b,poa,pob,point,f:array[0..200000]of longint;
    i,j,k,n,m,tot,tt,x:longint;
    ans:longint;
procedure kp(l,r:longint);
var i,j,m,t:longint;
begin
 i:=l; j:=r;
 m:=a[(l+r)div 2];
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i<=j then
   begin
    t:=a[i]; a[i]:=a[j]; a[j]:=t;
    t:=poa[i]; poa[i]:=poa[j]; poa[j]:=t;
    inc(i);
    dec(j);
   end;
 until i>j;
 if i<r then kp(i,r);
 if l<j then kp(l,j);
end;
procedure kp1(l,r:longint);
var i,j,m,t:longint;
begin
 i:=l; j:=r;
 m:=b[(l+r)div 2];
 repeat
  while b[i]<m do inc(i);
  while b[j]>m do dec(j);
  if i<=j then
   begin
    t:=b[i]; b[i]:=b[j]; b[j]:=t;
    t:=pob[i]; pob[i]:=pob[j]; pob[j]:=t;
    inc(i);
    dec(j);
   end;
 until i>j;
 if i<r then kp1(i,r);
 if l<j then kp1(l,j);
end;

begin
assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
   read(a[i]);
   poa[i]:=i;
  end;  readln;
 for i:=1 to n do
  begin
   read(b[i]);
   pob[i]:=i;
  end;  readln;
 kp(1,n);
 kp1(1,n);
 for i:=1 to n do
   begin
    point[poa[i]]:=pob[i];
   end;
 for i:=n downto 1 do
  begin
   x:=point[i]-1;
   while x>0 do
    begin
      ans:=(ans+f[x])mod 99999997;
      x:=x- (x and (-x));
    end;
   x:=point[i];
   while x<=n do
    begin
     f[x]:=f[x]+1;
     x:=x+ (x and (-x));
    end;
  end;

 writeln((ans+99999997)mod 99999997);
 close(input); close(output);
end.