{$R+,S+,Q+}
var t,h:array[0..100000] of longint;
    i,n,min,ans,l,r:longint;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  h[0]:=0;t[0]:=0;
  if n>1000 then
   begin
    for i:=1 to n do
     begin
      read(h[i]);
      if h[i]<=h[i-1] then t[i]:=t[i-1]
                      else t[i]:=t[i-1]+abs(h[i-1]-h[i]);
     end;
    write(t[n]);
   end
  else
   begin
    for i:=1 to n do read(h[i]);
    l:=0;r:=1;
    repeat
      while (h[l]=0) and (l<=n) do inc(l);
      r:=l;min:=maxlongint;
      if l>n then continue;
      while h[r]<>0 do
       begin
        if h[r]<min then min:=h[r];
        inc(r);
       end;
      dec(r);
      for i:=l to r do
       h[i]:=h[i]-min;
      inc(ans,min);
    until l>n;
    write(ans);
   end;
  close(input);close(output);
end.

