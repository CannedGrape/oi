program exam;
var

  n,m,k,x,tt,move:longint;

  xx,i:longint;










begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);

  readln(n,m,k,x);

  begin
  xx:=trunc(exp(k*ln(10)));


  tt:=x;
  move:=m mod n;

  for  i:=  1 to xx  do

    begin


      tt:=tt+move;
      tt:=tt mod n;
    end;

  writeln(tt);

  close(input);
     close(output);

                end;

  end.






