Program flower;
Var n,i,j,ans,temp:longint;
    f1,f2,h:array[0..100001]of longint;


function max(a,b:longint):longint;
begin
    if a>b then exit(a);
    exit(b);
end;


function judge(x,y:longint):longint;//1 means x is taller than y;3 means  they are equal
begin
    if h[x]>h[y] then
    begin
         judge:=1;  exit;
    end;

    if h[x]<h[y] then
    begin
        judge:=2;  exit;
    end;

    judge:=3;
    exit;
end;


Begin
    assign(input,'flower.in');  reset(input);
    assign(output,'flower.out');  rewrite(output);

    readln(n);
    for i:=1 to n do
    begin
        read(h[i]);  f1[i]:=1;  f2[i]:=1;
    end;

    for i:=2 to n do
        for j:=1 to i-1 do
        begin
            temp:=judge(i,j);
            if temp=1 then
            begin
                if f1[j] and 1=1 then
                    f1[i]:=max(f1[j]+1,f1[i]);

                if f2[j] and 1=0 then
                    f2[i]:=max(f2[j]+1,f2[i]);
                continue;
            end;

            if temp=2 then
            begin
                if f1[j] and 1=0 then
                    f1[i]:=max(f1[j]+1,f1[i]);
                if f2[j] and 1=1 then
                    f2[i]:=max(f2[j]+1,f2[i]);
                continue;
            end;
        end;

    ans:=1;
    for i:=1 to n do
    begin
        ans:=max(ans,f2[i]);  ans:=max(ans,f1[i]);
    end;
    writeln(ans);

    close(input);
    close(output);
End.
