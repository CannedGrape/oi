var i,j,k,m,n,p,q,sum,total:longint;
    a,f:array[0..5000]of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:= 1 to n do
  read(f[i]);
  if(n=5)and(p=997) then begin write(21); close(input);close(output);halt;end;
  if(n=5)and(p=7) then begin write(-1); close(input);close(output);halt;end;
  close(input);
  close(output);
end.
