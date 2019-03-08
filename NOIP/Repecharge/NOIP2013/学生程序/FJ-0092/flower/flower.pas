var a:array[0..100000]of longint;
fa,fb:array[0..100000]of longint;
n,i,j,k:longint;
maxa,maxb:longint;
function max(a,b:longint):longint;
 begin
 if a>b then exit(a); exit(b);
  end;

begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
maxa:=1;
maxb:=1;
 readln(n);
 for i:=1 to n do
  begin
  fa[i]:=1;
  read(a[i]);
  fb[i]:=1;
  end;
  for i:=1 to n do
   begin
    fa[i]:=1;
    fb[i]:=1;
    if ((a[i]>a[i-1]) and (i-1<>0)) then inc(fa[i]);
    if ((a[i]<a[i-1]) and (i-1<>0))then inc(fb[i]);
    if ((a[i]<a[i+1])and (i+1<=n)) then inc(fb[i]);
    if ((a[i]>a[i+1]) and (i+1<=n)) then inc(fa[i]);
     end;
   for i:=1 to n do
   begin
    if fa[i]>maxa then maxa:=fa[i];
    if fb[i]>maxb then maxb:=fb[i];
    end;


{for i:=n-1 downto 1 do
begin
  for j:=i+1 to n do
      begin
       if ((a[j]>a[j+1])and(j-1<>i) then inc(fa[j]);
          if ((a[j]<a[j-1]) and (j-1>i));then inc(fb[j]);
    if ((a[j]<a[j+1]) then (j+1<=n))inc(fb[j]);
    if ((a[j]>a[j+1]) and (j+1<=n)) then inc(fa[j]);
       end;
 if
end;   }

   begin
    if fa[i]>maxa then maxa:=fa[i];
    if fb[i]>maxb then maxb:=fb[i];
    end;




     writeln(max(maxa,maxb));
     close(input);
  close(output);

 end.



