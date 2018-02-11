var a,b,c:array[1..50000] of longint;
f,g,e:array[1..10000] of longint;
n,m,q,i,ww,g1,g2,f1,f2,t1,t2:longint;
function min(o,p:longint):longint;
begin
        if o<p then exit(o);exit(p);
end;
procedure swap(var o,p:longint);
var t:longint;
begin
        t:=o;o:=p;p:=t;
end;
procedure kp(l,r:longint);
var cc,d,mid:longint;
begin
        cc:=l;d:=r;mid:=(l+r)>>1;
        repeat
                while(c[cc]>c[mid]) do inc(cc);
                while(c[d]<c[mid]) do dec(d);
                if cc<=d then
                        begin
                                swap(c[cc],c[d]);
                                swap(a[cc],a[d]);
                                swap(b[cc],b[d]);
                                inc(cc);dec(d);
                        end;
        until cc>d;
        if cc<r then kp(cc,r);
        if l<d then kp(l,d);
end;
function fa(o:longint):longint;
begin
        while(o<>f[o])do begin ww:=min(ww,e[o]);o:=f[o];end;
        exit(o);
end;
begin
        assign(input,'truck.in');reset(input);
        assign(output,'truck.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do
                begin
                        f[i]:=i;
                        g[i]:=1;
                        e[i]:=200000;
                end;
        for i:=1 to m do
                begin
                        readln(a[i],b[i],c[i]);
                end;
        kp(1,m);
        for i:=1 to m do
                begin
                        f1:=fa(a[i]);
                        f2:=fa(b[i]);
                        if f1<>f2 then
                                begin
                                        if g[f1]>=g[f2] then
                                                begin
                                                        f[f2]:=f1;
                                                        e[f2]:=c[i];
                                                        inc(g[f1],g[f2]);
                                                end
                                        else    begin
                                                f[f1]:=f2;
                                                e[f1]:=c[i];
                                                inc(g[f2],g[f1]);
                                                end;
                                end;
                end;
        readln(q);
        for i:=1 to q do
                begin
                        read(t1,t2);
                        ww:=200000;
                        f1:=fa(t1);
                        g1:=ww;
                        ww:=200000;
                        f2:=fa(t2);
                        g2:=ww;
                        if f1<>f2 then writeln(-1) else writeln(min(g1,g2));
                end;
        close(input);close(output);
end.
