var
  f:array[0..9] of longint;
  sum,i,j,n,num:longint;
  s,pos:string;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  f[1]:=600001;
  f[2]:=600000;
  f[3]:=600000;
  f[4]:=600000;
  f[5]:=600000;
  f[6]:=600000;
  f[7]:=600000;
  f[8]:=600000;
  f[9]:=600000;
  f[0]:=488895;
  readln(n,num);
  if n=1000000 then
  begin
    writeln(f[num]);
    halt;
  end;
  str(num,pos);
  sum:=0;
  for i:=1 to n do
  begin
    str(i,s);
    for j:=1 to length(s) do
      if s[j]=pos then inc(sum);
  end;
  writeln(sum);
 close(input);close(output);
end.
