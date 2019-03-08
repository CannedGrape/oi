var n,i,ans:longint;
    x:char;
    s:string;
function str(i:longint):string;
begin
if i<10 then exit(chr(i mod 10+ord('1')-1))
else if (10<i)and(i<100) then exit(chr(i div 10+ord('1')-1)+chr(i mod 10+ord('1')-1))
else if (100<i)and(i<1000) then exit(chr(i div 100+ord('1')-1)+chr(i div 10+ord('1')-1)+chr(i mod 10+ord('1')-1))
else if (1000<i)and(i<10000) then exit(chr(i div 1000+ord('1')-1)+chr(i div 100+ord('1')-1)+chr(i div 10+ord('1')-1)+chr(i mod 10+ord('1')-1))
else if (10000<i)and(i<100000) then exit(chr(i div 10000+ord('1')-1)+chr(i div 1000+ord('1')-1)+chr(i div 100+ord('1')-1)+chr(i div 10+ord('1')-1)+chr(i mod 10+ord('1')-1))
else if (100000<i)and(i<1000000) then exit(chr(i div 100000+ord('1')-1)+chr(i div 10000+ord('1')-1)+chr(i div 1000+ord('1')-1)+chr(i div 100+ord('1')-1)+chr(i div 10+ord('1')-1)+chr(i mod 10+ord('1')-1));
if i=1000000 then exit('1000000');
end;

begin
ans:=0;
s:='';
assign(input,'count.in');
assign(output,'count.out');
reset(input);
rewrite(output);
readln(n,x);
for i:=1 to n do s:=s+str(i);
for i:=1 to n do if s[i]=x then inc(ans);
writeln(ans);
close(input);
close(output);
end.
