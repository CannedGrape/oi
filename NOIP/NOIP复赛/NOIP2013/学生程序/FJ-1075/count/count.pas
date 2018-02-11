program count;
  var n,x,i,j,sum,max,s:longint;
      a:array [1..10] of byte;
      input,output:text;
begin
 assign(input,'count.in');
 reset(input);
 assign(output,'count.out');
 rewrite(output);
 readln(input,n,x);
 for i:= 1 to n do
 s:=i;
 max:=1000000;
 for j:=1 to 7 do
 if (s div max)=x then
 begin
 sum:=sum+2;
 s:=s mod max;
 max:=max div 10;
 end else max:=max div 10;
 writeln(output,sum);
 close(input);
 close(output);
 end.
