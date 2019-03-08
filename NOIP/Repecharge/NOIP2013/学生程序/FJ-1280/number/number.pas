var number,score,special:array[1..1000000] of longint;
    n,i,j,max,p:longint;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
 readln(n,p);
 for i:=1 to n do read(number[i]);
 special[1]:=number[1];
 for i:=2 to n do begin
  if  special[i-1]>=0 then special[i]:=special[i-1]+number[i]
  else special[i]:=number[i];
  end;

 score[1]:=special[1];

 for i:=2 to n do begin
 max:=-99999999;
  for j:=i-1 downto 1 do begin
   if special[j]+score[j]>max then max:=special[j]+score[j]; end;
 score[i]:=max;
 end;

 max:=-999999999;
 for i:=1 to n do if score[i]>max then max:=score[i];
 writeln(max mod p);
 close(input);close(output);
 end.


