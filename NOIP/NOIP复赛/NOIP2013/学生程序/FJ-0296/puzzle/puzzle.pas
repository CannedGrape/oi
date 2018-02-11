Program puzzle;
const gox:array[1..4]of -1..1=(0,-1,0,1);
      goy:array[1..4]of -1..1=(-1,0,1,0);

Var map:array[0..31,0..31]of boolean;
    judge:array[0..40000000]of boolean;
    i,j,n,m,q,ex,ey,tx,ty,sx,sy,min,c:longint;
    dl:array[0..2000001,1..5]of longint;


function ju(temp,x,y:longint):boolean;
begin
    if (x<1)or(x>n) then
    begin
        ju:=false;
        exit;
    end;
    if (y<1)or(y>m) then
    begin
        ju:=false;
        exit;
    end;
    if judge[temp]=true then
    begin
        ju:=false;
        exit;
    end;
    if map[x,y]=false then
    begin
        ju:=false;
        exit;
    end;

    ju:=true;
    exit;
end;


procedure bfs;
var head,tail,tempx,tempy,temp,tex,tey,i:longint;
begin
    head:=0;  tail:=1;
    dl[1,1]:=sx;  dl[1,2]:=sy;  dl[1,3]:=ex;  dl[1,4]:=ey;  dl[1,5]:=0;
    temp:=ey+ex*100+sy*10000+sx*1000000;
    judge[temp]:=true;

    repeat
        inc(head);  head:=head mod 2000000;
        for i:=1 to 4 do
        begin
            tempx:=dl[head,3]+gox[i];  tempy:=dl[head,4]+goy[i];
            if (tempx=dl[head,1])and(tempy=dl[head,2])then
            begin
                tex:=dl[head,3];  tey:=dl[head,4];
            end else
            begin
                tex:=dl[head,1];  tey:=dl[head,2];
            end;

            temp:=tempy+tempx*100+tey*10000+tex*1000000;

            if ju(temp,tempx,tempy) then
            begin
                inc(tail);  tail:=tail mod 2000000;
                judge[temp]:=true;
                dl[tail,1]:=tex;  dl[tail,2]:=tey;  dl[tail,3]:=tempx;  dl[tail,4]:=tempy;
                dl[tail,5]:=dl[head,5]+1;
                if (tex=tx)and(tey=ty)then
                begin
                    min:=dl[tail,5];  exit;
                end;
            end;
        end;
    until head=tail;
end;


Begin
    assign(input,'puzzle.in');  reset(input);
    assign(output,'puzzle.out');  rewrite(output);

    readln(n,m,q);
    for i:=1 to n do
    begin
        for j:=1 to m do
        begin
            read(c);
            if c=1 then map[i,j]:=true else map[i,j]:=false;
        end;
        readln;
    end;

    for i:=1 to q do
    begin
        readln(ex,ey,sx,sy,tx,ty);
        fillchar(judge,sizeof(judge),false);
        min:=maxlongint;
        bfs;
        if min=maxlongint then writeln('-1') else
            writeln(min);
    end;

    close(input);
    close(output);
End.
