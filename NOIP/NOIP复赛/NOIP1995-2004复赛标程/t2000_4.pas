program t2000_4;
const maxn=10;
var sum,i1,j1,n,i,j,k,p:integer;
    a:array[1..maxn,1..maxn]of integer;
    f1,f2:array[1..maxn,1..maxn]of integer;

begin
    assign(input,'4.in');
    reset(input);
    readln(n);
    for i:=1 to n do
      for j:=1 to n do a[i,j]:=0;
    read(i);
    while i<>0 do begin
        readln(j,a[i,j]);
        read(i);
    end;
    close(input);
    for i:=1 to n do
       for j:=i to n do begin
           f1[i,j]:=0;
           for k:=1 to j do
             f1[i,j]:=f1[i,j]+a[1,k];
       end;

    for k:=2 to n do begin
        for i:=1 to n do
           for j:=i to n do begin {Qiu f[i,j]}
               f2[i,j]:=0;
               for i1:=1 to i do
                   for j1:=i1 to j do begin
                       sum:=0;
                       if j1<=i then
                           for p:=i1 to j do sum:=sum+a[k,p]
                       else begin
                           for p:=i1 to i do sum:=sum+a[k,p];
                           for p:=j1 to j do sum:=sum+a[k,p];
                       end;
                       if f2[i,j]<f1[i1,j1]+sum then
                           f2[i,j]:=f1[i1,j1]+sum;
                   end;
           end;
        f1:=f2;
    end;
    assign(output,'4.out');
    rewrite(output);
    writeln(f2[n,n]);
    close(output);
end.