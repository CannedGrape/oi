var i,j,n,max,min,dis,ans,hh,num,po:longint;
m1,m2,cha:array[0..100000]of longint;
inf,ouf:text;
procedure init;
begin
assign(inf,'match.in');reset(inf);
assign(ouf,'match.out');rewrite(ouf);
read(inf,n);
for i:=1 to n do
read(inf,m1[i]);
for i:=1 to n do
read(inf,m2[i]);
end;

procedure main(d:longint);
begin
min:=d; num:=0;
for i:=1 to n-1 do
begin
hh:=cha[i]*cha[i]+cha[i+1]*cha[i+1]-(m1[i+1]-m2[i])*(m1[i+1]-m2[i])-(m2[i+1]-m1[i])*(m2[i+1]-m1[i]);
if (dis-hh)>=min then inc(num);
if (num=(n-1))or(dis=0) then exit;
if (dis-hh)<min then begin min:=dis-hh;po:=i;end;
end;
dis:=min;inc(ans);
cha[po]:=(m1[i+1]-m2[i]);
cha[po+1]:=(m2[i+1]-m1[i]);
main(dis);
end;

begin
init;
for i:=1 to n do
begin
if m1[i]>m2[i] then cha[i]:=m1[i]-m2[i] else cha[i]:=m2[i]-m1[i];
dis:=dis+cha[i]*cha[i];end;
main(dis);
writeln(ouf,ans);
close(inf);close(ouf);

end.
