var
   i,p,m,n,k,x,n2,n5:longint;
   w,ans:qword;

procedure halt0;
begin writeln(ans);close(input);close(output);halt;end;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
    read(n,m,k,x);p:=n;n2:=0;n5:=0;
    while (p mod 2=0)and(n2<k) do begin p:=p div 2;inc(n2);end;
    while (p mod 5=0)and(n5<k) do begin p:=p div 5;inc(n5);end;
    if p=1 then begin ans:=x;halt0;end;
    w:=1;
    for i:=1 to k do w:=w*10;
    ans:=(x+w*m);
    ans:=ans mod n;
    halt0;
end.
