var i,j,k,t,m,n,x,y,z,q,ans:longint;
    a:array[0..10000,0..10000] of longint;
    b:array[0..10000]of longint;
    input,output:text;
function min(x,y:longint):longint;
begin
  if x>y then min:=y else min:=x;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(input,n,m);
  fillchar(a,sizeof(a),0);
  for t:=1 to m do
  begin
    readln(input,i,j,k);
    if k>a[i,j] then begin
      a[i,j]:=k;
      a[j,i]:=k;
    end;
  end;
  for i:=1 to n do
   for j:=1 to n do
    for k:=1 to n do
      if (i<>j) and (i<>k) and (j<>k) then begin
      if (a[i,j]>a[i,k]) and (a[j,k]>a[i,k]) then a[i,k]:=min(a[i,j],a[j,k]);
      end;
  readln(input,q);
  for t:=1 to q do
  begin
    readln(input,i,j);
  if a[i,j]=0 then writeln(output,'-1') else writeln(output,a[i,j]);
  end;
  close(input);close(output);
end.
