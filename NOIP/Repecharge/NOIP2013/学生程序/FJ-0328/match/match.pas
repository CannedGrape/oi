type s=array[1..100000]of longint;
var
 a,b,c,d,e:s;
 n,i,j,k,l,step,t,n1,n2,n3,min,ans:longint;
 bo:boolean;

 procedure qsort1(l,r:longint);
 var i,j,x,y:longint;
 begin
  i:=l; j:=r; x:=d[(l+r)div 2];
  repeat
   while d[i]<x do inc(i);
   while d[j]>x do dec(j);
   if i<=j then
    begin
     y:=d[i]; d[i]:=d[j]; d[j]:=y;
     inc(i); dec(j);
    end;
  until i>j;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
 end;
 procedure qsort2(l,r:longint);
 var i,j,x,y:longint;
 begin
  i:=l; j:=r; x:=e[(l+r)div 2];
  repeat
   while e[i]<x do inc(i);
   while e[j]>x do dec(j);
   if i<=j then
    begin
     y:=e[i]; e[i]:=e[j]; e[j]:=y;
     inc(i); dec(j);
    end;
  until i>j;
  if l<j then qsort2(l,j);
  if i<r then qsort2(i,r);
 end;

 function ok:boolean;
 var l:longint;
 begin
  l:=0;
  for i:=1 to n do l:=(l+sqr(a[i]-b[i]))mod 99999997;
  if l=min then exit(true) else exit(false);
 end;

begin
 assign(input,'match.in'); reset(input);
 assign(output,'match.out'); rewrite(output);
 readln(n);  bo:=false;
 for i:=1 to n do read(a[i]);
 for i:=1 to n do read(b[i]);
 for i:=1 to n do c[i]:=abs(a[i]-b[i]);
 for i:=1 to n do l:=(l+c[i]*c[i]) mod 99999997;
 for i:=1 to n do begin d[i]:=a[i]; e[i]:=b[i]; end;
 qsort1(1,n);
 qsort2(1,n);
 for i:=1 to n do min:=(min+sqr(d[i]-e[i]))mod 99999997;
 if l=min then begin writeln(0); exit; end;
 while not(bo) do
  begin
   if abs(a[1]-b[1])>0 then
    begin
    if abs(a[1]-b[1])>abs(a[2]-b[1]) then
     begin
      t:=a[1]; a[1]:=a[2]; a[2]:=t;
      step:=(step+1)mod 99999997;
     end;
    end;
   bo:=ok; if bo then break;
   for i:=2 to n-1 do
    begin
     if c[i]=0 then continue;
     n1:=abs(a[i-1]-b[i]); n2:=abs(a[i]-b[i]); n3:=abs(a[i+1]-b[i]);
     if (n2<n1) and (n2<n3) then continue;
     if (n1<n2) and (n1<n3) then
      begin
       t:=a[i-1]; a[i-1]:=a[i]; a[i]:=t;
       step:=(step+1)mod 99999997; continue;
      end;
     t:=a[i]; a[i]:=a[i+1]; a[i+1]:=t;
     step:=(step+1)mod 99999997; continue;
    end;
   bo:=ok;
  end;
 writeln(step);
 close(input); close(output);
end.




















