var n,i,j,ans,min,minn:longint;
    h:array[1..100001]of longint;


procedure mesort(he,t:longint);
var k,c,minh,minnum:longint;
begin
  if he>t then exit;
  if he=t then
    if h[he]=0 then exit
      else
        begin
          ans:=ans+h[he];
          h[he]:=0;
        end;
  minh:=100000;
  for k:=he to t do
    if h[k]<minh then
      begin
        minh:=h[k];
        minnum:=k;
      end;
  for k:=he to t do h[k]:=h[k]-minh;
  ans:=ans+minh;
  mesort(he,minnum-1);
  mesort(minnum+1,t);
end;



begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);
  readln(n);
  min:=100000;
  for i:=1 to n do
    begin
     read(h[i]);
     if h[i]<min then
       begin
         min:=h[i];
         minn:=i;
       end;
    end;
  for i:=1 to n do h[i]:=h[i]-min;
  ans:=min;
  mesort(1,minn-1);
  mesort(minn+1,n);
  writeln(ans);
  close(input); close(output);
end.

