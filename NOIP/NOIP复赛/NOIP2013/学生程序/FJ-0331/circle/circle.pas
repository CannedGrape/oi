var time,k,n,m,x,i,now,ans,cha:longint;

function fuck(c:longint):qword;
var get:qword;i:longint;
begin
  if c=1 then exit(cha);
      get:=fuck(c-1);
  for i:=1 to 10 do
    begin
      get:=(get+get)mod n;exit(get);
    end;
end;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  cha:=0;time:=1;
  if k<7 then
    begin
      for i:=1 to k do
        time:=time*10;
      for i:=1 to time do
        x:=(x+m) mod n;
      writeln(x);
      close(output);
      exit;
    end;
  for i:=1 to 10 do
    cha:=(cha+m) mod n;
  now:=fuck(k);
  ans:=(x+now) mod n;
  writeln(ans);
  close(input);
  close(output);
end.
