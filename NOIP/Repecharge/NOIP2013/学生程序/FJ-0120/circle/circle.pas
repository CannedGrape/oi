var
  i,j:longint;
  n,m,k,x,tot,ans,kk:int64;

function ksm(a,b:int64):int64;
begin
  if b=0 then exit(1);
  while (b>1) do
   begin
     if b mod 2=0 then
      begin
        a:=a*a mod n;
        b:=b div 2;
      end

     else
      begin
        a:=a*b mod n;
        a:=a*a mod n;
        dec(b);
        b:=b div 2;
      end;
   end;
  ksm:=a mod n;
end;





begin
assign(input,'circle.in'); reset(input);
assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);

  ans:=x;
  tot:=ksm(10,k);
  kk:=m *tot;
  kk:=kk mod (n);   //writeln('kk',kk);
  ans:=ans +kk;
  if ans>(n-1) then ans:=ans-(n);

  writeln(ans);
  //writeln('ksm',tot);
close(input); close(output);
end.
