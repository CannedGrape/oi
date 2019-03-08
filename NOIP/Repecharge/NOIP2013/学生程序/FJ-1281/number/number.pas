var n,m,max,sum:int64;
    i:longint;
    data,b:array[0..1000000] of int64;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
readln(n,m);
for i:=1 to n do read(data[i]);
b[1]:=data[1];
for i:=2 to n do if data[i]>0 then b[i]:=b[i-1]+data[i]
                 else b[i]:=b[i-1];
max:=b[1];
for i:=2 to n do if b[i-1]>0 then max:=b[i-1]+max;
if max>0 then writeln(max mod m)
else begin
                write('-');
                write(abs(max) mod m);
     end;
close(input);close(output);
end.
