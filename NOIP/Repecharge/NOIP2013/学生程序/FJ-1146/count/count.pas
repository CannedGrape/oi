var i,j,k,m,n,o,p,q,l,r,sum:longint;
    s,t,w:string;
    c:char;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  read(m,n);
  c:=chr(n+48);
  for i:=1 to m do begin
    str(i,s);
    for j:=1 to length(s) do
     if s[j]=c then inc(sum);
  end;
  write(sum);
  close(input);
  close(output);
end.