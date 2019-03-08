program ex2;
var n,ans:longint;
a:array[0..100000] of longint;
b:array[0..100000] of longint;

procedure start;
var i:longint;
begin
    assign(input,'match.in');
    assign(output,'match.out');
    reset(input);
    rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do read(b[i]);
    ans:=0;
end;

procedure work;
var i,j,x,y,temp,k:longint;
begin
    temp:=maxlongint;
    for i:=1 to n do
    begin
        for j:=i to n do
        if (a[i]-b[j])*(a[i]-b[j])<temp then
        begin
            temp:=(a[i]-b[j])*(a[i]-b[j]);
            k:=j;
        end;
        if j-i=0 then
        ans:=ans+k-i
        else
        begin
            ans:=ans+k-i;
            for x:=k downto i+1 do
            begin
                y:=b[x];b[x]:=b[x-1];b[x-1]:=y;
            end;
        end;
        temp:=maxlongint;
    end;
    write(ans);
end;

begin
    start;
    work;
end.

