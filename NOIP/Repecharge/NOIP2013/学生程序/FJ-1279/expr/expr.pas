program expr;
 var
 a:ansistring;
 b:array[1..100001] of ansistring;
 d:array[1..100001] of longint;
 i,j,qs,c,qs1,cj,cj1,h,code,bj:longint;
 begin
 assign(input,'expr.in');reset(input);
 assign(output,'expr.out');rewrite(output);
 readln(a);
 qs:=1;
 c:=0;
  for i:=1 to length(a) do
   if a[i]='+' then
    begin
     inc(c);
     b[c]:=copy(a,qs,i-qs);
     qs:=i+1;
    end;
   inc(c);
   inc(i);
   b[c]:=copy(a,qs,i-qs);
  for i:=1 to c do
   begin
   cj1:=1;
   qs1:=1;
   bj:=0;
   for j:=1 to length(b[i]) do
    if b[i,j]='*' then
    begin
    val(copy(b[i],qs1,j-qs1),cj,code);
    cj1:=cj*cj1;
    qs1:=j+1;
    bj:=1;
    end;
   val(copy(b[i],qs1,length(b[i])+1-qs1),cj,code);
   cj1:=cj*cj1;
   val(b[i],d[i],code);
   if bj=1 then d[i]:=cj1;
   h:=h+d[i];
   end;
  write(h mod 10000);
 close(input);close(output);
 end.