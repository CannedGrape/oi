var n,i,top:longint;
z,h,x,e,r,q,w,a,b:array[0..100000] of longint;
function max(o,p:longint):longint;
begin
        if o>p then exit(o);exit(p);
end;
begin
        assign(input,'flower.in');reset(input);
        assign(output,'flower.out');rewrite(output);
        readln(n);
        for i:=1 to n do
                read(h[i]);
        for i:=n downto 1 do
                begin
                        while(top<>0) and (z[top]>h[i]) do begin e[x[top]]:=i; dec(top);end;
                        inc(top);z[top]:=h[i];x[top]:=i;
                end;
        top:=0;
        for i:=n downto 1 do
                begin
                        while(top<>0) and (z[top]<h[i]) do begin r[x[top]]:=i; dec(top);end;
                        inc(top);z[top]:=h[i];x[top]:=i;
                end;
        for i:=2 to n do
                begin
                        if e[i]>0 then a[i]:=w[e[i]]+1;
                        if r[i]>0 then b[i]:=q[r[i]]+1;
                        q[i]:=max(q[i-1],a[i]);
                        w[i]:=max(w[i-1],b[i]);
                end;
        writeln(max(a[n],b[n])+1);
        close(input);close(output);
end.
