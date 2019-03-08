var num,a,b:array[1..1000000] of int64;
    i,j,n,p:longint;
    qq:boolean;
    ans,t:int64;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  t:=0; ans:=-1000000000000000000;
  readln(n,p);
  qq:=false;
  for i:=1 to n do
  begin
    read(num[i]);
    if (t<0) or (not qq) then begin t:=num[i]; qq:=true; end
    else
    begin
      if num[i]>=0 then t:=t+num[i]
      else begin t:=0;qq:=false; end;
    end;
    if i=1 then a[i]:=num[i]
    else a[i]:=max(a[i-1],t);
    if i=1 then b[i]:=a[i]
    else if i=2 then b[i]:=a[i-1]+b[i-1]
    else b[i]:=max(a[i-1]+b[i-1],b[i-1]);
    if b[i]>ans then ans:=b[i];
  end;
  writeln(ans mod p);
  close(input);close(output);
end.
