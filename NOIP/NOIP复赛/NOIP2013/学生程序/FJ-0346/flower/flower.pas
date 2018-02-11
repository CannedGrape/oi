program flower;
var n:longint;
    a,b:array[1..1000000] of longint;
    s:ansistring;

    i,j,ans:longint;

procedure search(x,y:longint);
var i,j,k:longint;
begin
for i:=1 to x do
    begin
        for j:=1 to x-1 do
        a[j]:=a[j+1];
            for k:=1 to 2 div(x-1) do
            if (b[2*k]<b[2*k-1]) or(b[2*k]<b[2*k]+1)
            then
            exit;
            if x-y>ans then ans:=x-y;
            for k:=1 to 2 div(x-1) do
            if (b[2*k]>b[2*k-1]) or(b[2*k]>b[2*k]+1)
            then exit;
            if x-y>ans then ans:=x-y;
    end;
for i:=1 to n do b[i]:=a[i];

if x>y+1 then search(x,y+1);
end;
procedure init;
var o,i:longint;
begin


    read(n);
    for i:=1 to n do
    begin
    read(a[i]);
    b[i]:=a[i];
    end;

end;

begin
init;
if n<=2 then begin write('1'); halt;end;
search(n,1);

write(ans);

end.
