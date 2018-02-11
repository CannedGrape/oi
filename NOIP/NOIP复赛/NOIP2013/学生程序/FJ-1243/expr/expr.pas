program dsf;
var a:array[1..100001]of longint;
b:array[-1..100000]of char;
c:array[1..100001]of longint;
d:array[1..11]of integer;
i,j,k,ans,n,m,x,l,r:longint;
h:char;
begin
   assign(input,'expr.in');reset(input);
   assign(output,'expr.out');rewrite(output);
   n:=1;
   x:=1;
   read(h);
   while (48<=ord(h))and(ord(h)<=ord('9')) do
   begin
      l:=l+1;
      d[l]:=((ord(h)-48) mod 10000);
      read(h);
   end;
   for j:=l downto 1 do
   begin
      a[n]:=a[n]+d[j]*x;
      a[n]:=a[n] mod 10000;
      x:=x*10;
      r:=r+1;
      if r>=4 then break;
   end;
   x:=1;
   l:=0;
   r:=0;
   a[n]:=a[n]mod 10000;
   while not eof do
   begin
      b[n]:=h;
      inc(n);
      read(h);
      while (48<=ord(h))and(ord(h)<=ord('9')) do
   begin
      l:=l+1;
      d[l]:=((ord(h)-48) mod 10000);
      read(h);
   end;
   for j:=l downto 1 do
   begin
      a[n]:=a[n]+d[j]*x;
      a[n]:=a[n] mod 10000;
      x:=x*10;
      r:=r+1;
      if r>=4 then break;
   end;
   x:=1;
   l:=0;
   r:=0;
   a[n]:=a[n]mod 10000;
      if b[n-1]='*' then
      begin
         m:=m+1;
         c[m]:=a[n]*a[n-1] mod 10000;
      end
      else
      begin
         if b[n-2]<>'*'then
         begin
         m:=m+1;
         c[m]:=a[n-1];
         end;
      end;
   end;
   if b[n-1]<>'*'then
   begin
      m:=m+1;
      c[m]:=a[n];
   end;
   for i:=1 to m do
   ans:=(ans+c[i])mod 10000;
   write(ans);
   close(input);
   close(output);
end.
