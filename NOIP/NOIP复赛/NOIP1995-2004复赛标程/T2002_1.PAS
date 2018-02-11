program t2002_1(input,output);
const maxn=100;
var n,i:integer;
    a:array[1..maxn] of integer;stack:array[1..maxn,1..2]of longint;
    count,top,i1:integer;
    ave:longint;
begin
    assign(input,'a.in');
    reset(input);
    readln(n);ave:=0;
    for i:=1 to n do begin read(a[i]);ave:=ave+a[i];end;
    close(input);
    ave:=ave div n;

    assign(output,'a.out');
    rewrite(output);

    count:=0;top:=0;
    for i:=1 to n-1 do begin
       a[i+1]:=a[i+1]-(ave-a[i]);
       if a[i]<>ave then begin
           top:=top+1;
           stack[top,1]:=i;
           stack[top,2]:=ave-a[i];
           count:=count+1;
       end;
       if a[i+1]>=0 then begin
           while top>0 do begin
               i1:=stack[top,1];
          {     if stack[top,2]>0 then
                 writeln('From ',i1+1,' to ',i1,' Get ',stack[top,2], 'Cards')
               else
                 writeln('From ',i1,' to ',i1+1,' Get ',-stack[top,2], 'Cards');}
               top:=top-1;
           end;
       end;

    end;
    writeln(count);
    close(output);
end.
