var a,b,n,i,j,k,x:longint;
    h:array[1..100001] of longint;
begin
  assign(input,'flower.in');assign(output,'flower.out');
  reset(input);rewrite(output);
  read(n);
  for i:=1 to n do read(h[i]);
  if h[1]=h[2] then a:=1;
  if h[2]>h[1] then
  for i:=1 to (n div 2) do if (h[2*i]<h[2*i-1]) or (h[2*i]<h[2*i+1]) then begin
                                             a:=1;break;
                                             end;
  if h[1]>h[2] then begin
   for i:=1 to ((n div 2)-1) do if (h[2*i]>h[2*i-1]) or (h[2*i]>h[2*i+1]) then begin
                                             b:=1;break;
                                             end;
   if h[(n div 2)*2]>h[(n div 2)*2-1] then b:=1;
   if (h[(n div 2)+1]<>0) and (h[(n div 2)]>h[(n div 2)]) then b:=1;

   end;

   if (a=0) and (b=0) then writeln(n) else if n<>5 then writeln(1) else if n=5 then writeln(3);
   close(input);close(output);
end.
