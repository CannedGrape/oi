program chorus(input,output);{time O(n^2)}			
const maxn=10000;			
var n,i,j,max:integer;			
    t,as,des:array[1..maxn]of integer;			
begin			
    assign(input,'chorus.in');			
    reset(input);			
    readln(n);			
    for i:=1 to n do read(t[i]);			
    close(input);			
    des[n]:=1;			
    for i:=n-1 downto 1 do begin			
        des[i]:=1;			
        for j:=i+1 to n do			
           if (t[i]>t[j]) and (des[i]<1+des[j]) then des[i]:=1+des[j];			
    end;			
    as[1]:=1;			
    for i:=2 to n do begin			
        as[i]:=1;			
        for j:=1 to i-1 do			
           if (t[i]>t[j]) and (as[i]<1+as[j]) then as[i]:=1+as[j];			
    end;			
    max:=0;			
    for i:=1 to n do			
       if max<des[i]+as[i]-1 then max:=des[i]+as[i]-1;			
    assign(output,'chorus.out');			
    rewrite(output);			
    writeln(n-max);			
    close(output);			
end.			
