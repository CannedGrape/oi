program truck;
var f,d:array[0..10000] of longint;
    a,k:array[0..10000,0..10000] of longint;
    n,m,i,j,l,q,head,tail,x,y,z:longint;
    v:array[1..10000] of boolean;
procedure init;
begin
    fillchar(a,sizeof(a),$7f);
    readln(n,m);
    for i:=1 to m do
    begin
        readln(x,y,z);
        a[x,y]:=z;
        a[y,x]:=z;
        inc(k[0,x]);
        k[k[0,x],x]:=y;
        inc(k[0,y]);
        k[k[0,y],y]:=x;
    end;
end;
function max(i,j:longint):longint;
begin
    if i>j then exit(i);
    exit(j);
end;
function min(i,j:longint):longint;
begin
    if i<j then exit(i);
    exit(j);
end;
procedure perm;
var s,t:integer;
begin
    readln(q);
    for i:=1 to q do
    begin
        fillchar(f,sizeof(f),0);
        fillchar(d,sizeof(d),0);
        fillchar(v,sizeof(v),0);
        readln(s,t);
        head:=1; tail:=1;
        v[s]:=true; f[s]:=maxlongint; f[t]:=0; d[1]:=s;
        while head<=tail do
        begin
            x:=d[head];
            for j:=1 to k[0,x] do
            begin
                y:=min(f[x],a[x,k[j,x]]);
                if y>f[k[j,x]] then
                begin
                    f[k[j,x]]:=y;
                    if not(v[k[j,x]]) then
                    begin
                        inc(tail);
                        d[tail]:=k[j,x];
                        v[k[j,x]]:=false;
                    end;
                end;
            end;
            inc(head);
            v[x]:=false;
        end;
        if f[t]<>0 then writeln(f[t]) else writeln ('-1');
    end;
end;
begin
    assign(input,'truck.in');
    assign(output,'truck.out');
    reset(input);
    rewrite(output);
    init;
    perm;
    close(input);
    close(output);
end.
