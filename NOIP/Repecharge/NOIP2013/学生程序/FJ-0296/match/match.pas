Program match;
Var a,b,posa,posb,tarb,tb:array[0..100001]of int64;
    time:qword;
    i,n,next:longint;
    jub:array[0..100001]of boolean;

procedure swap(var a,b:int64);
var temp:int64;
begin
    temp:=a;  a:=b;  b:=temp;
end;

procedure qsorta(l,r:longint);
var i,j:longint;
    mid:int64;
begin
    i:=l;  j:=r;  mid:=a[(l+r)shr 1];
    repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if i<=j then
        begin
            swap(a[i],a[j]);  swap(posa[i],posa[j]);  inc(i);  dec(j);
        end;
    until i>j;
    if i<r then qsorta(i,r);
    if l<j then qsorta(l,j);
end;

procedure qsortb(l,r:longint);
var i,j:longint;
    mid:int64;
begin
    i:=l;  j:=r;  mid:=b[(l+r)shr 1];
    repeat
        while b[i]<mid do inc(i);
        while b[j]>mid do dec(j);
        if i<=j then
        begin
            swap(b[i],b[j]);  swap(posb[i],posb[j]);  inc(i);  dec(j);
        end;
    until i>j;
    if i<r then qsortb(i,r);
    if l<j then qsortb(l,j);
end;

Begin
    assign(input,'match.in');  reset(input);
    assign(output,'match.out');  rewrite(output);

    fillchar(jub,sizeof(jub),false);
    readln(n);
    for i:=1 to n do
    begin
        read(a[i]);  posa[i]:=i;
    end;

    readln;

    for i:=1 to n do
    begin
        read(b[i]);  posb[i]:=i;
    end;

    qsorta(1,n);  qsortb(1,n);

    for i:=1 to n do
    begin
        tarb[i]:=posa[i];  tb[posb[i]]:=i;
    end;

    time:=n;

    for i:=1 to n do
    begin
        if not jub[posb[i]] then
        begin
            if posb[i]=tarb[i] then
            begin
                jub[posb[i]]:=true;
                dec(time);  continue;
            end;

            next:=posb[i];  //next means the oriposition of the number
            while not jub[next] do
            begin
                jub[next]:=true;
                next:=posb[tb[tarb[tb[next]]]];
            end;
            dec(time);
        end;
    end;

    writeln(time mod 99999997);

    close(input);
    close(output);
End.
