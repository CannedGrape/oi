program number;
var n,p,i,j,k,max,m,x:longint;
    num,t,sco:array[1..1000000] of longint;
begin
 assign(input,'number.in');
 assign(output,'number.out');
 reset(input);
 rewrite(output);
 read(n,p); readln;
 for i:=1 to n do
  read(num[i]);
 t[1]:=num[1];
 for i:=2 to n do
  begin
   x:=1;
   max:=-1000000001;
   while(x<=i) do
    begin
     for j:=1 to i-x do
      begin
       m:=0;
       for k:=j+1 to j+x do
        m:=m+num[k];
       if m>max then max:=m;
      end;
     x:=x+1;
    end;
   if max>=0 then t[i]:=max+1 else
    t[i]:=max;
  end;
 sco[1]:=t[1];
 for i:=2 to n do
  begin
   max:=-1000000001;
   for j:=1 to i-1 do
    begin
     m:=sco[j]+t[j];
     if m>max then max:=m;
    end;
   sco[i]:=max;
  end;
 for i:=1 to n do
  if sco[i]>max then max:=sco[i];
 write(max mod p);
 close(input);
 close(output);
end.