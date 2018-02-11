program ex03;
var num:array[1..1000005] of longint;
    te:array[1..1000005] of longint;
    score:array[1..1000005] of longint;
    l:array[1..1000005] of longint;
    i,n,p,max,imax:longint;



function chx(r:longint):longint;
var i,m:longint;
begin
fillchar(l,sizeof(l),0);
l[1]:=num[1];
m:=l[1];
for i:=2 to r do
   if (num[i]>=0)and(num[i-1]>=0) then
     begin
     l[i]:=num[i]+l[i-1];
     if l[i]>m then m:=l[i];
     end
   else if (num[i]>=0)and(num[i-1]<0) then
     begin
     l[i]:=num[i];
     if l[i]>m then m:=l[i];
     end
   else if num[i]<0 then
      begin
      l[i]:=num[i];
      if l[i]>m then m:=l[i];
      end;
chx:=m;
end;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
readln(n,p);
for i:=1 to n do read(num[i]);
fillchar(te,sizeof(te),0);
fillchar(score,sizeof(score),0);
te[1]:=num[1];score[1]:=te[1];
max:=te[1]+score[1];
imax:=score[1];
for i:=2 to n do
   begin
   te[i]:=chx(i);
   score[i]:=max;
   if score[i]>imax then imax:=score[i];
   if score[i]+te[i]>max then max:=score[i]+te[i];
   end;
if imax<0 then
   begin
    write('-');
    imax:=0-imax;
   end;
imax:=imax mod p;
write(imax);
close(input);
close(output);
end.


