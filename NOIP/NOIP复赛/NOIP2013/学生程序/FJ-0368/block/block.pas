program block;
var n,i,j,max,t:longint;
a:qword;
b:boolean;
q:array[1..100000]of integer;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
     read(q[i]);
     if q[i]>max then
       max:=q[i];
    end;
   for i:=1 to max do
   begin
    t:=0;b:=false;
    for j:=1 to n do
    begin
     if q[j]>=i then b:=true;
     if (q[j]<i)and(b) then begin b:=false; inc(t);end;
    end;
     if (q[n]<i)and(not b) then dec(t);
    inc(a,t+1);
   end;
   writeln(a);
  close(input);close(output);
end.
