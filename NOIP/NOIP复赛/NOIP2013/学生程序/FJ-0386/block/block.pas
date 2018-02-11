program block;
var  n,s,i,j:longint;
     a:array[1..100000]of integer;
procedure ys(l,r:longint);
var min:integer; t:longint;
begin
   for i:=l to r do
      begin
       min:=a[i];
       for j:=i+1 to n do
        if a[j]<min then
         begin
          min:=a[j];
          t:=j;
         end;
       if (t>l)and(t<r) then
        begin
         ys(l,t-1);
         ys(t+1,r);
        end;
        s:=s+1;
      end;
end;
begin
     assign(input,'block.in');reset(input);
     assign(output,'block.out');rewrite(output);
     s:=0;
     readln(n);
     for i:=1 to n do read(a[i]);
     ys(1,n);
     write(s);
     close(input); close(output);
end.
