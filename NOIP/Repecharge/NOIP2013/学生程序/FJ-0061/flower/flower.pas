var n,i,j,ans:longint;
    a,lu,ld,ru,rd,fu,fd:array[-1..100001] of longint;
function max(a,b:longint):longint;
begin
    if a>b then exit(a) else exit(b);
end;
begin
    assign(input,'flower.in');reset(input);
    assign(output,'flower.out');rewrite(output);
    readln(n);
    for i:=1 to n do
        read(a[i]);
    for i:=1 to n do
    begin
        j:=0;
        repeat
            inc(j);
        until (a[i+j]>a[i])or(i+j>n);
        if i+j<=n then begin
            ru[i]:=i+j;
            ld[i+j]:=i;end;
        j:=0;
        repeat
            inc(j);
        until (a[i+j]<a[i])or(i+j>n);
        if i+j<=n then begin
            rd[i]:=i+j;
            lu[i+j]:=i;end;
    end;
    for i:=1 to n do
    begin
        fu[i]:=fd[lu[i]]+1;
        fd[i]:=fu[ld[i]]+1;
        if i+fu[i]<=n then ans:=max(ans,fu[i]*2);
        if i+fd[i]<=n then ans:=max(ans,fd[i]*2);
        if i+fu[i]+1<=n then ans:=max(ans,fu[i]*2+1);
        if i+fd[i]+1<=n then ans:=max(ans,fd[i]*2+1);
    end;
    writeln(ans);
    close(input);close(output);
end.
