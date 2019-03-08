var
  h,g:array[1..1000000]of longint;
  n,m,i,j:longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n); fillchar(h,sizeof(h),0);
  for i:=1 to  n do
    read(h[i]);
  readln; m:=n;
  for i:=1 to n do
    begin
      if (i-1>0) and (i+1<n) then
      begin
      if (h[i]>h[i-1]) then
      begin  m:=m-1; end
      else
      if  (h[i]>h[i+1]) then begin  m:=m-1; end;
      end;
    end;
  writeln(m);
  close(input);close(output);
end.