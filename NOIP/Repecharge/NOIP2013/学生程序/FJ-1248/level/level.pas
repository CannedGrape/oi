program level;
var i,j,n,m,k,l,ans,p:longint;
    s:array[0..1001]of boolean;
    a,du:array[0..1001]of longint;
    b:array[0..1001,0..1001]of boolean;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    read(k);
    fillchar(s,sizeof(s),false);
    for j:=1 to k do
    begin
      read(a[j]);
      s[a[j]]:=true;
    end;
    s[1]:=true;s[n]:=true;
    for j:=1 to n do
    if not s[j]then
    for l:=1 to k do
    if(not b[j,a[l]])then begin du[a[l]]:=du[a[l]]+1;b[j,a[l]]:=true;end;
    readln;
  end;
  fillchar(s,sizeof(s),true);

  while true do
  begin
    k:=0;
    for i:=2 to n-1 do
    begin
      if(du[i]=0)and(s[i])then
      begin
        k:=k+1;
        a[k]:=i;
        s[i]:=false;
      end;
    end;
    if k>0 then ans:=ans+1 else break;
    for i:=1 to k do
    for j:=1 to n do
    if b[a[i],j]then
    begin
      b[a[i],j]:=false;
      du[j]:=du[j]-1;
    end;
  end;
  if ans=0 then write(1)else write(ans);
close(input);close(output);
end.
