uses math;
var i,j,tot,s,t,n,m:longint;
    h:array[1..100000] of longint;
    l:array[1..100000] of longint;

begin
    assign(input,'block.in'); reset(input);
    assign(output,'block.out'); rewrite(output);
    readln(n);
    for i:=1 to n do
      read(h[i]);
    tot:=n-minintvalue(h)+n-maxintvalue(h)-1;
    write(tot);
    close(input); close(output);
    end.


