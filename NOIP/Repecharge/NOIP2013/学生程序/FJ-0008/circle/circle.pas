var s2,n,m,k,x,s,s1:int64;i:longint;
function gcd(q,w:int64):int64;
begin
        if w=0 then begin gcd:=q;exit;end;
        if q>w then gcd:=gcd(w,q mod w)
        else gcd:=gcd(q,w mod q);
end;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
        read(n,m,k,x);
        s:=1;
        s2:=n*m;s2:=s2 div (gcd(n,m));
        s2:=s2 div m;
        k:=k mod s2;
        for i:=1 to k do
         s:=s*10  mod s2;
        if k=0 then s:=0;
         s1:=s*(m mod s2)mod s2;
         writeln((s1+x)mod n);
close(input);close(output);
end.