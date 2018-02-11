program circle;
var i,j,a,b,c,d,e,n,m,k,x,f:longint;
    l,s,q:string;
begin
     assign(input,'circle.in'); assign(output,'circle.out');reset(input);rewrite(output);
     read(n,m,k,x);
     str(m,l);a:=length(l);str(n,s);b:=length(s);val(s[1],c,d);
     for i:=1 to (b-a+1) do m:=m*10;
     m:=m mod n;
     k:=k-(b-a+1);
     str(m,l);
     a:=length(l);
     while (a+k)>b do begin
                        for i:=1 to (b-a+1) do m:=m*10;
     m:=m mod n;k:=k-(b-a+1);str(m,l);a:=length(l);
            end;
     if a+k=b then for i:=1 to k do m:=m*10;
     m:=m mod n;
     m:=(m+x) mod n;
     writeln(m);
     close(input);close(output);
end.
