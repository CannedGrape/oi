var f,num,score:array[1..1000000] of qword;
    i,j,ans,n,p:longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(num[i]);
  f[1]:=num[1];
  for i:=1 to n do
    if f[i-1]<f[i-1]+num[i] then f[i]:=f[i-1]+num[i]
    else f[i]:=f[i-1];
  score[1]:=f[1];
  for i:=2 to n do
   begin
    score[i]:=0;
    for j:=1 to i-1 do
     if f[j]+num[j]>score[i] then score[i]:=f[j]+num[j];
    end;
  if score[n]<0 then
   begin
    write('-');
    ans:=score[n];
    ans:=ans mod p;
    write(ans);
   end;
  close(input);
  close(output);
end.
