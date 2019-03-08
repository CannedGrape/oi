
var n,i,t,tot,q:longint; a,b:array[0..100001] of longint;


procedure search(l,r:longint);
 var j,c:longint;
  begin

    while (a[l-1]=0)and(a[r+1]=0)and  (l=r) do begin tot:=tot+a[l]; break; end;
   for j:=l to r do
      a[j]:=a[j]-1;
      tot:=tot+1;
      for j:=l to r do
       if a[j]=0 then
       begin
         search(l,j-1);
         search(j+1,r);
        end;

     end;
 begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out');rewrite(output);
   readln(input,n);
   t:=0;
    for i:=1 to n do
     begin
     read(input,a[i]);
     if a[i]=0 then begin  inc(t); b[t]:=i;end;
     end;
     b[t+1]:=n;  b[0]:=1;
      for q:=1 to t+1 do
       search(b[q-1],b[q]);
       writeln(output,tot);
        close(input); close(output);
        end.




