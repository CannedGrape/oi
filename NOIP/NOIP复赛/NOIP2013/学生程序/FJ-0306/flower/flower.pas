program ex_2;
var a:array[0..100001]of integer;
    d:array[0..100001,1..2,1..2]of longint;
    n,i,j,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
begin
  assign(input,'flower.in');reset(input);
  read(n);
  for i:=1 to n do
    read(a[i]);
  close(input);

  d[1,1,1]:=1;
  d[1,1,2]:=1;
  d[1,2,1]:=0;
  d[1,2,2]:=0;
  for i:=2 to n do
    for j:=i-1 downto 1 do
      begin
        if (d[j,2,2]<>0)and(a[i]>a[j]) then
          d[i,1,1]:=max(d[i,1,1],d[j,2,2]+1)
        else d[i,1,1]:=max(1,d[i,1,1]);
        if d[i,1,1]>ans then ans:=d[i,1,1];

        if (d[j,2,1]<>0)and(a[i]<a[j]) then
          d[i,1,2]:=max(d[i,1,2],d[j,2,1]+1)
        else d[i,1,2]:=max(1,d[i,1,2]);
        if d[i,1,2]>ans then ans:=d[i,1,2];

        if (d[j,1,1]<>0)and(a[i]<a[j]) then
          d[i,2,2]:=max(d[i,2,2],d[j,1,1]+1);
        if d[i,2,2]>ans then ans:=d[i,2,2];

        if (d[j,1,2]<>0)and(a[i]>a[j]) then
          d[i,2,1]:=max(d[i,2,1],d[j,1,2]+1);
        if d[i,2,1]>ans then ans:=d[i,2,1];
      end;
  assign(output,'flower.out');rewrite(output);
  write(ans);
  close(output);
end.

