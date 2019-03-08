var n,mo,i,j,k,l,count,max1,max2:longint;
    s,tz,fs:array[1..1000000]of longint;
begin
assign(input,'number.in');
assign(output,'number.out');
reset(input);
rewrite(output);
read(n,mo);
for i:=1 to n do
read(s[i]);
tz[1]:=s[1];
fs[1]:=s[1];
max1:=s[1];
max2:=s[1]+s[1];
count:=0;
for i:= 2 to n do
begin
   for j:=i downto 2 do
   begin
      for k:=j-1 downto 1 do
      begin
         for l:=k to j do
         begin
             count:=count+s[l];
         end;
         if(count>max1)  then
         max1:=count;
         count:=0;
      end;
   end;
   tz[i]:=max1;
end;

for i:=2 to n do
begin
fs[i]:=max2;
if(tz[i]+fs[i]>max2)and (not(i=n)) then
max2:=tz[i]+fs[i];
end;
max2:=fs[1];
for i:=2 to n do    begin
if(fs[i]>max2) then
max2:=fs[i];
end;
write(max2 mod mo);
close(input);
close(output);
end.
