program count;
var
  x,sum,y,k,p:ansistring;
  n,i,j,ans,h,s,f:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  rewrite(output);
  readln(n,x);
  sum:=''; y:='';
  ans:=0;
  delete(x,1,1);
  for i:=1 to n do
    begin
      s:=i;
      if s>= 10 then
      while s>1 do begin
      inc(f);
        h:=s div 10;
        s:=s mod 10;
        y:=chr(h+ord('0'));
        if y=x then inc(ans);
      end
      else begin
      y:=chr(i+ord('0'));
      if x=y then inc(ans);
      end;
      sum:='';
    end;
  writeln(ans);
  close(input);
  close(output);
end.
