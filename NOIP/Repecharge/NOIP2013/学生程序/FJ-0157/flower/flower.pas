program flower;
 var n,m,i,xg,xd:longint;
     h:array[0..100000]of longint;

begin
 assign(input,'flower.in');
 assign(output,'flower.out');
 reset(input);
 reset(output);

  readln(n);
  for i:=1 to n do
   begin
    read(h[i]);
   end;

  xg:=0;
  xd:=0;
  for i:=2 to (n-1) do
   begin
      if ( (h[i]>h[i-1]) and (h[i]>h[i+1]) )
         then inc(xg);
      if ( (h[i]<h[i-1]) and (h[i]<h[i+1]) )
         then inc(xd);
   end;

  if xg>xd then m:=xg
           else m:=xd;

  write(2*m+1);
  readln;

 close(input);
 close(output);
end.