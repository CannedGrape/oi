var h:array[0..100500]of longint;
 n,i,j,k,ans1,ans2,s1,s2:longint;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
  read(n);
  for i:=1 to n do read(h[i]);
  s1:=1;s2:=-1;
  for i:=2 to n do
   begin
     if (h[i]<h[i-1])and(s1=1)then begin inc(ans1);s1:=-1;end else
         if (h[i]>h[i-1])and(s1=-1)then begin inc(ans1);s1:=1;end;
     if (h[i]<h[i-1])and(s2=1)then begin inc(ans2);s2:=-1;end else
         if (h[i]>h[i-1])and(s2=-1)then begin inc(ans2);s2:=1;end;


   end;
   if ans1>ans2 then write(ans1+1) else write(ans2+1);
 close(input);
close(output);
end.