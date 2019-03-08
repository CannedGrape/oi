program flower;
var
  n,m,i,t,max,k:longint;
  h,g:array [1..10000000] of longint;
  procedure fl(x:longint);
  begin
     if x>1 then
       begin
    for i:=1 to x do
     if 2*i<=x then
     begin
     if (h[2*i]<h[2*i-1]) and (h[2*i]<h[2*i+1]) then
       begin
      inc(t,2);
      g[k]:=h[2*i-1];
      inc(k);
      g[k]:=h[2*i+1];
      inc(k);
       end
      else if (h[2*i]>h[2*i-1]) and (h[2*i]>h[2*i+1]) then
        begin
       inc(t,2);
       g[k]:=h[2*i-1];
       inc(k);
       g[k]:=h[2*i+1];
       inc(k);
        end;
     end;
        for i:=1 to t do
         if g[i]=0 then
           dec(t);
     if t>max then
       max:=t;

     end
else
     max:=1;
  end;

  begin
   assign(input'flower.in');
   reset(input);
   assign(output,' flower.out');
   rewrite(output);
   K:=1;
   t:=1;
   read(n);
   for i:=1 to n do
     read(h[i]);
    fl(n);
    write(max);
    close(input);close(output);
  end.

