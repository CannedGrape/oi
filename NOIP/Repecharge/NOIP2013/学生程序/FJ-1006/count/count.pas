const fn='count';
var n:longword;x,i:byte;ch:char;
ans:qword;s:string;

procedure flink;
begin assign(input,fn+'.in');
assign(output,fn+'.out');
reset(input);rewrite(output) end;
procedure fclose;
begin close(output);close(input) end;


begin
flink;
read(n,x);
ch:=chr(48+x);
ans:=0;
for n:=1 to n do
 begin
  str(n,s);
  for i:=1 to length(s) do
  if s[i]=ch then inc(ans)
 end;
write(ans);
fclose
end.


