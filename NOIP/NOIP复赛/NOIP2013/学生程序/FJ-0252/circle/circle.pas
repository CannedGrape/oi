program circle;
var
  n,m,k,x,ans,pos:longint;
  input,output:text;

function pow(a:longint):longint;
var
  i:longint;
begin
  pow:=1;
  for i:=1 to a do
    pow:=pow*10 mod n;
end;

begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  read(input,n,m,k,x);
  k:=pow(k);
  pos:=m*k mod n;
  ans:=x+pos;
  write(output,ans);
  close(input);
  close(output);
end.
