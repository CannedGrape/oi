var
  i,j,k,m,n,c,r:longint;
  a,b:array[0..100000] of longint;
begin
  assign(input,'block.in');  reset(input);
  assign(output,'block.out');  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  b[1]:=a[1];     r:=1;
  for i:=2 to n do
   begin
     if a[i]>b[r] then  begin inc(r);  b[r]:=a[i];  end;
     if (a[i]<b[r]) and (a[i]<>0)then
      begin
        while a[i]<b[r]   do
          begin
           c:=c+1;  r:=r-1;
          end;
        if r=0 then begin r:=1;  b[r]:=a[i];  end;
        if a[i]>b[r] then begin inc(r);  b[r]:=a[i];  end;
      end;
   end;
  if r>0 then c:=c+r;
  for i:=1 to r do
   if b[i]=0 then c:=c-1;
  write(c);
  close(input);  close(output);
end.

