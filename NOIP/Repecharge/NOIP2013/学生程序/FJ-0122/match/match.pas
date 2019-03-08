const
   p=99999997;
var
   a,b,d1,d2:array[0..100000]of longint;
   n,i,j,max,l,r:longint;
procedure kp(l,r:longint);
var
   i,j,mid,t:longint;
begin
   i:=l;j:=r;
   mid:=a[(l+r)div 2];
   repeat
     while a[i]>mid do inc(i);
     while a[j]<mid do dec(j);
     if i<=j then
     begin
       t:=a[i];a[i]:=a[j];a[j]:=t;
       t:=d1[i];d1[i]:=d1[j];d1[j]:=t;
       inc(i);dec(j);
     end;
   until i>j;
   if i<r then kp(i,r);
   if l<j then kp(l,j);
end;
procedure kp1(l,r:longint);
var
   i,j,mid,t,k:longint;
begin
   i:=l;j:=r;
   mid:=b[(l+r)div 2];
   repeat
     while b[i]>mid do inc(i);
     while b[j]<mid do dec(j);
     if i<=j then
     begin
       t:=b[i];b[i]:=b[j];b[j]:=t;
       t:=d2[i];d2[i]:=d2[j];d2[j]:=t;
       inc(i);dec(j);
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
     d1[i]:=i;
   end;
   for i:=1 to n do
   begin
     read(b[i]);
     d2[i]:=i;
   end;
   kp(1,n);
   kp1(1,n);
   for i:=1 to n do
   begin
     if (abs(d1[i]-d2[i]))mod p>max then max:=(abs(d1[i]-d2[i]))mod p;
   end;
   writeln(max);
   readln;
   close(input);close(output);
end.