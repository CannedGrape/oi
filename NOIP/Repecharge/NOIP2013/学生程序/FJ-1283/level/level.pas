var
    i,j,n,m,k,l,max,ans:longint;
    s,a,b,c:array[1..1000]of longint;
//=====================================
function zj(x:longint):longint;
 var q:longint;
 begin
  zj:=x;
  for q:=2 to trunc(sqrt(x)) do
   if (x mod q=0)  then
    begin
     zj:=q;
     exit;
    end;
 end;

//========================================
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
 readln(n,m); max:=0;
 for i:=1 to m do
  begin
   read(s[i]);
     for j:=1 to s[i]do
    read(a[j]);ans:=0;
   for j:=1 to s[i] do
   if a[j]<>1 then
    begin
     inc(ans);
     c[ans]:=zj(a[j]);
     break;
    end;
   for k:=j+1 to s[i] do
    begin
     for l:=1 to ans do
      if a[k] mod c[l]=0 then break;
     if a[k] mod c[l]<>0 then
      begin
        inc(ans);
        c[ans]:=zj(a[k]);
      end;
    end;
  if ans>max then max:=ans;
  end;
 writeln(max);
close(input);close(output);
end.
