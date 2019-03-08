program circle;
var n,m,k,x,i,j:longint;
    ans:qword;
    w:boolean;
begin
    assign(input,'circle.in');
    assign(output,'circle.out');
    reset(input);
    rewrite(output);
    readln(n,m,k,x);
    ans:=x;
    for i:=1 to k do
        begin
            ans:=ans+10*m;
            while ans>=n do ans:=ans mod n;
        end;
    write(ans);
    close(input);
    close(output);
end.
