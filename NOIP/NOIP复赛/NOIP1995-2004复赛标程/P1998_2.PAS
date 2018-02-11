program p1998_2(input,output);{High Precision Caculate 1!+2!+...+n!高精度运算}
const max=100;
type arr=array[1..max] of integer;
var f,total:arr;
    i,j,n:integer;

procedure mul(var f:arr;n:integer);
var c,i:integer;
begin
    for i:=1 to 100 do f[i]:=f[i]*n;
    c:=0;
    for i:=1 to 100 do begin
        f[i]:=f[i]+c;
        c:=f[i] div 10;
        f[i]:=f[i] mod 10;
    end;
end;

procedure add(var total:arr;f:arr);
var c,i,nt,nf:integer;
begin
    nt:=max;while (nt>0) and (total[nt]=0) do nt:=nt-1;
    nf:=max;while (nf>0) and (f[nf]=0) do nf:=nf-1;
    if nt<nf then nt:=nf;
    c:=0;
    for i:=1 to nt do begin
       total[i]:=total[i]+c+f[i];
       c:=total[i] div 10;
       total[i]:=total[i] mod 10;
    end;
    if c>0 then total[nt+1]:=c;
end;

procedure out(total:arr);
var i:integer;
begin
    i:=max;while (i>0) and (total[i]=0) do i:=i-1;
    while i>0 do begin write(total[i]);i:=i-1;end;
    writeln;
end;

begin
    assign(input,'factor.in');
    reset(input);
    readln(n);
    close(input);
    assign(output,'factor.out');
    rewrite(output);
    fillchar(f,sizeof(f),0);fillchar(total,sizeof(total),0);
    f[1]:=1;
    for i:=1 to n do begin
       mul(f,i);
       add(total,f);
    end;
    out(total);
    close(output);
end.
