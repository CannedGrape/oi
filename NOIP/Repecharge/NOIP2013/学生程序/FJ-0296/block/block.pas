Program block;
Var sum,ans:qword;
    h:array[0..100001]of qword;
    i,n:longint;

function min(a,b:qword):qword;
begin
    if a<b then exit(a);
    exit(b);
end;

Begin
    assign(input,'block.in');  reset(input);
    assign(output,'block.out');  rewrite(output);


    readln(n);  sum:=0;
    for i:=1 to n do
    begin
        read(h[i]);
        inc(sum,h[i]);
    end;

    ans:=sum;

    for i:=2 to n do
    begin
        dec(ans,min(h[i],h[i-1]));
    end;

    writeln(ans);

    close(input);
    close(output);
End.
