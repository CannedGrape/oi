program block;
 var a:array[0..100003] of integer;
  n,y,i,j,l,r,x,q,p:longint;
  h:boolean;
 procedure gai(l,r:longint);
  var s,y:longint;
   begin
    for s:=l to r do
    if (s<>l) and (s<>r) then
     a[s]:=a[s]-1;
     inc(x);
   end;
 begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
  readln(n);
   for i:=1 to n do
     read(a[i]);
   readln;
 i:=0;
 j:=-1;
 h:=true;
 while h=true do
  begin
  h:=false;
 while i<>n do
  begin
   if (a[i]=0) and (a[i+1]<>0) then
    begin
     q:=i;
     break;
    end
   else
   begin
   if a[i]<>0 then inc(i);
    while a[i]=0 do
     inc(i);
    dec(i);
    q:=i;
    break
   end;
  end;
 while j<>n+2 do
  begin
 if j=-1 then j:=i+1;
   if a[j]=0 then
    begin
     p:=j;
     j:=-1;
     break;
    end
    else j:=j+1;
  end;
 gai(q,p);
for y:=1 to n do
 if a[y]<>0 then h:=true;
  end;
 writeln(x);
close(input);
close(output);
end.

