type
rec=record
s:longint;
y:longint;
end;
var
sum,n,i:longint;
a,b:array[0..100001] of rec;
f:array[0..100001] of longint;
flag:boolean;
 procedure sort1(l,r: longint);
      var
         i,j,x: longint;
         y:rec;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2].s;
         repeat
           while a[i].s<x do
            inc(i);
           while x<a[j].s do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort1(l,j);
         if i<r then
           sort1(i,r);
      end;


  procedure sort2(l,r: longint);
      var
         i,j,x: longint;
         y:rec;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2].s;
         repeat
           while b[i].s<x do
            inc(i);
           while x<b[j].s do
            dec(j);
           if not(i>j) then
             begin
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort2(l,j);
         if i<r then
           sort2(i,r);
      end;

procedure swap(var a,b:longint);
var y:longint;
begin
y:=a;
a:=b;
b:=y;


end;


begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);
read(n);
for i:= 1 to n do begin read(a[i].s);a[i].y:=i; end;
for i:= 1 to n do begin read(b[i].s);b[i].y:=i; end;
sort1(1,n);
sort2(1,n);
for i:= 1 to n do
f[a[i].y]:=b[i].y;
flag:=true;
while flag do
begin
flag:=false;
for i:= 2 to n do
if f[i]<f[i-1] then
begin
swap(f[i],f[i-1]);
inc(sum);
if sum>=99999997 then dec(sum,99999997);
flag:=true;
end;



end;
write(sum);








close(input);
close(output);





end.
