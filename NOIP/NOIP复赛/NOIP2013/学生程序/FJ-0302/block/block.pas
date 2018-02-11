program sdadf;
var i,n,k1,kk,l1,l2,ans,j,ll,min:longint;ok:boolean;
    a,b:array[0..100010]of longint;

begin
 assign(input,'block.in');
 reset(input);
 read(n);ok:=true;
 min:=maxlongint;
 for i:=1 to n do
  begin
   read(a[i]);
   inc(kk,a[i]);
   if min>a[i] then
    min:=a[i];
  end;
 for i:=1 to n do
  begin b[i]:=min;inc(k1,min);ans:=min;end;
 repeat
  ok:=false;
  for I:=1 to n+1 do
  if a[i]<>b[i] then
    begin
     inc(b[i]);
     inc(k1);
     ok:=true;
    end
   else
    begin
     if ok then
      begin
       inc(ans);
       ok:=false;
      end;
    end;


 until k1=kk;
 assign(output,'block.out');
 rewrite(output);
 write(ans);
 close(input);
 close(output);
end.
