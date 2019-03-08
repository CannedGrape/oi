Program circle;
Var n,m,k,x,movement:qword;

function figer(x:qword):qword;
begin
    if x=0 then
    begin
        figer:=1;
        exit;
    end;
    if x=1 then
    begin
        figer:=10;  exit;
    end;
    if x and 1=0 then
    begin
        figer:=sqr(figer(x shr 1)) mod n;  exit;
    end;
    figer:=((sqr(figer(x shr 1)) mod n)*10)mod n;
    exit;
end;


Begin
    assign(input,'circle.in');  reset(input);
    assign(output,'circle.out');  rewrite(output);

    readln(n,m,k,x);
    movement:=(m*figer(k))mod n;
    writeln((x+movement)mod n);

    close(input);
    close(output);
End.

