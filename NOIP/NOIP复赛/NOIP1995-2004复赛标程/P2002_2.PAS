program p02_2(input,output);
const maxn=20;
var
    a:array[1..maxn] of integer;
    n,k,i,j,count:integer;
    x:array[1..maxn] of longint;
    sum:longint;

function prime(n:longint):boolean;
var i:integer;flag:boolean;
begin
      if n=2 then prime:=true
      else if n mod 2=0 then prime:=false
       else
         begin
               flag:=true;i:=3;
               while flag and (i<=n div 2) do begin
                    if n mod i=0 then flag:=false;i:=i+2;end;
               prime:=flag;
         end;
end;

begin
    assign(input,'p2.in');
    reset(input);
    readln(n,k);
    for i:=1 to n do read(x[i]);
    close(input);
    count:=0;
    for i:=1 to k do a[i]:=i;
    i:=k;
    while (i>0) do begin
        sum:=0;
        for i:=1 to k do sum:=sum+x[a[i]];
        if prime(sum) then
              count:=count+1;
        i:=k;
        while (i>0) and (a[i]=n-k+i) do i:=i-1;
        if (i>0) then begin
             a[i]:=a[i]+1;
             for j:=i+1 to k do a[j]:=a[j-1]+1;end;
    end;
    assign(output,'p2.out');
    rewrite(output);
    writeln(count);
    close(output);
end.
